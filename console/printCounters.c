#include "Lprint.h"
void
printCounters ()
{
  int value = 0;
  char str[BUFF];

  sc_icounterGet (&value);

  mt_gotoXY (5, 98);
  int len = sprintf (str, "IC: +%.4x", value);
  write (1, str, len);
}
