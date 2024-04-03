#include "Lprint.h"
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <time.h>
#include <unistd.h>

int
main ()
{
  int rows = 50, cols = 60;
  mt_getscreensize (&rows, &cols);
  sc_memoryInit ();
  mt_clrscr ();

  if (rows < 25 || cols < 25)
    {
      mt_gotoXY (1, 1);
      mt_setfgcolor (RED);
      mt_setbgcolor (WHITE);
      printf ("Screen is too small!\n");
      return 0;
    }

  for (int j = 0; j < 128; j++)
    {
      if (j >= 9 && j % 9 == 0)
        {
          write (1, "\n", 2);
        }

      int value;
      sc_commandEncode (1, rand () % 99, rand () % 99, &value);
      sc_memorySet (j, value);
      printCell (j, WHITE, BLACK);
      sc_accumulatorInit ();
      sc_icounterInit ();
      sc_regInit ();
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
    }

  int last_num = 1;
  srand (time (NULL));

  for (int i = 0;;)
    {

      i = rand () % 127;
      printCell (i, RED, WHITE);
      printCell (last_num, BLUE, RED);
      last_num = i;
      int value;
      sc_memoryGet (i, &value);
      sc_icounterSet (value);
      printDecodedCommand (value);
      printTerm (i, 1);
      printCommand ();
      mt_setcursorvisible (1);
      sleep (2);
    }
  return 0;
}