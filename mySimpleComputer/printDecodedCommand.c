#include "../include/mySimpleComputer.h"
void
printDecodedCommand (int value)
{
  int sign, command, operand;
  sc_commandDecode (value, &sign, &command, &operand);
  printf ("Decimal: %d\n", value);
  printf ("Octal: %o\n", value);
  printf ("Hexadecimal: %X\n", value);
  printf ("Binary: ");
  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
  printf ("\n");
}
