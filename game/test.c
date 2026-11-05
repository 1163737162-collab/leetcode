#include "game.h"
void menu()
{
    printf("***********************************\n");
    printf("********Welcome to the game!*******\n");
    printf("***********************************\n");
    printf("**************1.play***************\n");
    printf("**************0.exit***************\n");
    printf("***********************************\n");
    printf("***********************************\n");
}
void game()
{
    char mine[ROWS][COLS]; // 布置好雷的
    char show[ROWS][COLS]; // 排查出的雷
    // 初始化游戏区域
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    // 打印棋盘 (游戏区)
    // DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    // 布置地雷
    SetMine(mine, ROW, COL);
    // DisplayBoard(mine,ROW,COL);
    // 排查雷
    FindMine(mine, show, ROW, COL);
}
int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("Please enter your choice: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("You have chosen to play the game!\n");
            game();
            break;
        case 0:
            printf("You have chosen to exit the game.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (input);

    return 0;
}