#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void game(int r);
int main()
{
    printf("..........\n");
    printf("..........\n");
    printf(".1.play...\n");
    printf(".0.esist..\n");
    printf("..........\n");
    printf("..........\n");
    int res;
    do
    {
        scanf("%d", &res);
        
    } while (res !=1 );
    srand((unsigned int)time(NULL));
    int r = rand() % 100 + 1;
    game(r);

        return 0;
}
void game(int r)
{
    while (1)
    {
        int guess;
        scanf("%d", &guess);
        if (guess > r)
        {
            printf("猜大了\n");
        }
        else if (guess < r)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("恭喜你,猜对了\n");
            break;
        }
    }
}
