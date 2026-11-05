#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10
// 函数声明

// 初始化游戏区域的函数
void InitBoard(char board[ROWS][COLS], int r, int c, char set);

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c);
// 布置地雷
void SetMine(char mine[ROWS][COLS], int r, int c);
// 排查雷
void FindMine(char mine[ROWS][COLS], char shoe[ROWS][COLS], int r, int c);
#endif // GAME_H
