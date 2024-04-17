#include "myBigChars.h"
int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2)
    {
      return -1;
    }

  mt_gotoXY (x1, y1);
  bc_printA (LUCORNER);

  for (int i = y1 + 1; i < y2; i++)
    {
      mt_gotoXY (x1, i);
      bc_printA (HLINE);
      mt_gotoXY (x2, i);
      bc_printA (HLINE);
    }
  bc_printA (RDCORNER);

  for (int i = x1 + 1; i < x2; i++)
    {
      mt_gotoXY (i, y1);
      bc_printA (VLINE);
      mt_gotoXY (i, y2);
      bc_printA (VLINE);
    }

  mt_gotoXY (x1, y2);
  bc_printA (RUCORNER);

  mt_gotoXY (x2, y1);
  bc_printA (LDCORNER);

  if (header)
    {
      mt_setfgcolor (header_fg);
      mt_setbgcolor (header_bg);
      int count = 0;
      for (int i = 0; header[i] != '\n'; i++)
        {
          count++;
        }
      if (y2 - y1 < 15)
        {
          mt_gotoXY (x1, count / 2 + y1 + 1);
          write (1, header, count);
        }
      else
        {
          int width = (y2 - y1) / 2 - (count / 3);
          if (width < 0)
            {
              width = 0;
            }
          mt_gotoXY (x1, width + y1 + 2);
          write (1, header, count);
        }
    }
  mt_setdefaultcolor ();

  return 0;
}