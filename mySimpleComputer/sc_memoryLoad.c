#include "../include/mySimpleComputer.h"
int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rb");

  if (file == NULL)
    {
      return -1;
    }

  fread (memory, sizeof (int), MEMORY_SIZE, file);
  fclose (file);

  return 0;
}
