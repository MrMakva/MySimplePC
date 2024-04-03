#include "Lprint.h"
void
printFlags ()
{
  char str[BUFF] = "P 0 M T E";

  for (int i = 0, k = 1; i < 5; ++i, k *= 2)
    {
      int value;
      sc_regGet (k, &value);

      if (value == 0)
        {
          str[2 * i] = '_';
        }
    }

  mt_gotoXY (2, 140);
  write (1, str, BUFF);
}