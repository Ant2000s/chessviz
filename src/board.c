#include "board.h"
#include "stdio.h"
#include <string.h>

extern char desk[8][8];
int i1;c1;i2;c2;

void start(int flag)
{
char input[5]=NULL;
for(;;){
 for(;;){
  fgets(input,5,stdin);
   if(flag==1){
     white();
    break;
   }
   if (flag==2){
    black();
    break;
   }
}
int white()
{
 switch(desk[i1][c1]) {
  case 'P'
   if((desk[i2][c2]== ' ') && (i1==2) && (c2==c1)&&((i2-i1)>0)&&((i2-i1)<=2)) {
    return 1;
   if ((desk[i2][c2]== ' ')&&((i2-i1)>0)&&((i2-i1)<=1)) {
   return 1;
   if ((desk[i2][c2]>'a')&&(desk[i2][c2]<'s')) {
  return 1;
 return 0;
}


int black()
{
 switch(desk[i1][c1]) {
  case 'p'
   if((desk[i2][c2]== ' ') && (i1==6) && (c2==c1)&&((i1-i2)>0)&&((i1-i2)<=2)) {
    return 1;
   if ((desk[i2][c2]== ' ')&&((i1-i2)>0)&&((i1-i2)<=1)) {
   return 1;
   if ((desk[i2][c2]>'A')&&(desk[i2][c2]<'S')) {
  return 1;
 return 0;
}
