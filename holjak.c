#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void flag(void)
{
    puts("Well done, you have the flag!");
}

int main(int argc, char **argv)
{
    char input[20];
    printf("Hello this is holjak game\n");
    printf("Please choose between odd and even.(Type '1' or '2')\n");
    printf("1. Odd\n2. Even\n");
    srand(time(NULL));
    int answer = rand() % 2;
    gets(input);
    int guess = atoi(input) % 2;
    if (answer == 3)
    {
        flag();
        exit(1);
    }
    printf("G: %d, A: %d\n", guess, answer);
    if (guess == answer)
        printf("You are correct\n");
    else
        printf("You are wrong, too bad\n");
    exit(0);
}