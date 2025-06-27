#ifndef UNIX_TERMINAL_CONTROL_H
#define UNIX_TERMINAL_CONTROL_H

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void moveTerminalCursorUp(int lines);
void moveTerminalCursorDown(int lines);
void moveTerminalCursorRight(int lines);
void moveTerminalCursorLeft(int lines);
void moveTerminalCursorToCords(int row, int column);
void moveTerminalCursorHome(); // moves T cursor to 0,0

void moveTerminalCursorDownBeginning(int lines); // moves T cursor to the beginning of the line, which is $lines down
void moveTerminalCursorUpBeginning(int lines); // same as moveTerminalCursorDownBeginning(), but moves upwards

void moveTerminalCursorToBeginning(); // moves cursor to the beginning of the current line (basically carriage return)

// Input
bool kbhit();
int getch(void);

#ifdef __cplusplus
}
#endif

#endif
