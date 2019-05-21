#include "board.h"
#include <stdio.h>
#include <string.h>

extern char desk[8][8];
extern int i1, c1, i2, c2;
extern char input[7];

void start(int flag)
{
    // char input[7] = "NULL";
    for (;;) {
        for (;;) {
        fgets(input, 7, stdin);
        if (chartoint(input)) {
            break;
        }
        }
        if (flag == 1) {
            if (white() == 1) {
                break;
            } else {
                printf("Невозможное действие, введите ещё раз: ");
            }
        }
        if (flag == 2) {
            if (black() == 1) {
                break;
            } else {
                printf("Невозможное действие, введите ещё раз: ");
            }
        }
    }
}
int chartoint(char input[7])
{
    if ((input[2] != '-') && (input[2] != 'x')) {
        return 0;
    }
    c1 = (int)input[0] - 'A';
    i1 = (int)input[1] - '1';
    c2 = (int)input[3] - 'A';
    i2 = (int)input[4] - '1';
    if (desk[i1][c1] == ' ') {
        printf("В выбраной клетке ни кого нет! введите ещё раз: ");
        return 0;
    }
    if ((input[2] == 'x') && (desk[i2][c2] == ' ')) {
        printf("Некого рубить! Введите ещё раз: ");
        return 0;
    }
    if ((input[2] == '-') && (desk[i2][c2] != ' ')) {
        printf("Нельзя сходить, клетка занята. Введите ещё раз: ");
        return 0;
    }
    if ((c2 < 8) && (c2 >= 0) && (i2 < 8) && (i2 >= 0) && (c1 < 8)
            && (c1 >= 0) && (i1 < 8) && (i1 >= 0)) {
        return 1;
    }
    return 0;
}
void move()
{
    desk[i2][c2] = desk[i1][c1];
    desk[i1][c1] = ' ';
}

int white()
{
    if ((desk[i2][c2] > 'A') && (desk[i2][c2] < 'S')) {
        return 0; //не рубим своих
    }
    switch (desk[i1][c1]) {
    case 'P':
        if ((desk[i2][c2] == ' ') && (i1 == 1) && (c1 == c2) && (i2 - i1 > 0)
            && (i2 - i1 < 3) && checkY()) {
            return 1; //начальный ход
        }
        if ((desk[i2][c2] == ' ') && (c2 == c1) && (i2 - i1 == 1)) {
            transformPawn();
            return 1; //ход по пустым клеткам
        }
        if ((desk[i2][c2] < 's' && desk[i2][c2] > 'a')
            && ((c2 - c1 == 1) || (c2 - c1 == -1)) && (i2 - i1 == 1)
            && (input[2] == 'x')) {
            return 1; //рубим чужих
        }
        break;
    case 'R':
        if ((i2 == i1) && (checkX())) {
            return 1;
        }
        if ((c2 == c1) && (checkY())) {
            return 1;
        }
        break;
    case 'N':
        if ((i1 - i2 == 2) && (c1 - c2 == 1)) {
            return 1;
        }
        if ((i2 - i1 == 2) && (c2 - c1 == 1)) {
            return 1;
        }
        if ((i2 - i1 == 2) && (c1 - c2 == 1)) {
            return 1;
        }
        if ((i1 - i2 == 2) && (c2 - c1 == 1)) {
            return 1;
        }
        if ((i1 - i2 == 1) && (c2 - c1 == 2)) {
            return 1;
        }
        if ((i2 - i1 == 1) && (c2 - c1 == 2)) {
            return 1;
        }
        if ((i1 - i2 == 1) && (c1 - c2 == 2)) {
            return 1;
        }
        if ((i2 - i1 == 1) && (c1 - c2 == 2)) {
            return 1;
        }
        break;
    case 'B':
        if (checkD()) {
            return 1;
        }
        break;
    case 'K':
        if ((i1 - i2 != 1) && (i2 - i1 != 1)
            && ((c1 - c2 != 1) && (c2 - c1 != 1))) {
            break;
        } else {
            return 1;
        }
        break;
    case 'Q':
        if (checkX() || checkY() || checkD()) {
            return 1;
        }
        break;
    }
    return 0;
}
int black()
{
    if ((desk[i2][c2] > 'a') && (desk[i2][c2] < 's')) {
        return 0; //не рубим своих
    }
    switch (desk[i1][c1]) {
    case 'p':
        if ((desk[i2][c2] == ' ') && (i1 == 6) && (c1 == c2) && (i1 - i2 > 0)
            && (i1 - i2 < 3) && checkY()) {
            return 1; //начальный ход
        }
        if ((desk[i2][c2] == ' ') && (c2 == c1) && (i1 - i2 == 1)) {
            transformPawn();
            return 1; //ход по пустым клеткам
        }
        if ((desk[i2][c2] < 'S' && desk[i2][c2] > 'A')
            && ((c1 - c2 == 1) || (c1 - c2 == -1)) && (i1 - i2 == 1)) {
            return 1; //рубим чужих
        }
        break;
    case 'r':
        if ((i2 == i1) && (checkX())) {
            return 1;
        }
        if ((c2 == c1) && (checkY())) {
            return 1;
        }
        break;
    case 'n':
        if ((i1 - i2 == 2) && (c1 - c2 == 1)) {
            return 1;
        }
        if ((i2 - i1 == 2) && (c2 - c1 == 1)) {
            return 1;
        }
        if ((i2 - i1 == 2) && (c1 - c2 == 1)) {
            return 1;
        }
        if ((i1 - i2 == 2) && (c2 - c1 == 1)) {
            return 1;
        }
        if ((i1 - i2 == 1) && (c2 - c1 == 2)) {
            return 1;
        }
        if ((i2 - i1 == 1) && (c2 - c1 == 2)) {
            return 1;
        }
        if ((i1 - i2 == 1) && (c1 - c2 == 2)) {
            return 1;
        }
        if ((i2 - i1 == 1) && (c1 - c2 == 2)) {
            return 1;
        }
        break;
    case 'b':
        if (checkD()) {
            return 1;
        }
        break;
    case 'k':
        if ((i1 - i2 != 1) && (i2 - i1 != 1)
            && ((c1 - c2 != 1) && (c2 - c1 != 1))) {
            break;
        } else {
            return 1;
        }
    case 'q':
        if (checkX() || checkY() || checkD()) {
            return 1;
        }
        break;
    }
    return 0;
}

int checkY()
{
    int i, x1 = i1, x2 = i2;
    if (c1 != c2) {
        return 0;
    }
    if (i1 > i2) {
        x1 = i2;
        x2 = i1;
    }
    for (i = x1 + 1; i < x2; i++) {
        if ((desk[i][c1] > 'a' && desk[i][c1] < 's')
            || (desk[i][c1] > 'A' && desk[i][c1] < 'S')) {
            return 0;
        }
    }
    return 1;
}

int checkX()
{
    int i, y1 = c1, y2 = c2;
    if (i1 != i2) {
        return 0;
    }
    if (c1 > c2) {
        y1 = c2;
        y2 = c1;
    }
    for (i = y1 + 1; i < y2; i++) {
        if ((desk[i1][i] > 'a' && desk[i1][i] < 's')
            || (desk[i1][i] > 'A' && desk[i1][i] < 'S')) {
            return 0;
        }
    }
    return 1;
}

int checkD()
{
    int i, j, ci, cj;
    int d1 = i2;
    int d2 = i1;
    if (((i2 - i1) != (c2 - c1)) && ((i2 - i1) != (c1 - c2))) {
        return 0;
    }
    if (i2 > i1) {
        d1 = i1;
        d2 = i2;
        ci = 1;
    } else {
        ci = -1;
    }
    if (c2 > c1) {
        cj = 1;
    } else {
        cj = -1;
    }
    i = i1 + ci;
    j = c1 + cj;
    while ((i < d2) && (i > d1)) {
        if (((desk[i][j] > 'a') && (desk[i][j] < 's'))
            || ((desk[i][j] > 'A') && (desk[i][j] < 'S'))) {
            return 0;
        }
        i += ci;
        j += cj;
    }
    return 1;
}

void transformPawn()
{
    char npawn;
    if ((desk[i1][c1] == 'p') && (i2 == 0)) {
        while (1) {
            printf("Введите в какую фигуру превратить:");
            npawn = getchar();
            if ((npawn == 'r') || (npawn == 'n') || (npawn == 'b')
                || (npawn == 'q')) {
                desk[i1][c1] = npawn;
                break;
            } else {
                printf("Введите правильную фигуру.\n");
            }
        }
    }
    if ((desk[i1][c1] == 'P') && (i2 == 7)) {
        while (1) {
            printf("Введите в какую фигуру превратить:");
            npawn = getchar();
            if ((npawn == 'R') || (npawn == 'N') || (npawn == 'B')
                || (npawn == 'Q')) {
                desk[i1][c1] = npawn;
                break;
            } else {
                printf("Введите правильную фигуру.\n");
            }
        }
    }
}

int checkWin(int status)
{
    int i, j, player = 0;
    if (status == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (desk[i][j] == 'q') {
                    player = 1;
                }
            }
        }
    }
    if (status == 2) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (desk[i][j] == 'Q') {
                    player = 2;
                }
            }
        }
    }

    if (player == 0) {
        return status;
    }

    return 0;
}
