// loops array and function pointers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]*2);
    }
    printf("Double array  \n");
}

void address(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%p ", &array[i]);
    }
    printf("Address of array  \n");
}

void test_case() {
    // ++k  increment and return new Value and k++ is  increment and return old value
    for(int k = 0 ; k< 10; ++k) {
        printf("k is %d \n", k);
    }
}

// whiel Loop
void while_loop() {
    int i = 0;
    while (i < 10) {
        printf("i is %d \n", i);
        i++;
    }
}

// do while loop
void do_while_loop() {
    int i = 0;
    do {
        printf("i is %d \n", i);
        i++;
    } while (i < 10);
}

// even Odds 
void even_odd(int n ) {
    for(int k = 0 ; k <n; k++) {
        if(k&1) {
            printf("Odd %d \n", k);
        } else {
            printf("Even %d \n", k);
        }
    }
}

// prime Array 
void primr( int n) {
    // optimized solution
    for(int j = 2; j < n; j++) {
        int i = 2;
        for(; i < j; i++) {
            if(j%i == 0) {
                break;
            }
        }
        if(i == j) {
            printf("Prime %d \n", j);
        }
    }
}

// Array in C
void arr() {
    int a[5] = {1, 2, 3, 4, 5};
    // if size is not known
    int *b = (int *)malloc(5 * sizeof(int)); // malloc is used to allocate memory in heap and it returns a void pointer
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;
    b[4] = 5;
}

// sum up to n 
void n_sum(int n) {
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i;
    }
    printf("Sum is %d \n", sum);
}
// 
int n_sum2(int n) {
    if( n == 0) {
        return 0;
    } else {
        return n + n_sum2(n-1);
    } 
}
// plai 
void is_palindrome(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    while(i < j) {
        if(str[i] != str[j]) {
            printf("Not Palindrome \n");
            return;
        }
        i++;
        j--;
    }
    printf("Palindrome \n");
}

// randome string
void random_string() {
    char *str = (char *)malloc(10 * sizeof(char));
    for(int i = 0; i < 10; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[10] = '\0';
    printf("%s \n", str);
    free(str);
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    print_array(array, 5);
    address(array, 5);
    test_case();
    // while_loop();
    // do_while_loop();
    // even_odd(10);
    // primr(100);
    // arr();
    n_sum(10);
    printf("Sum is %d \n", n_sum2(10));
    is_palindrome("madam");
    random_string();
    return 0;
}