#include "Lprint.h"
static int last_value[6];
void
printTerm (int address, int input)
{
  char str[BUFF];

  for (int i = 0; i < BUFF; i++)
    {
      str[BUFF] = '\000';
    }

  int value;
  int sign;
  int command;
  int operand;
  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  int len;
  if (input == 0)
    {
      len = sprintf (str, "%s%s%d>    ", (address < 10) ? "0" : "",
                     (address < 100) ? "0" : "", address);
    }
  else if (input == 1)
    {

      len = sprintf (str, "%d>%c%s%s%d:%s%s%d\n", address, (sign) ? '-' : '+',
                     (command < 10) ? "0" : "", (command < 100) ? "0" : "",
                     command, (operand < 100) ? "0" : "",
                     (operand < 10) ? "0" : "", operand);
    }

  last_value[5] = last_value[4];
  last_value[4] = last_value[3];
  last_value[3] = last_value[2];
  last_value[2] = last_value[1];
  last_value[1] = last_value[0];
  last_value[0] = address;

  mt_gotoXY (22, 110);
  write (1, str, len);

  for (int i = 1; i < 6; i++)
    {
      mt_gotoXY (22 + i, 110);
      sc_memoryGet (last_value[i], &value);
      sc_commandDecode (value, &sign, &command, &operand);
      len = sprintf (
          str, "%d>%c%s%s%d:%s%s%d\n", last_value[i], (sign) ? '-' : '+',
          (command < 10) ? "0" : "", (command < 100) ? "0" : "", command,
          (operand < 100) ? "0" : "", (operand < 10) ? "0" : "", operand);
      write (1, str, len);
    }
}