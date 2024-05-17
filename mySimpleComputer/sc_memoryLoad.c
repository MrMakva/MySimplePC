#include "mySimpleComputer.h"
int
sc_memoryLoad (char *filename)
{

  FILE *file;
  file = fopen (filename, "rb");
  //создание резервного массива на случай, если память будет считана
  //неправильно
  int mas_of_ram_resrv[MEMORY_SIZE];
  if (!file
      || fread (mas_of_ram_resrv, sizeof (int), MEMORY_SIZE, file)
             != MEMORY_SIZE)
    {
      return -1;
    }
  // fread (mas_of_ram_resrv, sizeof (int), MEMORY_SIZE, file);
  //воспроизводится запись из резервного массива в текущий
  for (int i = 0; i < MEMORY_SIZE - 1; i++)
    {
      memory[i] = mas_of_ram_resrv[i];
    }

  fclose (file);
  return 0;
}
