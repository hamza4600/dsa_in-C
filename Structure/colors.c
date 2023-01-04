// colors in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// for sleep
#include <unistd.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

// britinees colors
#define BRED "\x1B[91m"
#define BGRN "\x1B[92m"

// colors in C works with printf only

char *colors[] = {
    "\x1B[31m", // red
    "\x1B[32m", // green
    "\x1B[33m", // yellow
    "\x1B[34m", // blue
    "\x1B[35m", // magenta
    "\x1B[36m", // cyan
    "\x1B[37m", // white
    "\x1B[0m",  // reset
    "\x1B[91m", // bright red
    "\x1B[92m", // bright green
    "\x1B[93m", // bright yellow
    "\x1B[94m", // bright blue
    "\x1B[95m", // bright magenta
    "\x1B[96m", // bright cyan
    "\x1B[97m", // bright white
};

void randomCol()
{
    int i = 0;
    while (i < 20)
    {
        printf("%s Hello World %s \n", colors[rand() % 15], RESET);
        i++;
    }
}

void test2()
{
    printf(" Palying with colors \n");           // reset Hello World red
    printf("%s Hello World %s \n", GRN, RED);    // green Hello World red
    printf("%s Hello World %s \n", RED, YEL);    // red Hello World yellow
    printf("%s Hello World %s \n", YEL, BLU);    // yellow Hello World blue
    printf("%s Hello World %s \n", BLU, MAG);    // blue Hello World magenta
    printf("%s Hello World %s \n", MAG, CYN);    // magenta Hello World cyan
    printf("%s Hello World %s \n", CYN, WHT);    // cyan Hello World white
    printf("%s Hello World %s \n", WHT, RESET);  // white Hello World reset
    printf("%s Hello World %s \n", RESET, BRED); // reset Hello World bright red
    printf("%s Hello World %s \n", BRED, BGRN);  // bright red Hello World bright green
    printf(" Hello World %s \n", WHT);           // bright green Hello World reset
    printf(" Hello World  \n");                  // bright green Hello World reset
};

// counter in Terminal
// everry down second chage back ground color and text color
// and print counter

char *background[] = {
    "\033[48;5;0m ",   // black
    "\033[48;5;1m ",   // red
    "\033[48;5;2m ",   // green
    "\033[48;5;3m ",   // yellow
    "\033[48;5;4m ",   // blue
    "\033[48;5;255m ", // white
    "\033[48;5;0m ",   // black
    "\033[48;5;1m ",   // red
    "\033[48;5;2m ",   // green
    "\033[48;5;3m ",
};

void counter()
{
    for (int i = 10; i >= 0; i--)
    {
        printf("\033[2J");
        // background color
        printf("%s", background[i]);
        // text color
        printf("%s", colors[i]);
        printf("%s %d \n", BGRN, i);
        printf("%d \n", i);
        sleep(1);
    }
    printf("\033[?25h"); // show cursor
}

int main()
{
    // randomCol();
    printf("%s Hello World \n", BLU); // green Hello World red
    counter();

    return 0;
};