#include "../include/mySimpleComputer.h"
int
sc_icounterSet (int value)
{
  if (value >= 100)
    return -1;
  instructionCounter = value;
  return 0;
}
