#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/unix_terminal_control.h"

void moveTerminalCursorUp(int lines) {
    printf("\033[%iA", lines);
}
void moveTerminalCursorDown(int lines) {
    printf("\033[%iB", lines);
}
void moveTerminalCursorRight(int lines) {
    printf("\033[%iC", lines);
}
void moveTerminalCursorLeft(int lines) {
    printf("\033[%iD", lines);
}
void moveTerminalCursorToCords(int row, int column) {
	printf("\033[%i;%iH", row, column);
	printf("\033[%i;%if", row, column);
}
void moveTerminalCursorHome() {
	printf("\033[H");
}
void moveTerminalCursorDownBeginning(int lines) {
	printf("\033[%iE", lines);
}
void moveTerminalCursorUpBeginning(int lines) {
	printf("\033[%iF", lines);
}

// Input
bool kbhit() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Turn off CANON mode and ECHO mode
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int old_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, old_flags | O_NONBLOCK); // Set nonblock mode

    int ch = getchar(); // Try to get a char
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    fcntl(STDIN_FILENO, F_SETFL, old_flags); // Restore old flags

    if(ch != EOF) {
        ungetc(ch, stdin); // Return a character back to the stream
        return true; // The key has been pressed
    }
    return false; // The key has not been pressed
}

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
