#include "myTerm.h"
int
mt_setdefaultcolor ()
{
  const char *str = "\E[0m";
  write (1, str, strlen (str));
  return 0;
}