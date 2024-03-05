#include "../include/mySimpleComputer.h"
void
printCell (int address)
{
  int value;
  if (sc_memoryGet (address, &value) != -1)
    {
      int sign, command, operand;
      sc_commandDecode (value, &sign, &command, &operand);
      printf ("Memory cell at address %d: (%d, %d, %d)\n", address, sign,
              command, operand);
    }
  else
    {
      printf ("Invalid memory address\n");
    }
}
