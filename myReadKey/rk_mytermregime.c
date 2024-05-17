#include "myReadKey.h"

int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  struct termios curr;
  tcgetattr (fileno (stdin), &curr);
  //канонический режим
  if (regime)
    {
      curr.c_lflag |= ICANON;
    }
  //неканонический режим
  else if (!regime)
    {
      curr.c_lflag &= ~ICANON;
      sigint ? (curr.c_lflag |= ISIG) : (curr.c_lflag &= ~ISIG);
      echo ? (curr.c_lflag |= ECHO) : (curr.c_lflag &= ~ECHO);
      curr.c_cc[VMIN] = vmin;
      curr.c_cc[VTIME] = vtime;
    }
  if (tcsetattr (fileno (stdin), TCSAFLUSH, &curr) != 0)
    {
      return -1;
    }
  return 0;
}