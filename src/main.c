#include "board_print_plain.h"
#include "board.h"
#include <stdio.h>

// extern char desk[8][8];

char desk[8][8] = {"rhbqkbhr",
                   "pppppppp",
                   "        ",
                   "        ",
                   "        ",
                   "        ",
                   "PPPPPPPP",
                   "RHBQKBHR"};

int main()
{
    board();
    for (;;) {
     start(1);
     move();
     board();
     start(2);
     move(2);
     board();
     }
    return 0;
}
