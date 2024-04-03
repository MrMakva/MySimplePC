#include "myTerm.h"
int
mt_setbgcolor (enum colors color)
{
  char buf[16];
  int len = sprintf (buf, "\E[48;5;%dm", color);
  write (1, buf, len);
  return 0;
}