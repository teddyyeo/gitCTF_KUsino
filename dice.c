#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sum = 0;
char input[128];

void flag(void){
    puts("hello1\n");
    puts("hello2\n");
    puts("hello3\n");
    exit(0);
}

int main(void)
{
    int dice1 = 0;
    int dice2 = 0;
    char predict[8];

    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    sum = dice1 + dice2;

    gets(input);
    strcpy(predict, input);

    // 주사위 결과 예측
    printf("Guess dice1 + dice2: ");
    scanf("%s", predict); // 버퍼 오버플로우 취약점
    if (atoi(predict) == sum)
    {
        printf("You win!\n");
    }
    else
    {
        printf("You loose!\n");
    }

    return 0;
}