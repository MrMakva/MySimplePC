#include "myTerm.h"
int
mt_clrscr ()
{
  char output[10];
  sprintf (output, "\E[H\E[2J");
  if (write (1, output, strlen (output)) == strlen (output))
    {
      return 0;
    }
  else
    {
      return -1;
    }
}