#include "game.h"
// 函数的定义

void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            board[i][j] = set;
        }
    }
}
void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
    for (int i = 0; i <= c; i++)
        printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= r; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= c; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void SetMine(char mine[ROWS][COLS], int r, int c)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % r + 1;
        int y = rand() % c + 1;
        if (mine[x][y] != '1')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}
// 来支持FindMine函数的实现而存在
// static修饰，变成内部函数
static size_t GetMineCount(char mine[ROWS][COLS], int x, int y)
{
    size_t res=0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (mine[i][j] == '1')
                res++;
        }
    }
    return res;
    
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
    int x, y;
    int cleared = 0; // 已排查出的安全位置数量
    while (1)
    {
        // 保存本次输入坐标的开始和结束时间
        struct timespec start, end;
        printf("请输入要排查的坐标");
        // 确保提示立即显示，再开始计时
        fflush(stdout);
        // 使用单调时钟，避免系统时间调整影响计时
        clock_gettime(CLOCK_MONOTONIC, &start);
        scanf("%d %d", &x, &y);
        clock_gettime(CLOCK_MONOTONIC, &end);
        // 秒数之差加上纳秒之差，得到本次输入耗时（单位：秒）
        double elapsed = (end.tv_sec - start.tv_sec) +
                         (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("本次用时: %.2f 秒\n", elapsed);
        // 判断输入坐标合理性
        if (x >= 1 && x <= r && y >= 1 && y <= c)
        {
            // 判断该位置是否被排查
            if (show[x][y] == '*')
            {
                // 第一次选中雷时，把它移到另一个没有雷的位置
                if (cleared == 0 && mine[x][y] == '1')
                {
                    for (int i = 1; i <= r; i++)
                    {
                        int moved = 0;
                        for (int j = 1; j <= c; j++)
                        {
                            if (mine[i][j] == '0')
                            {
                                mine[i][j] = '1';
                                mine[x][y] = '0';
                                moved = 1;
                                break;
                            }
                        }
                        if (moved)
                            break;
                    }
                }
                // 该位置是不是雷
                if (mine[x][y] == '0') // 不是雷
                {
                    size_t count = GetMineCount(mine, x, y); // 统计mine数组中x,y周围雷的个数
                    show[x][y] = (char)(count + '0');
                    cleared++;
                    DisplayBoard(show, r, c);
                    // 所有安全位置都已排查，游戏胜利
                    if (cleared == r * c - EASY_COUNT)
                    {
                        printf("恭喜你，排雷成功！\n");
                        break;
                    }
                }
                else // 是雷
                {
                    printf("很遗憾,你被炸死了\n");
                    DisplayBoard(mine, ROW, COL);
                    break;
                }
            }
            else
            {
                printf("该位置已经被排查过了,请重新输入坐标\n");
            }
        }
        else
        {
            printf("输入的坐标非法,请重新输\n");
        }
    }
}
