#include "mySimpleComputer.h"
int
sc_memorySave (char *filename)
{

  FILE *file;
  file = fopen (filename, "wb");
  if (!file || fwrite (memory, sizeof (int), MEMORY_SIZE, file) != MEMORY_SIZE)
    {
      return -1;
    }

  fclose (file);

  return 0;
}
