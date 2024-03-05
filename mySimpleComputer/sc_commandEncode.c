#include "../include/mySimpleComputer.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (sign != 0 && sign != 1 || sc_commandValidate (command) != 0
      || operand < 0 || operand >= MEMORY_SIZE || value == NULL)
    {
      return -1;
    }

  *value = (sign << 14) | (command << 7) | operand;
  return 0;
}
