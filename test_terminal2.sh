#!/bin/bash

echo -e "\033c"

# Переход к позиции 10, 5
echo -e "\033[10;5H"

# Массив для хранения состояний каждой ячейки в рамке
declare -A frame

# Инициализируем все ячейки пустыми 
for ((i=1; i<=8; i++))
do
    for ((j=1; j<=8; j++))
    do
        frame["$i,$j"]=" "
    done
done

# Заполняем рамку и выводим символ
for ((i=1; i<=8; i++))
do
    for ((j=1; j<=8; j++))
    do
        # Верхняя и нижняя границы рамки
        if [[ $i -eq 1 ]]; then
            if [[ $j -eq 1 ]]; then
                frame["$i,$j"]="┌"
            elif [[ $j -eq 8 ]]; then
                frame["$i,$j"]="┐"
            else
                frame["$i,$j"]="─"
            fi
        elif [[ $i -eq 8 ]]; then
            if [[ $j -eq 1 ]]; then
                frame["$i,$j"]="└"
            elif [[ $j -eq 8 ]]; then
                frame["$i,$j"]="┘"
            else
                frame["$i,$j"]="─"
            fi
        elif [[ $j -eq 1 || $j -eq 8 ]]; then
            frame["$i,$j"]="│"
        fi
    done
done

frame[2,2]="█"
frame[2,3]="█"
frame[2,4]="█"
frame[2,5]="█"
frame[2,6]="█"
frame[2,7]="█"
frame[3,6]="█"
frame[3,7]="█"
frame[4,5]="█"
frame[4,6]="█"
frame[5,4]="█"
frame[5,3]="█"
frame[6,3]="█"
frame[6,2]="█"
frame[7,2]="█"
frame[7,3]="█"
frame[7,4]="█"
frame[7,5]="█"
frame[7,6]="█"
frame[7,7]="█"

for ((i=1; i<=8; i++))
do
    for ((j=1; j<=8; j++))
    do
        echo -n "${frame[$i,$j]}"
    done
    echo
done

echo
