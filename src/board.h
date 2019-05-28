#ifndef BOARD_H
#define BOARD_H

void start();
int chartoint(char input[7]);
int checkWin(int status);
int white();
int black();
void move();
int checkY();
int checkX();
int checkD();
void transformPawn();

#endif
