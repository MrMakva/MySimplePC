#include "myTerm.h"
int
mt_getscreensize (int *rows, int *cols)
{
  if (rows == NULL || cols == NULL)
    {
      return -1;
    }

  if (!isatty (1))
    {
      return -1;
    }

  struct winsize window_size;
  //Получает размер окна
  if (ioctl (1, TIOCGWINSZ, &window_size))
    {
      return -1;
    }
  *rows = window_size.ws_row;
  *cols = window_size.ws_col;

  return 0;
}