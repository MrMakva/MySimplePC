#include "../include/mySimpleComputer.h"
void
printFlags ()
{
  printf ("Flags: %c%c%c\n", (flags & ZERO_MASK) ? 'Z' : '_',
          (flags & OVERFLOW_MASK) ? 'O' : '_',
          (flags & DIVISION_BY_ZERO_MASK) ? 'D' : '_');
}
