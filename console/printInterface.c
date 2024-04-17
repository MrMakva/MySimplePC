#include "Lprint.h"
void
print_interface ()
{
  // bc_box for memory
  bc_box (1, 1, 15, 90, WHITE, DEFAULT, "оперативная память\n", RED, DEFAULT);

  // accumulator
  bc_box (1, 92, 3, 114, WHITE, DEFAULT, "аккумулятор\n", RED, DEFAULT);

  // // instructioncounter
  bc_box (1, 116, 3, 138, WHITE, DEFAULT, "регистр флагов\n", RED, DEFAULT);

  // // operation
  bc_box (4, 92, 6, 114, WHITE, DEFAULT, "счётчик команд\n", RED, DEFAULT);

  // // flags
  bc_box (4, 116, 6, 138, WHITE, DEFAULT, "команда\n", RED, DEFAULT);

  // // bc_box for bigChars
  bc_box (7, 92, 18, 138, WHITE, DEFAULT, "регистр флагов\n", RED, DEFAULT);

  //хрень внизу под оперативкой
  bc_box (16, 1, 18, 90, WHITE, DEFAULT, "редактируемая ячейка (формат)\n",
          RED, WHITE);

  // //Cash CPU
  bc_box (19, 1, 27, 100, WHITE, DEFAULT, "кэш процессора\n", GREEN, WHITE);

  // //IN-OUT
  bc_box (19, 101, 27, 115, WHITE, DEFAULT, "IN--OUT\n", GREEN, WHITE);

  // // Клавиши
  bc_box (19, 116, 27, 140, WHITE, DEFAULT, "клавиши\n", GREEN, WHITE);
}
