// object in c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcpy

// how to make modifiable object in c  we can use pointer to make it modifiable
// x->y is the same as (*x).y and x.y is the same as (*x).y but x->y is more readable

// constructor is a function that return a struct
// destructor is a function that free the memory of a struct
// we can use typedef to make a struct more readable
typedef struct Car {
    int year;
    char model[20]; // array of char
    char color[20]; // array of char
    int price;
    char owner[20];
} Car;

void Car_intialize(struct Car *car, int year, char *model, char *color, int price, char *owner) {
    car -> year = year;
    car -> price = price;
    strcpy(car -> model, model); // strcpy is a function that copy a string to another string 
    strcpy(car -> color, color);
    strcpy(car -> owner, owner);
};

// print a struct
void Car_print(struct Car *car) {
    printf("Car: %s %s %d %d %s \n", car -> model, car -> color, car -> year, car -> price, car -> owner);
};

// free a struct
void Car_free(struct Car *car) {
    free(car);
};


void test() {
    struct Car *car = malloc(sizeof(struct Car)); // allocate memory for the struct
    Car_intialize(car, 2020, "BMW", "Black", 10000, "Ali"); // initialize the struct
    Car_print(car);
    Car_free(car); // free the memory of the struct
} 

typedef struct Shape {
    int x;
    int y;
    int width;
    int height;
} Shape;

void Shape_intialize(struct Shape *shape, int x, int y, int width, int height) {
    shape -> x = x;
    shape -> y = y;
    shape -> width = width;
    shape -> height = height;
};

void Shape_print(struct Shape *shape) { // if we don,t use *shape we will get an error because we are passing a pointer to a struct
    printf("Shape: %d %d %d %d \n", shape -> x, shape -> y, shape -> width, shape -> height);
};

void Shape_free(struct Shape *shape) {
    free(shape);
};

// area of a shape
int Shape_area(struct Shape *shape) {
    return shape -> width * shape -> height;
};

// move a shape
void Shape_move(struct Shape *shape, int x, int y) {
    shape -> x = x;
    shape -> y = y;
};

void text2() {
    struct Shape *shape = malloc(sizeof(struct Shape));
    Shape_intialize(shape, 10, 20, 30, 40);
    Shape_print(shape);
    printf("Area of the shape is %d \n", Shape_area(shape));
    Shape_move(shape, 100, 200);
    Shape_print(shape);
    Shape_free(shape);
};


int main()
{
    test();
    text2();
    return 0;
}