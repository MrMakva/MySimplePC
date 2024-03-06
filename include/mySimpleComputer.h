#include <stdio.h>
#include <stdlib.h>

#define ZERO_MASK 0b00000001
#define OVERFLOW_MASK 0b00000010
#define DIVISION_BY_ZERO_MASK 0b00000100
#define MEMORY_SIZE 128

extern int memory[128];
extern int accumulator;
extern int instructionCounter;
extern int flags;

void sc_memoryInit ();

int sc_memorySet (int address, int value);

int sc_memoryGet (int address, int *value);

int sc_memorySave (char *filename);

int sc_memoryLoad (char *filename);

void sc_regInit ();

int sc_regSet (int regFlag, int value);

int sc_regGet (int regFlag, int *value);

void sc_accumulatorInit ();

int sc_accumulatorSet (int value);

int sc_accumulatorGet (int *value);

void sc_icounterInit ();

int sc_icounterGet (int *value);

int sc_icounterSet (int value);

int sc_commandValidate (int command);

int sc_commandEncode (int sign, int command, int operand, int *value);

int sc_commandDecode (int value, int *sign, int *command, int *operand);

void printCell (int address);

void printFlags ();

void printDecodedCommand (int value);

void printAccumulator ();

void printCounters ();
