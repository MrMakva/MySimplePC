#!/bin/bash

clear_screen="\033[2J\033[H"
cursor_address="\033[%d;%dH"
set_a_background="\033[3%dm"
set_a_foreground="\033[4%dm"
cursor_invisible="\033[?25l"
cursor_visible="\033[?25h"
delete_line="\033[2K"
reset="\033[0m"

print_with_colors(){
  printf "$cursor_address" $1 $2
  printf "$set_a_foreground" $3
  printf "$set_a_background" $4
  echo -n $5
}

echo -e "$clear_screen"
print_with_colors 5 10 1 0 "Вадим"
print_with_colors 6 8 2 7 "ИС-242"

printf "$cursor_address" 10 1
echo -e "$reset"

echo -e "$cursor_visible"