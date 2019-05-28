#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
char input[7];
int i1, i2, c1, c2;
char desk[8][8] = {"RNBQKBNR",
                   "PPPPPPPP",
                   "        ",
                   "        ",
                   "        ",
                   "        ",
                   "pppppppp",
                   "rnbqkbnr"};

int main()
{
    int status = 0;
    board();
    for (;;) {
        printf("Введите действие белых: ");
        start(1);
        move();
        board();
        status = checkWin(1);
        if (status != 0)
            break;
        printf("Введите действие чёрных: ");
        start(2);
        move();
        board();
        status = checkWin(2);
        if (status != 0)
            break;
    }
    return 0;
}
