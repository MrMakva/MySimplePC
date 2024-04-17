#ifndef Lprint_h
#define Lprint_h

#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <math.h>
#include <stdio.h>

#define BUFF 20

void printAccumulator ();

void printCell (int address, enum colors fg, enum colors bg);

void printCommand (void);

void printCounters ();

void printDecodedCommand (int value);

void printFlags ();

void printTerm (int address, int input);

void print_interface ();

int output_BigChars ();

#endif