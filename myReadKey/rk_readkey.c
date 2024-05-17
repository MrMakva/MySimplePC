#include "myReadKey.h"

int
rk_readkey (enum keys *key)
{

  char buf_local[MIN_BUF_SIZE - 1];
  //очистка буфера
  for (int i = 0; i < MIN_BUF_SIZE; i++)
    {
      buf_local[i] = 0;
    }
  //переключаем терминал в неканонический режим
  rk_mytermregime (0, 0, 1, 0, 1);

  //считываем первый введённый символ
  fflush (stdin); //очистка потока ввода
  read (fileno (stdin), buf_local, MIN_BUF_SIZE);

  if (!key)
    {
      return -1;
    }
  //проверка введённого символа
  if (buf_local[0] == '\033')
    { // Esc-последовательности
      switch (buf_local[1])
        {
        case '\0':
          *key = ESC_KEY;
          break;
        case '[':
          switch (buf_local[2])
            {
            case 'A':
              *key = UP_KEY;
              break;
            case 'B':
              *key = DOWN_KEY;
              break;
            case 'C':
              *key = RIGHT_KEY;
              break;
            case 'D':
              *key = LEFT_KEY;
              break;
            case '1':
              if (buf_local[3] == '5' && buf_local[4] == '~')
                *key = F5_KEY;
              if (buf_local[3] == '7' && buf_local[4] == '~')
                *key = F6_KEY;
              break;
            default:
              *key = INVALID_KEY;
              break;
            }
          break;
        default:
          *key = INVALID_KEY;
          break;
        }
    }
  else if (buf_local[0] == '\n' && buf_local[1] == '\0')
    { // клавиша Enter
      *key = ENTER_KEY;
    }
  else
    { // прочие клавиши
      switch (buf_local[0])
        {
        case 'l':
        case 'L':
          *key = L_KEY;
          break;
        case 's':
        case 'S':
          *key = S_KEY;
          break;
        case 'r':
        case 'R':
          *key = R_KEY;
          break;
        case 't':
        case 'T':
          *key = T_KEY;
          break;
        case 'i':
        case 'I':
          *key = I_KEY;
          break;
        case 'a':
        case 'A':
          *key = A_KEY;
          break;
        case 'b':
        case 'B':
          *key = B_KEY;
          break;
        case 'c':
        case 'C':
          *key = C_KEY;
          break;
        case 'd':
        case 'D':
          *key = D_KEY;
          break;
        case 'e':
        case 'E':
          *key = E_KEY;
          break;
        case 'f':
        case 'F':
          *key = F_KEY;
          break;

        case '0':
          *key = ZERO_KEY;
          break;

        case '1':
          *key = ONE_KEY;
          break;
        case '2':
          *key = TWO_KEY;
          break;
        case '3':
          *key = THREE_KEY;
          break;
        case '4':
          *key = FOUR_KEY;
          break;
        case '5':
          *key = FIVE_KEY;
          break;
        case '6':
          *key = SIX_KEY;
          break;
        case '7':
          *key = SEVEN_KEY;
          break;
        case '8':
          *key = EIGHT_KEY;
          break;
        case '9':
          *key = NINE_KEY;
          break;

        case '+':
          *key = PLUS_KEY;
          break;
        case '-':
          *key = MINUS_KEY;
          break;

        case 0:
          *key = NOTHING_KEY;
          break;
        default:
          *key = INVALID_KEY;
          break;
        }
    }

  return 0;
}