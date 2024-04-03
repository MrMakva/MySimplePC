#include "mySimpleComputer.h"
int
sc_accumulatorSet (int value)
{
  if (value >= 1000)
    return -1;
  accumulator = value;
  return 0;
}
