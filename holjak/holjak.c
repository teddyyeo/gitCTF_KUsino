#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char input[200];

void flag(void)
{
    puts("Well done, you have the flag!");
    exit(0);
}

int main(int argc, char **argv)
{
    int  answer;
    int  guess;
    char buffer[8];

    srand(time(NULL));
    puts("Hello this is holjak game.\n");
    puts("Please choose between odd and even.(Type '1' or '2')\n");
    printf("1. Odd\n2. Even\nYour guess: ");

    answer = rand() % 8 + 1;
    gets(input);
    strcpy(buffer, input);
    guess = atoi(buffer) % 2;
    
    printf("The answer was %d!!\n", answer);

    if (guess == (answer % 2))
        printf("You are correct!\n");
    else
        printf("You are wrong, too bad\n");

    return (0);
}
