#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>



/*** defines ***/

#define KILO_VERSION "0.0.1"

#define CTRL_KEY(k) ((k) & 0x1f)

enum editorKey {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};

/*** data ***/
struct editorConfig
{
    int cx, cy;
    int screenrows;
    int screencols;
    struct termios orig_termios;    // original terminal attributes stores in a global variable.
};

struct editorConfig E;

/*** terminal ***/

void die(const char *s)
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    perror(s);
    exit(1);
}

void disableRawMode()
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1)
    die("tcsetattr");
}

void enableRawMode()
{
    if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcsetaatr");
    atexit(disableRawMode);     // calls disableRawMode automatically when programs exits.

    struct termios raw = E.orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_iflag &= ~(ICRNL | IXON);     // disables flow control.
    raw.c_oflag &= ~(OPOST); //turns off post proccessing 
    raw.c_cflag &= ~(CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); // '|' is a bitwise OR. Don't confuse with logical OR (||).
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

int editorReadKey() //waits for keypress and returns it.
{
    int nread;
    char c;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
    {
        if (nread == -1 && errno != EAGAIN) die("read");
    }

    if (c == '\x1b') {
      char seq[3];

      if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
      if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';

      if (seq[0] == '[') {
	switch (seq[1]) {
	  case 'A': return 'ARROW_UP';
	  case 'B': return 'ARROW_DOWN';
	  case 'C': return 'ARROW_RIGHT';
	  case 'D': return 'ARROW_LEFT';
	}
      }

      return '\x1b';
    } else {
      return c;
    }	
}

int getCursorPosition(int *rows, int *cols) {

    char buf[32];   // buffer to store terminal's response
    unsigned int i = 0; // index to keep track of buffer position

    /* 
    sends ANSI escape code "\x1b[6n" to the terminal 
    this command requests the terminal to report the current cursor position
    example reponse: "\x1b[24;80R" (cursor at row 24, column 80.)
    */
    if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

    while (i < sizeof(buf) -1) {
        if (read(STDIN_FILENO, &buf[i], 1) != 1) break;
        if (buf[i] == 'R') break;
        i++;
    }

    buf[i] = '\0';

    if (buf[0] != '\x1b' || buf[1] != '[') return -1;
    if (sscanf(&buf[2], "%d;%d", rows, cols) != 2) return -1;

    return 0;
}

int getWindowSize(int *rows, int *cols)
{
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1;
        return getCursorPosition(rows, cols);
    } else {
        *cols = ws.ws_col;
        *rows = ws.ws_row;
        return 0;
    }
    
}

/*** append buffer ***/

struct abuf {
    char *b;    // pointer to the buffer storing characters.
    int len;    // current length of the buffer (number of characters)
};

#define ABUF_INIT {NULL, 0}

void abAppend(struct abuf *ab, const char *s, int len)  {
    char *new = realloc(ab->b, ab->len + len); // resize the buffer to accommodate new data

    if (new == NULL) return;    // handles memory allocation failure 

    memcpy(&new[ab->len], s, len);  // copy the new data to the end of the resized buffer
    ab->b = new;    // update the buffer pointer
    ab->len += len; // update the buffer length
}

void abFree(struct abuf *ab) {

    free(ab->b);
}

/*** output ***/

void editorDrawRows(struct abuf *ab) {
    int y;
    for (y = 0; y < E.screenrows; y++) {
	if (y == E.screenrows / 3) {
	   char welcome[80];
	   int welcomelen = snprintf(welcome, sizeof(welcome),
		"Kilo editor -- version %s", KILO_VERSION);
	if (welcomelen > E.screencols) welcomelen = E.screencols;
	int padding = (E.screencols - welcomelen) / 2;   // to center string, divide screen width by 2
	if (padding) {
	   abAppend(ab, "~", 1);
	   padding--;   
	}
	while (padding--) abAppend(ab, " ", 1);
	abAppend(ab, welcome, welcomelen);
	} else {
	  abAppend(ab, "~", 1);
	}
  
	abAppend(ab, "x1b[K", 3);
        if (y < E.screenrows - 1) {
            abAppend(ab, "\r\n", 2);
        }
    }
}

void editorRefreshScreen() {
    struct abuf ab = ABUF_INIT;

    abAppend(&ab, "\x1b[?25l", 6);
    abAppend(&ab, "\x1b[H", 3);

    editorDrawRows(&ab);

    char buf[32];
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
    abAppend(&ab, buf, strlen(buf));

    abAppend(&ab, "\x1b[?25h", 6);

    write(STDOUT_FILENO, ab.b, ab.len);
    abFree(&ab);
}

/*** input ***/

void editorMoveCursor(int key) {
    switch (key) {
      case 'ARROW_LEFT':
	if (E.cx != 0) {
      	  E.cx--;
	}
	break;
      case 'ARROW_RIGHT':
	if (E.cx != E.screencols - 1) {
	  E.cx++;
	}
	break;
      case 'ARROW_UP':
	if (E.cy != 0) {
	  E.cy--;
	}
	break;
      case 'ARROW_DOWN':
	if (E.cy != E.screenrows - 1) {
	  E.cy++;
	}
	break;   
    }
}

void editorProcessKeypress()
{
    int c = editorReadKey();

    switch (c) {
        case CTRL_KEY('q'):
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
        break;

	case 'ARROW_UP':
	case 'ARROW_DOWN':
	case 'ARROW_LEFT':
	case 'ARROW_RIGHT':
	  editorMoveCursor(c);
	  break;
    }
}

/*** init ***/

void initEditor() {
    E.cx = 0;
    E.cy = 0;

    if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
}

int main ()
{
    enableRawMode();
    initEditor();

    while (1)
    {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}