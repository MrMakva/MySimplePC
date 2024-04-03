#include "myTerm.h"
int
mt_delline ()
{
  const char *str = "[\EM";
  write (1, str, strlen (str));
  return 0;
}