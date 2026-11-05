#include <stdio.h>
int main()
{
    int n;
    scanf("%i", &n);
    char answer[n];
    for (int i = 0; i < n; i++)
        answer[i] = "i+1";
    for (int j = 0; j < n; j++)
    {
        if (answer[j] % 3 == 0 && answer[j] % 5 == 0)
            answer[j] = "FizzBuzz";
        else if (answer[j] % 3 == 0)
            answer[j] = "Fizz";
        else if (answer[j] % 5 == 0)
            answer[j] = "Buzz";
    }

    return answer;
}