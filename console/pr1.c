#include "../include/mySimpleComputer.h"
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  for (int i = 0; i < 10; i++)
    {
      sc_memorySet (i, rand () % 256);
    }

  printf ("Memory content:\n");
  for (int i = 0; i < 21; i++)
    {
      printCell (i);
      if ((i + 1) % 10 == 0)
        {
          printf ("\n");
        }
    }

  int status = sc_memorySet (200, 1000);
  printf ("Status of setting an invalid memory value: %s\n",
          status == -1 ? "Failed" : "Success");

  sc_regSet (ZERO_MASK, 1);
  sc_regSet (OVERFLOW_MASK, 0);
  sc_regSet (DIVISION_BY_ZERO_MASK, 1);

  printf ("Flag content:\n");
  printFlags ();

  int flagStatus = sc_regSet (10, 1);
  printf ("Status of setting an incorrect flag value: %s\n",
          flagStatus == -1 ? "Failed" : "Success");

  sc_accumulatorSet (500);

  printf ("Accumulator value: ");
  printAccumulator ();

  int accStatus = sc_accumulatorSet (1000);
  printf ("Status of setting an invalid accumulator value: %s\n",
          accStatus == -1 ? "Failed" : "Success");

  sc_icounterSet (50);

  printf ("Instruction counter value: ");
  printCounters ();

  int icounterStatus = sc_icounterSet (150);
  printf ("Status of setting an invalid instruction counter value: %s\n",
          icounterStatus == -1 ? "Failed" : "Success");

  int decodedValue;
  sc_memoryGet (5, &decodedValue);
  printDecodedCommand (decodedValue);

  int accValue;
  sc_accumulatorGet (&accValue);
  printf ("Accumulator decoded value: ");
  printDecodedCommand (accValue);

  int encodedValue;
  sc_commandEncode (1, 30, 40, &encodedValue);
  printf ("Encoded command value:\n");
  printDecodedCommand (encodedValue);

  return 0;
}