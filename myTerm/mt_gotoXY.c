#include "myTerm.h"
int
mt_gotoXY (int string, int column)
{
  char buf[16];
  int len = sprintf (buf, "\E[%d;%dH", string, column);
  write (1, buf, len);
  return 0;
}