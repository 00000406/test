#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void Intboard(char board[ROW][COL], int row, int col);

void Display(char board[ROW][COL], int row, int col);

void Player(char board[ROW][COL], int row, int col);

void Computer(char board[ROW][COL], int row, int col);


//玩家赢--‘*’
//电脑赢--‘#’
//平局--Q
//继续--C
char Iswin(char board[ROW][COL], int row, int col);
