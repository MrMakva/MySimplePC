#include "myBigChars.h"

int
bc_strlen (char *str)
{
  if (!str)
    {
      return 0;
    }

  int counter = 0;
  for (int i = 0; str[i] != '\n';)
    {
      if (str[i] == 0x80)
        {
          counter++;
          i++;
        }
      else if (str[i] == 0xC0)
        {
          counter++;
          i += 2;
        }
      else if (str[i] == 0xE0)
        {
          counter++;
          i += 3;
        }
      else if (str[i] == 0xF0)
        {
          counter++;
          i += 4;
        }
      else
        {
          return 0;
        }
    }
  return counter;
}
