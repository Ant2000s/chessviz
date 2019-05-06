#include "board_print_plain.h"
#include <stdio.h>

extern char desk[8][8];
void board()
{
    printf("\n");
    for (int i = 7; i >= 0; i--) {
        printf("—+——+——+——+——+——+——+——+——+\n");
        printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c |", desk[i][j]);
        }
        printf("\n");
    }
    printf("  _______________________\n");
    printf("  A  B  C  D  E  F  G  H \n");
}
