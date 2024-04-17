#include "myBigChars.h"

int
bc_printbigchar (int bigchar[], int x, int y, enum colors frontcolor,
                 enum colors backcolor)
{

  if (mt_setfgcolor (frontcolor) == -1 || mt_setbgcolor (backcolor) == -1
      || mt_gotoXY (x, y) == -1)
    {
      return -1;
    }

  for (int i = 0; i < 4; i++)
    {
      int value = (bigchar[0] >> (i * 8)) & 0xff;
      for (int j = 0; j < 8; j++)
        {
          mt_gotoXY (x + i, y + j);
          int ch = (value >> (7 - j))
                   & 0x01; // Обращение к битам в обычном порядке
          if (ch == 1)
            {
              bc_printA (CKBOARD); // Функция для вывода символа CKBOARD
            }
          else
            {
              write (1, " ", 1);
            }
        }
    }

  for (int i = 0; i < 4; i++)
    {
      int value = (bigchar[1] >> (i * 8)) & 0xff;
      for (int j = 0; j < 8; j++)
        {
          mt_gotoXY (x + 4 + i, y + j);
          int ch = (value >> (7 - j))
                   & 0x01; // Обращение к битам в обычном порядке
          if (ch == 1)
            {
              bc_printA (CKBOARD); // Функция для вывода символа CKBOARD
            }
          else
            {
              write (1, " ", 1);
            }
        }
    }

  return 0;
}