#include "myReadKey.h"

int
rk_readvalue (int *value, int timeout)
{
  // очистка буфера ввода
  for (int i = 0; i < MIN_BUF_SIZE; i++)
    {
      buffer[i] = 0;
    }

  int address;
  sc_icounterGet (&address);

  if (*value == 1)
    {
      printCell (address, BLUE, BLUE);
      mt_gotoXY (address / 10 + 2, address % 10 * 9 + 2);
    }
  if (*value == 2)
    {
      mt_gotoXY (2, 96);
      mt_setfgcolor (BLUE);
      mt_setbgcolor (BLUE);
      write (1, "     ", 6);
      mt_gotoXY (2, 96);
    }
  if (*value == 3)
    {
      mt_gotoXY (5, 102);
      mt_setfgcolor (BLUE);
      mt_setbgcolor (BLUE);
      write (1, "     ", 6);
      mt_gotoXY (5, 102);
    }

  mt_setbgcolor (BLUE);
  mt_setfgcolor (BLACK);
  enum keys key;
  //параметр, необходимый для того, чтобы дать команду записи значения
  int to_do = 0;
  //если, то символы не будут выводиться
  int red_flag;
  for (int i = 0; i < 6; i++)
    {
      red_flag = 0;
      rk_readkey (&key);

      if (i == 5 && key != ENTER_KEY && key != ESC_KEY)
        {
          key = INVALID_KEY;
        }
      switch (key)
        {
        case ESC_KEY:
          mt_setdefaultcolor ();

          return -1;
          break;
        case PLUS_KEY:
        case MINUS_KEY:
          if (i == 0)
            {
              buffer[i] = key;
            }
          else
            {
              i--;
              red_flag += 1;
            }
          break;
        case ZERO_KEY:
        case ONE_KEY:
        case TWO_KEY:
        case THREE_KEY:
        case FOUR_KEY:
        case FIVE_KEY:
        case SIX_KEY:
        case SEVEN_KEY:
        case EIGHT_KEY:
        case NINE_KEY:
        case A_KEY:
        case B_KEY:
        case C_KEY:
        case D_KEY:
        case E_KEY:
        case F_KEY:
          if (i >= 1 && i <= 4)
            {
              buffer[i] = key;
            }
          else
            {
              i--;
              red_flag += 1;
            }
          break;

        case ENTER_KEY:
          to_do = 1;
          break;
        //в случае неверного ключа
        default:
          i--;
          red_flag += 1;

          break;
        }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////
      if (*value == 1 && (buffer[i] != ENTER_KEY && buffer[i] != ESC_KEY)
          && i < 5 && red_flag == 0)
        {
          char buf[2];

          if (i == 0)
            {
              if (buffer[i] == 45)
                {

                  sprintf (buf, "+");
                }
              else
                {
                  sprintf (buf, "-");
                }
            }

          else if (buffer[i] >= 0 && buffer[i] <= 9)
            {

              sprintf (buf, "%d", buffer[i]);
            }
          else if (buffer[i] >= 10 && buffer[i] <= 15)
            {
              int razn = 'a' - 10;
              sprintf (buf, "%c", buffer[i] + razn);
            }

          write (fileno (stdout), buf, 1);
        }
      /////////////////////////////////////////////////////////////////////////////////////////////////////////
      if (*value == 2 && (buffer[i] != ENTER_KEY && buffer[i] != ESC_KEY)
          && i < 5 && red_flag == 0)
        {

          char buf[2];

          if (i == 0)
            {
              if (buffer[i] == 45)
                {

                  sprintf (buf, "+");
                }
              else
                {
                  sprintf (buf, "-");
                }
            }

          else if (buffer[i] >= 0 && buffer[i] <= 9)
            {

              sprintf (buf, "%d", buffer[i]);
            }
          else if (buffer[i] >= 10 && buffer[i] <= 15)
            {
              int razn = 'a' - 10;
              sprintf (buf, "%c", buffer[i] + razn);
            }

          write (fileno (stdout), buf, 1);
        }
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      if (*value == 3 && (buffer[i] != ENTER_KEY && buffer[i] != ESC_KEY)
          && i < 5 && red_flag == 0)
        {

          char buf[2];

          if (i == 0)
            {
              if (buffer[i] == 45)
                {

                  sprintf (buf, "+");
                }
              else
                {
                  sprintf (buf, "-");
                }
            }

          else if (buffer[i] >= 0 && buffer[i] <= 9)
            {

              sprintf (buf, "%d", buffer[i]);
            }
          else if (buffer[i] >= 10 && buffer[i] <= 15)
            {
              int razn = 'a' - 10;
              sprintf (buf, "%c", buffer[i] + razn);
            }

          write (fileno (stdout), buf, 1);
        }
    }

  if (to_do == 1)
    {

      int address;
      sc_icounterGet (&address);
      //результат перевода
      int result;
      //переменные для сохранения числа
      int sign = 0;
      int command = 0;
      int operand = 0;
      for (int k = 0; k < 2; k++)
        {
          result = 0;
          //если, то это команда
          int barrier = 0;
          int thisstart = 0;
          if (k == 0)
            {
              thisstart = 1;
              barrier = 3;
            }
          //иначе операнд
          else
            {
              thisstart = 3;
              barrier = 5;
            }
          for (int i = thisstart; i < barrier; i++)
            {

              //так как мы точно знаем, что число будет четырёхразрядное,
              //мы также знаем, что во время перевода максимальная степень -
              //куб
              //          возведение в степень

              int help = (i - thisstart) + 1;
              switch (help)
                {
                case 1:
                  result = result + buffer[i] * 16;
                  break;
                case 2:
                  result = result + buffer[i];
                  break;
                default:
                  return -1;
                  break;
                }
              //в зависимости от внешнего цикла записываем в команду или
              //операнд
              if (k == 0)
                {
                  command = result;
                }
              else
                {
                  operand = result;
                }
            }
        }
      if ((command > 127 || operand > 127) && *value == 1)
        {
          int enter_value;
          sc_memoryGet (address, &enter_value);
          *value = enter_value;
          mt_setdefaultcolor ();
          return -1;
        }
      if ((command > 0 || operand > 127) && *value == 3)
        {
          *value = address;
          mt_setdefaultcolor ();
          return -1;
        }

      if (buffer[0] == MINUS_KEY)
        {
          sign = 1;
        }

      sc_commandEncode (sign, command, operand, value);
    }

  mt_setdefaultcolor ();

  return 0;
}