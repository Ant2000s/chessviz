#include "../src/board.h"
#include "../src/board_print_plain.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

int status = 0, i, j;
int c1, c2, i1, i2;
char desk[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char input[7];

CTEST(inputdata, chartointer)
{
    strcpy(input, "E2fE4"); // Ввод неправильного формата
    int c1 = chartoint(input);

    strcpy(input, "E2xE4"); // Ход взятия
    int c2 = chartoint(input);

    strcpy(input, "E2-E4"); // Обычный ход
    int c3 = chartoint(input);

    strcpy(input, "E2-E9"); // Ход за пределы поля
    int c4 = chartoint(input);

    strcpy(input, "hello!"); // Ввод мусора
    int c5 = chartoint(input);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}

CTEST(moving, movewhitepawn) // Тест белой пешки
{
    strcpy(input, "E2-E3"); // Первый ход на одну клетку
    chartoint(input);
    desk[i1][c1] = 'P';
    int c1 = white();

    strcpy(input, "E2-E4"); // Первый ход на две клетки
    chartoint(input);
    int c2 = white();

    desk[i1][c1] = ' ';

    strcpy(input, "E3-E5"); // Не первый ход на две клетки
    chartoint(input);
    desk[i1][c1] = 'P';
    int c3 = white();

    strcpy(input, "E3-F4"); // Ход по диагонали
    chartoint(input);
    int c4 = white();

    strcpy(input, "E3-E2"); // Ход назад
    chartoint(input);
    int c5 = white();

    strcpy(input, "E3xF4"); // Взятие чужой фигуры
    chartoint(input);
    desk[i2][c2] = 'p';
    int c6 = white();

    desk[i2][c2] = ' ';
    desk[i1][c1] = ' ';

    strcpy(input, "E2-E4"); // Первый ход через фигуру
    chartoint(input);
    desk[i1][c1] = 'P';
    desk[i1 + 1][c1] = 'p';
    int c7 = white();

    desk[i1][c1] = ' ';
    desk[i1 + 1][c1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveblackpawn) // Тест черной пешки
{
    strcpy(input, "D7-D6"); // Первый ход на одну клетку
    chartoint(input);
    desk[i1][c1] = 'p';
    int c1 = black();

    strcpy(input, "D7-D5"); // Первый ход на две клетки
    chartoint(input);
    int c2 = black();

    desk[i1][c1] = ' ';

    strcpy(input, "D6-D4"); // Не первый ход на две клетки
    chartoint(input);
    desk[i1][c1] = 'p';
    int c3 = black();

    strcpy(input, "D6-C5"); // Ход по диагонали
    chartoint(input);
    int c4 = black();

    strcpy(input, "D6-D7"); // Ход назад
    chartoint(input);
    int c5 = black();

    strcpy(input, "D6xC5"); // Взятие чужой фигуры
    chartoint(input);
    desk[i2][c2] = 'P';
    int c6 = black();

    desk[i2][c2] = ' ';
    desk[i1][c1] = ' ';

    strcpy(input, "D7-D5"); // Первый ход через фигуру
    chartoint(input);
    desk[i1][c1] = 'P';
    desk[i1 + 1][c1] = 'P';
    int c7 = black();

    desk[i1][c1] = ' ';
    desk[i1 + 1][c1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moverook) // Тест ладьи
{
    strcpy(input, "D4-D7"); // Ход вперед
    chartoint(input);
    desk[i1][c1] = 'R';
    int c1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    chartoint(input);
    int c2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    chartoint(input);
    int c3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    chartoint(input);
    int c4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали
    chartoint(input);
    int c5 = white();

    strcpy(input, "D4xD5"); // Взятие чужой фигуры
    chartoint(input);
    desk[i2][c2] = 'r';
    int c6 = white();

    strcpy(input, "D4-D6"); // Ход через фигуру
    chartoint(input);
    int c7 = white();

    desk[i1][c1] = ' ';
    desk[i2 - 1][c2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

