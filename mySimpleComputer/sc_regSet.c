#include "mySimpleComputer.h"
int
sc_regSet (int regFlag, int value)
{
  if (regFlag != ZERO_MASK && regFlag != OVERFLOW_MASK
      && regFlag != DIVISION_BY_ZERO_MASK)
    {
      return -1;
    }

  if (value)
    {
      flags |= regFlag;
    }
  else
    {
      flags &= ~regFlag;
    }

  return 0;
}
