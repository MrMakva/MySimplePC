#include "myReadKey.h"

int
rk_mytermsave ()
{
  if (tcgetattr (fileno (stdin), &save))
    {
      return -1;
    }
  return 0;
}