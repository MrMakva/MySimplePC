#ifndef MYTERM_H
#define MYTERM_H

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define ESC_SEQ "\033"

enum colors {
  DEFAULT,
  WHITE = 15,
  BLACK,
  RED = 196,
  ERROR,
  BLUE = 30,
  YELLOW = 220,
  GREEN = 34,
  PURPLE = 99,
  CYAN = 36,
  NONACTIVE = 0

};

int mt_clrscr ();

int mt_gotoXY (int string, int column);

int mt_getscreensize (int *rows, int *cols);

int mt_setfgcolor (enum colors color);

int mt_setbgcolor (enum colors color);

int mt_setdefaultcolor ();

int mt_setcursorvisible (int value);

int mt_delline ();

#endif