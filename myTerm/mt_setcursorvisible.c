#include "myTerm.h"
int
mt_setcursorvisible (int value)
{
  //невидимый
  if (value == 0)
    {
      const char *str = "\E[?25l";
      write (1, str, strlen (str));
      return 0;
    }
  //видимый
  else if (value == 1)
    {
      const char *str = "\E[?12;25h";
      write (1, str, strlen (str));
    }
  else
    {
      return -1;
    }
  return -1;
}