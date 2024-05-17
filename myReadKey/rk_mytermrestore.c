#include "myReadKey.h"

int
rk_mytermrestore ()
{
  tcsetattr (fileno (stdin), TCSAFLUSH, &save);
  return 0;
}