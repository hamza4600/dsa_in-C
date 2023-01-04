// Stack wiill hold all type of data types
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Dataarea
{
    int num;
    char text[20];
    float decimal;
} Dataarea;

typedef struct Stack
{
    int top;
    unsigned size;
    struct Dataarea *data[MAX]; // Array of pointers to Dataarea
} Stack;

void push(Stack *stack, Dataarea *data)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack is full !\n");
        return;
    }
    stack->data[++stack->top] = data;
};

Dataarea *pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty !\n");
        return NULL;
    }
    return stack->data[stack->top--];
};

void printStack(Stack *stack)
{
    printf("Stack: \n");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d %s %f \n", stack->data[i]->num , stack->data[i]->text, stack->data[i]->decimal);
    }
    printf("\n");
};

void test()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = MAX;

    Dataarea *data1 = malloc(sizeof(Dataarea));
    data1->num = 1;
    data1->decimal = 1.1;
    strcpy(data1->text, "one");

    Dataarea *data2 = malloc(sizeof(Dataarea));
    data2->num = 2;
    data2->decimal = 2.2;
    strcpy(data2->text, "two");

    Dataarea *data3 = malloc(sizeof(Dataarea));
    data3->num = 3;
    data3->decimal = 3.3;
    strcpy(data3->text, "three");

    push(stack, data1);
    push(stack, data2);
    push(stack, data3);

    printStack(stack);

    Dataarea *data = pop(stack);
    printf("Poped data: %d %s %f \n", data->num , data->text, data->decimal);
    printStack(stack);

    free(data1);
    free(data2);
    free(data3);
    free(stack);
};

int main()
{
    printf("Stack of Dataarea\n");
    test();
    return 0;
}