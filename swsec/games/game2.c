#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char input[200];

void flag(void)
{
    puts("flag");
    exit(0);
}

int main(int argc, char **argv)
{
    int  answer;
    int  guess;
    char buffer[8];

    srand(time(NULL));

    answer = rand() % 8 + 1;
    gets(input);
    strcpy(buffer, input);
    guess = atoi(buffer) % 2;
    
    printf("%d\n", answer);

    if (guess == (answer % 2))
        printf("1\n");
    else
        printf("2\n");

    return (0);
}