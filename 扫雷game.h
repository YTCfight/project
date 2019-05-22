#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define EASY 10

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void Initboard(char board[ROWS][COLS], int row, int col, char set);
void Display(char board[ROWS][COLS], int row, int col);
void Setmine(char mine[ROWS][COLS], int row,int col);
void Findlei(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void RmoveMine(char mine[ROWS][COLS], int x, int y);
void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
