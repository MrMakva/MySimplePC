#include "myTerm.h"
int
mt_setfgcolor (enum colors color)
{
  char buf[16];
  int len = sprintf (buf, "\E[38;5;%dm", color);
  write (1, buf, len);
  return 0;
}