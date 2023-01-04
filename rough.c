#include <stdio.h>
#include <stdlib.h>

// struct

typedef struct Point
{
    int x;
    int y;
} Point;

void newPoint(struct Point *point, int x, int y)
{
    point->x = x;
    point->y = y;
};

void values(struct Point *point)
{
    printf("Pointer Adress :: %p \n", point);
    printf("Points values \n %d %d \n", point->x, point->y);
};

void update(struct Point *point, int x, int y)
{
    point->x = x;
    point->y = y;
};

void free_space(struct Point *point)
{
    free(point);
};

void test()
{
    struct Point *point = malloc(sizeof(struct Point));
    newPoint(point, 10, 500);
    values(point);
    update(point, 100, 987);
    values(point);
    free_space(point);
};

union Plane
{
    struct Point *point1;
    struct Point *point2;
};

void test_t(int n)
{
    // print plane;
    for (int i = 0; i < n; i++)
    {
        printf("\n * ");
        for (int j = 0; j < n; j++)
        {
            printf(" = ");
        }
        for (int j = 0; j < n; j++)
        {
            if (j&1)
            {
                printf(" # ");
            } else {
                printf("  ");
            }
        }
    }
    printf("\n");
};

// tabel
void table(int x)
{
    printf(" Table of %d \n", x);
    for (int k = 0; k <= x; k++)
    {
        printf(" %d * %d =  %d \n", x, k, k * x);
    }
}
int main()
{
    // test();
    test_t(10);
    table(10);
    return 0;
}