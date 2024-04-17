#include "Lprint.h"
void
printAccumulator ()
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;
  char str[50] = "sc: ";

  sc_accumulatorGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  str[4] = sign == 0 ? '+' : '-';

  mt_gotoXY (2, 93);
  int len = sprintf (str, "sc: %.2x%.2x hex: %.4x", command, operand, value);
  write (1, str, len);
}
