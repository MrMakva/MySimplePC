#include "mySimpleComputer.h"
int
sc_commandValidate (int command)
{
  if (command < 0 || command > 99)
    {
      return -1;
    }
  else
    {
      return 0;
    }
}
