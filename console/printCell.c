#include "Lprint.h"
void
printCell (int address, enum colors fg, enum colors bg)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;
  char str[BUFF];

  //Цвет вывода
  //////////////////////
  mt_setfgcolor (fg);
  mt_setbgcolor (bg);
  //Вычисление позици ячейки
  ///////////////////////
  int y_pos = address % 10 * 9 + 2;
  int x_pos = address / 10 + 2;
  mt_gotoXY (x_pos, y_pos);
  //////////////////////

  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  //вывод
  int len
      = sprintf (str, "%c%.2x%.2x\n", (sign) ? '-' : '+', command, operand);
  write (1, str, len);
  //стандартные цвета
  mt_setdefaultcolor ();
}