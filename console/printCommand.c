#include "Lprint.h"
void
printCommand (void)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;

  char str[BUFF];

  sc_icounterGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  int len = sprintf (str, "+%d", command);

  mt_gotoXY (4, 135);

  write (1, str, len);
}
