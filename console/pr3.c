#include "Lprint.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"
#include "myTerm.h"
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

int
main ()
{

  int rows = 50, cols = 60;
  mt_getscreensize (&rows, &cols);
  sc_memoryInit ();
  mt_clrscr ();
  print_interface ();
  //  if (rows < 25 || cols < 25) {
  //   mt_gotoXY(1, 1);
  //   mt_setfgcolor(RED);
  //   mt_setbgcolor(WHITE);
  //   printf("Screen is too small!\n");
  //   return 0;
  // }

  mt_gotoXY (20, 117);
  write (1, "l - load", 9);
  mt_gotoXY (20, 127);
  write (1, "s - save", 9);
  mt_gotoXY (21, 117);
  write (1, "i - reset", 10);
  mt_gotoXY (22, 117);
  write (1, "r - run", 8);
  mt_gotoXY (23, 117);
  write (1, "t - step", 9);
  mt_gotoXY (24, 117);
  write (1, "esc - выход", 17);
  mt_gotoXY (25, 117);
  write (1, "F5 - accumulator", 17);
  mt_gotoXY (26, 117);
  write (1, "F6 - instruction counter", 25);

  for (int j = 0; j < 128; j++)
    {
      if (j >= 9 && j % 9 == 0)
        {
          write (1, "\n", 2);
        }

      int value;
      sc_commandEncode (1, rand () % 99, rand () % 99, &value);
      sc_memorySet (j, value);
      printCell (j, WHITE, BLACK);
      sc_accumulatorInit ();
      sc_icounterInit ();
      sc_regInit ();
      printAccumulator ();
      printCounters ();
      printFlags ();

      printCommand ();
    }

  int last_num = 1;
  srand (time (NULL));

  last_num = 0;
  rk_mytermsave ();
  for (int i = 0;;)
    {

      //ввод значения счётчика команд
      sc_icounterSet (i);
      //во время работы терминала часто может возникнуть необходимость
      //использования адреса текущей ячейки
      int address = 0;
      sc_icounterGet (&address);
      //вывод счётчика команд
      printCounters ();
      //вывод флагов
      printFlags ();
      //вывод команды
      printCommand ();
      //вывод текущей ячейки памяти
      printCell (i, RED, WHITE);
      //выводим значение аккумулятора
      printAccumulator ();
      //возвращаем в стандартные цвета предыдущую ячейку
      if (i != last_num)
        {
          printCell (last_num, WHITE, DEFAULT);
          last_num = i;
        }

      int value;
      sc_memoryGet (i, &value);
      printDecodedCommand (value);
      printTerm (i, 1);
      output_BigChars (i);

      enum keys key;
      rk_readkey (&key);
      //переменная для считывания значения в случае ввода
      int enter_value;
      switch (key)
        {
        case UP_KEY:
          if (i < 10)
            {
              if (i < 8)
                {
                  i = i + 120;
                }
              else
                {
                  i = i + 110;
                }
            }
          else
            {
              i = i - 10;
            }
          break;
        case DOWN_KEY:
          if (i > 117)
            {
              if (i < 120)
                {
                  i = i - 110;
                }
              else
                {
                  i = i - 120;
                }
            }
          else
            {
              i = i + 10;
            }
          break;
        case LEFT_KEY:
          if (i == 120)
            {
              i = i + 7;
            }
          else
            {
              if (i % 10 == 0)
                {
                  i = i + 9;
                }
              else
                {
                  i--;
                }
            }
          break;
        case RIGHT_KEY:
          if (i == 127)
            {
              i = i - 7;
            }
          else
            {
              if ((i - 9) % 10 == 0)
                {
                  i = i - 9;
                }
              else
                {
                  i++;
                }
            }
          break;
        case ESC_KEY:
          rk_mytermrestore ();
          mt_clrscr ();
          mt_setcursorvisible (1);
          return 0;
          break;

          //считываем число в закодированном виде
        case ENTER_KEY:

          enter_value = 1;
          if (rk_readvalue (&enter_value, 50) != -1)
            {
              sc_memorySet (address, enter_value);
            }
          printCell (address, WHITE, DEFAULT);
          break;
        ///////////////////////////////////////////////////
        case F5_KEY:
          //переключаем терминал в неканонический режим
          //и подсвечиваем позицию, куда будем вводить
          //значение аккумулятора
          enter_value = 2;
          if (rk_readvalue (&enter_value, 50) != -1)
            {
              sc_accumulatorSet (enter_value);
            }

          break;

        case F6_KEY:

          enter_value = 3;
          if (rk_readvalue (&enter_value, 50) != -1)
            {
              sc_icounterSet (enter_value);
              i = enter_value;
            }

          break;

        case S_KEY:
          mt_gotoXY (27, 1);
          char buf1[100];
          sprintf (buf1, "Введите название файла для сохранения: ");

          write (fileno (stdin), buf1, 73);
          rk_mytermrestore ();
          // rk_mytermregime(1, 50, 50, 1, 0);
          mt_setcursorvisible (1);
          mt_gotoXY (27, 40);
          char buf2[30];
          read (fileno (stdin), buf2, 30);
          int i = 0;
          char buf3[30];

          while (buf2[i] != '\n')
            {
              buf3[i] = buf2[i];
              i++;
            }
          // char bufff[100];
          // sprintf(bufff, "Пиздец");
          // write(fileno(stdin), bufff, 40);

          sc_memorySave (buf3);
          mt_gotoXY (27, 1);
          sprintf (buf1, "                                                    "
                         "                                 ");
          write (fileno (stdin), buf1, 86);
          rk_mytermregime (0, 50, 4, 1, 0);

          break;
        ////////////////////////////////////////
        case L_KEY:
          mt_gotoXY (27, 1);
          char buf4[100];
          sprintf (buf4, "Введите название файла для загрузки: ");
          write (fileno (stdin), buf4, 69);
          rk_mytermrestore ();
          mt_setcursorvisible (1);
          mt_gotoXY (27, 38);
          char buf5[30];
          read (fileno (stdin), buf5, 30);

          char buf6[30];
          int k = 0;
          while (buf5[k] != '\n')
            {
              buf6[k] = buf5[k];
              k++;
            }
          buf6[k] = '\0';

          sc_memoryLoad (buf6);

          rk_mytermregime (0, 50, 4, 1, 0);
          mt_gotoXY (27, 1);
          sprintf (buf1, "                                                    "
                         "                                 ");
          write (fileno (stdin), buf1, 86);

          for (int i = 0; i < 128; i++)
            {
              printCell (i, WHITE, DEFAULT);
            }
          break;

        case I_KEY:
          sc_accumulatorInit ();
          printAccumulator ();
          sc_icounterInit ();
          printCounters ();
          sc_memoryInit ();
          sc_regInit ();
          printFlags ();

          for (int i = 0; i < 128; i++)
            {
              printCell (i, WHITE, DEFAULT);
            }
          break;

        default:
          rk_mytermrestore ();
          mt_clrscr ();
          return -1;
          break;
        }
    }
  rk_mytermrestore ();
  ///////////////////////////////
  return 0;
}
