#include "Lprint.h"
#include <fcntl.h>

int
output_BigChars ()
{
  int cursor = 0;
  int value, command, operand, sing = 0;
  if (sc_memoryGet (cursor, &value) < 0
      || sc_commandDecode (value, &sing, &command, &operand) < 0)
    {
      return -1;
    }

  int fd = open ("font.bin", O_RDONLY);
  if (fd == -1)
    {
      perror ("Ошибка открытия файла");
      return -1;
    }
  int *bc_NUMS[16][2];
  for (int i = 0; i < 16; i++)
    {
      read (fd, &bc_NUMS[i], sizeof (int) * 2); // Чтение символа из файла
    }
  close (fd);
  int bc_PLUS[2] = { 0xFF181818, 0x181818FF };
  int bc_MINUS[2] = { 0xFF000000, 0x000000FF };

  (sing == 1) ? bc_printbigchar (bc_MINUS, 9, 93, WHITE, BLACK)
              : bc_printbigchar (bc_PLUS, 9, 93, WHITE, BLACK);
  bc_printbigchar (bc_NUMS[(command >> 4) % 16], 9, 102, WHITE, BLACK);
  bc_printbigchar (bc_NUMS[(command & 0xf) % 16], 9, 111, WHITE, BLACK);
  bc_printbigchar (bc_NUMS[(operand >> 4) & 0xf % 16], 9, 120, WHITE, BLACK);
  bc_printbigchar (bc_NUMS[(operand & 0xf) % 16], 9, 129, WHITE, BLACK);

  return 0;
}