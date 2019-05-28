#include "../src/board.h"
#include "../src/board_print_plain.h"
#include "ctest.h"
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
    int z1 = chartoint(input);

    strcpy(input, "E2xE4"); // Ход взятия
    int z2 = chartoint(input);

    strcpy(input, "E2-E4"); // Обычный ход
    int z3 = chartoint(input);

    strcpy(input, "E2-E9"); // Ход за пределы поля
    int z4 = chartoint(input);

    strcpy(input, "hela"); // Ввод мусора
    int z5 = chartoint(input);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
}

CTEST(moving, movewhitepawn) // Тест белой пешки
{
    strcpy(input, "E2-E3"); // Первый ход на одну клетку
    chartoint(input);
    desk[i1][c1] = 'P';
    int z1 = white();

    strcpy(input, "E2-E4"); // Первый ход на две клетки
    chartoint(input);
    int z2 = white();

    desk[i1][c1] = ' ';

    strcpy(input, "E3-E5"); // Не первый ход на две клетки
    chartoint(input);
    desk[i1][c1] = 'P';
    int z3 = white();

    strcpy(input, "E3-F4"); // Ход по диагонали
    chartoint(input);
    int z4 = white();

    strcpy(input, "E3-E2"); // Ход назад
    chartoint(input);
    int z5 = white();

    strcpy(input, "E3xF4"); // Взятие чужой фигуры
    chartoint(input);
    desk[i2][c2] = 'p';
    int z6 = white();

    desk[i2][c2] = ' ';
    desk[i1][c1] = ' ';

    strcpy(input, "E2-E4"); // Первый ход через фигуру
    chartoint(input);
    desk[i1][c1] = 'P';
    desk[i1 + 1][c1] = 'p';
    int z7 = white();

    desk[i1][c1] = ' ';
    desk[i1 + 1][c1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
    ASSERT_EQUAL(exp6, z6);
    ASSERT_EQUAL(exp7, z7);
}

CTEST(moving, moveblackpawn) // Тест черной пешки
{
    strcpy(input, "D7-D6"); // Первый ход на одну клетку
    chartoint(input);
    desk[i1][c1] = 'p';
    int z1 = black();

    strcpy(input, "D7-D5"); // Первый ход на две клетки
    chartoint(input);
    int z2 = black();

    desk[i1][c1] = ' ';

    strcpy(input, "D6-D4"); // Не первый ход на две клетки
    chartoint(input);
    desk[i1][c1] = 'p';
    int z3 = black();

    strcpy(input, "D6-C5"); // Ход по диагонали
    chartoint(input);
    int z4 = black();

    strcpy(input, "D6-D7"); // Ход назад
    chartoint(input);
    int z5 = black();

    strcpy(input, "D6xC5"); // Взятие чужой фигуры
    chartoint(input);
    desk[i2][c2] = 'P';
    int z6 = black();

    desk[i2][c2] = ' ';
    desk[i1][c1] = ' ';

    strcpy(input, "D7-D5"); // Первый ход через фигуру
    chartoint(input);
    desk[i1][c1] = 'P';
    desk[i1 + 1][c1] = 'P';
    int z7 = black();

    desk[i1][c1] = ' ';
    desk[i1 + 1][c1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
    ASSERT_EQUAL(exp6, z6);
    ASSERT_EQUAL(exp7, z7);
}

CTEST(moving, moverook) // Тест ладьи
{
    strcpy(input, "D4-D7"); // Ход вперед
    chartoint(input);
    desk[i1][c1] = 'R';
    int z1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    chartoint(input);
    int z2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    chartoint(input);
    int z3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    chartoint(input);
    int z4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали
    chartoint(input);
    int z5 = white();

    strcpy(input, "D4xD5"); // Взятие чужой фигуры
    chartoint(input);
    desk[i2][c2] = 'r';
    int z6 = white();

    strcpy(input, "D4-D6"); // Ход через фигуру
    chartoint(input);
    int z7 = white();

    desk[i1][c1] = ' ';
    desk[i2 - 1][c2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
    ASSERT_EQUAL(exp6, z6);
    ASSERT_EQUAL(exp7, z7);
}

CTEST(moving, moveknight) // Тест коня
{
    strcpy(input, "D4-D7"); // Ход вперед
    chartoint(input);
    desk[i1][c1] = 'N';
    int z1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    chartoint(input);
    int z2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    chartoint(input);
    int z3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    chartoint(input);
    int z4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали
    chartoint(input);
    int z5 = white();

    strcpy(input, "D4-C6"); // Ход Г вверх влево
    chartoint(input);
    int z61 = white();

    strcpy(input, "D4-E6"); // Ход Г вверх вправо
    chartoint(input);
    int z62 = white();

    strcpy(input, "D4-F5"); // Ход Г вправо вверх
    chartoint(input);
    int z63 = white();

    strcpy(input, "D4-F3"); // Ход Г вправо вниз
    chartoint(input);
    int z64 = white();

    strcpy(input, "D4-E2"); // Ход Г вниз вправо
    chartoint(input);
    int z65 = white();

    strcpy(input, "D4-C2"); // Ход Г вниз влево
    chartoint(input);
    int z66 = white();

    strcpy(input, "D4-B5"); // Ход Г влево вверх
    chartoint(input);
    int z67 = white();

    strcpy(input, "D4-B3"); // Ход Г влево вниз
    chartoint(input);
    int z68 = white();

    strcpy(input, "D4xE6"); // Ход через фигуру и взятие
    chartoint(input);
    desk[c1 + 1][i1] = 'p';
    desk[i2][c2] = 'n';
    int z7 = white();

    desk[i1][c1] = ' ';
    desk[c1 + 1][i1] = ' ';
    desk[i2][c2] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp61 = 1;
    const int exp62 = 1;
    const int exp63 = 1;
    const int exp64 = 1;
    const int exp65 = 1;
    const int exp66 = 1;
    const int exp67 = 1;
    const int exp68 = 1;
    const int exp7 = 1;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
    ASSERT_EQUAL(exp61, z61);
    ASSERT_EQUAL(exp62, z62);
    ASSERT_EQUAL(exp63, z63);
    ASSERT_EQUAL(exp64, z64);
    ASSERT_EQUAL(exp65, z65);
    ASSERT_EQUAL(exp66, z66);
    ASSERT_EQUAL(exp67, z67);
    ASSERT_EQUAL(exp68, z68);
    ASSERT_EQUAL(exp7, z7);
}

CTEST(moving, movebishop) // Тест слона
{
    strcpy(input, "D4-D7"); // Ход вперед
    chartoint(input);
    desk[i1][c1] = 'B';
    int z1 = white();

    strcpy(input, "D4-D2"); // Ход назад
    chartoint(input);
    int z2 = white();

    strcpy(input, "D4-F4"); // Ход вправо
    chartoint(input);
    int z3 = white();

    strcpy(input, "D4-B4"); // Ход влево
    chartoint(input);
    int z4 = white();

    strcpy(input, "D4-F6"); // Ход по диагонали вверх вправо
    chartoint(input);
    int z51 = white();

    strcpy(input, "D4-B6"); // Ход по диагонали вверх влево
    chartoint(input);
    int z52 = white();

    strcpy(input, "D4-F2"); // Ход по диагонали вниз вправо
    chartoint(input);
    int z53 = white();

    strcpy(input, "D4xB2"); // Ход по диагонали вверх вправо и взятие
    chartoint(input);
    desk[i2][c2] = 'p';
    int z54 = white();

    desk[i2][c2] = ' ';

    strcpy(input, "D4-F6"); // Ход по диагонали вниз вправо через фигуру
    chartoint(input);
    desk[i2 - 1][c2 - 1] = 'p';
    int z6 = white();

    desk[i1][c1] = ' ';
    desk[i2 - 1][c2 - 1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp51 = 1;
    const int exp52 = 1;
    const int exp53 = 1;
    const int exp54 = 1;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp51, z51);
    ASSERT_EQUAL(exp52, z52);
    ASSERT_EQUAL(exp53, z53);
    ASSERT_EQUAL(exp54, z54);
    ASSERT_EQUAL(exp6, z6);
}

CTEST(moving, moveking) // Тест короля
{
    strcpy(input, "D4-D5"); // Ход вверх
    chartoint(input);
    desk[i1][c1] = 'K';
    int z1 = white();

    strcpy(input, "D4-D3"); // Ход вниз
    chartoint(input);
    int z2 = white();

    strcpy(input, "D4-C4"); // Ход влево
    chartoint(input);
    int z3 = white();

    strcpy(input, "D4-E4"); // Ход вправо
    chartoint(input);
    int z4 = white();

    strcpy(input, "D4-E5"); // Ход вверх вправо
    chartoint(input);
    int z5 = white();

    strcpy(input, "D4-C5"); // Ход вверх влево
    chartoint(input);
    int z6 = white();

    strcpy(input, "D4-E3"); // Ход вниз вправо
    chartoint(input);
    int z7 = white();

    strcpy(input, "D4xC3"); // Ход вниз влево и взятие
    chartoint(input);
    desk[i2][c2] = 'p';
    int z8 = white();

    desk[i2][c2] = ' ';

    strcpy(input, "D4-D6"); // Ход вверх на 2 клетки
    chartoint(input);
    int z9 = white();

    strcpy(input, "D4-F2"); // Ход вниз вправо на 2 клетки
    chartoint(input);
    int z10 = white();

    desk[i1][c1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
    ASSERT_EQUAL(exp6, z6);
    ASSERT_EQUAL(exp7, z7);
    ASSERT_EQUAL(exp8, z8);
    ASSERT_EQUAL(exp9, z9);
    ASSERT_EQUAL(exp10, z10);
}

CTEST(moving, movequeen) // Тест ферзя
{
    strcpy(input, "D4-D7"); // Ход вверх
    chartoint(input);
    desk[i1][c1] = 'Q';
    int z1 = white();

    strcpy(input, "D4-D1"); // Ход вниз
    chartoint(input);
    int z2 = white();

    strcpy(input, "D4-A4"); // Ход влево
    chartoint(input);
    int z3 = white();

    strcpy(input, "D4-G4"); // Ход вправо
    chartoint(input);
    int z4 = white();

    strcpy(input, "D4-G7"); // Ход по диагонали вверх вправо
    chartoint(input);
    int z5 = white();

    strcpy(input, "D4-A7"); // Ход по диагонали вверх влево
    chartoint(input);
    int z6 = white();

    strcpy(input, "D4-A1"); // Ход по диагонали вних влево
    chartoint(input);
    int z7 = white();

    strcpy(input, "D4xG1"); // Ход по диагонали вниз вправо и взятие
    chartoint(input);
    desk[i2][c2] = 'p';
    int z8 = white();

    desk[i2][c2] = ' ';

    strcpy(input, "D4-G7"); // Ход по диагонали вверх вправо через фигуру
    chartoint(input);
    desk[i2 - 1][c2 - 1] = 'p';
    int z9 = white();

    desk[i2 - 1][c2 - 1] = ' ';

    strcpy(input, "D4-F7"); // Ход Г по диагонали вверх вправо
    chartoint(input);
    int z10 = white();

    desk[i1][c1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
    ASSERT_EQUAL(exp5, z5);
    ASSERT_EQUAL(exp6, z6);
    ASSERT_EQUAL(exp7, z7);
    ASSERT_EQUAL(exp8, z8);
    ASSERT_EQUAL(exp9, z9);
    ASSERT_EQUAL(exp10, z10);
}
CTEST(signs ,sign)
{
    strcpy(input, "E2fE4"); // Ввод неправильного формата
    int z1 = chartoint(input);

    strcpy(input, "E2xE4"); // Ход взятия
    int z2 = chartoint(input);

    strcpy(input, "E2-E4"); // Обычный ход
    int z3 = chartoint(input);

    strcpy(input, "E2#E9"); // Неправилный знак
    int z4 = chartoint(input);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;

    ASSERT_EQUAL(exp1, z1);
    ASSERT_EQUAL(exp2, z2);
    ASSERT_EQUAL(exp3, z3);
    ASSERT_EQUAL(exp4, z4);
}
