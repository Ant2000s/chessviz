#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

// extern char desk[8][8];

char desk[8][8] = {"RHBQKBHR",
                   "PPPPPPPP",
                   "        ",
                   "        ",
                   "        ",
                   "        ",
                   "pppppppp",
                   "rhbqkbhr"};

int main()
{
    board();
    for (;;) {
        printf("Введите действие белых: ");
        start(1);
        move();
        board();
        printf("Введите действие чёрных: ");
        start(2);
        move();
        board();
    }
    return 0;
}
