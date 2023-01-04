#include <stdio.h>
#include <time.h>

// gcc -Wall -Wextra -Werror -o hello hello.c

void hello()
{
    for (int i = 0; i < 10; i++)
    {
        puts("Hello world In New Version");
        printf("Hello in Older Version  Inside of function\n");
    }
};

void sum()
{
    for (int j = 1; j < 10; j++)
    {
        printf(" %i\n ", (j));
        for (int l = 1; l < 10; l++)
        {
            printf(" %i ", (l));
        }
    }
};
// Numbers
void nums()
{
    int a = 10;
    int b = 5;
    printf("%i\n", (a << b));
};

// Squarte Table of Numbers in Terminal
void squarte()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            printf("= %i =" , (j));
        } // End of inner for loop
        printf("\n");
    }
};

// Table of any number
void table()
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);
    for (int i = 1; i < 11; i++)
    {
        printf(" %i * %i = %i \n", num, i, (i * num)); // PRINT LIKE 10 * 1 = 10
    }
}; // End of table function

// test Speed of function
// function get function as a parameter and return time and function also
double time_of_function(void (*func)())
{
    clock_t start = clock();
    func();
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds \n", time_spent);
}

// compelex function
void complex()
{
    for (int k = 0; k < 100000; k++)
    {
        printf(" %i ", (k));
    }
};

//  coding Challange
int singleNumber(int *nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
};
//  more Better Solution
int singleNumber1(int *nums, int numsSize)
{
    int aa = 0;
    for (int k = 0; k < numsSize; ++k) // ++k is faster than k++
    {
        aa ^= nums[k];
    }
    return aa;
};

int main(void)
{
    // hello();
    // nums();
    // sum();
    squarte();
    // table();
    // time_of_function(complex);
    return 0;
}