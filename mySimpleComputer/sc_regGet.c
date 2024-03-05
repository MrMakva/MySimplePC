#include "../include/mySimpleComputer.h"
int
sc_regGet (int regFlag, int *value)
{
  if ((regFlag != ZERO_MASK && regFlag != OVERFLOW_MASK
       && regFlag != DIVISION_BY_ZERO_MASK)
      || value == NULL)
    {
      return -1;
    }

  *value = (flags & regFlag) ? 1 : 0;
  return 0;
}
