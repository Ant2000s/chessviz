#include <stdio.h>

void board(char board[8][8])
{
    printf("\n");
    for (int i = 7; i >= 0; i--) {
        printf("—+——+——+——+——+——+——+——+——+\n");
        printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c |", board[i][j]);
        }
    printf("\n");
    }
    printf("  _______________\n");
    printf("  A B C D E F G H\n");
}

int main()
{
	char dos[8][8] = {
 		"rhbqkbhr",
 		"pppppppp",
 		"        ",
 		"        ",
 		"        ",
 		"        ",
 		"PPPPPPPP",
 		"RHBQKBHR" };
    board(dos);
    return 0;
}
