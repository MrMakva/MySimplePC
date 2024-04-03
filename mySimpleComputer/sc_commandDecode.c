#include "mySimpleComputer.h"
int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  *sign = (value >> 14) & 1;
  *command = (value >> 7) & 0x7F;
  *operand = value & 0x7F;

  if (sc_commandValidate (*command) != 0 || *sign < 0 || *sign > 1
      || *operand < 0 || *operand >= MEMORY_SIZE)
    {
      return -1;
    }

  return 0;
}
