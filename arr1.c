#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    char students[30][10] =
        {"张三", "李四", "王五", "赵六", "陈晨",
         "刘洋", "孙丽", "周涛", "吴杰", "郑爽",
         "Alice", "Bob", "Charlie", "David", "Emma",
         "Frank", "Grace", "Henry", "Isabella", "Jack",
         "Olivia", "Liam", "Sophia", "Noah", "Mia",
         "Ethan", "Lucas", "Amelia", "James", "Emily"};
    srand((unsigned int)time(NULL));
    int name1 = rand() % 30;
    int name2 = rand() % 30;
    printf("抽到的两位同学是：%s 和 %s\n", students[name1], students[name2]);
    return 0;
}
