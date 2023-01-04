#include <stdio.h>

/*

The data type size and range depend a lot on the compiler. However, the code that the compiler compiles is targeted for some specific types of Microcontrollers or Microprocessors

   int **p is used to declear multi dimesional array
    & is used to get the address of a variable
    [] is used to declare an array
    () is used to declare a function
    {} is used to declare a structure
    -> is used to access a member of a structure using a pointer
    . is used to access a member of a structure using a variable
    :: is used to access a member of a class using a pointer
    : is used to access a member of a class using a variable
    ; is used to terminate a statement
    , is used to separate two or more statements
    # is used to include a header file
    ? is used to declare a ternary operator
    : is used to declare a ternary operator
    = is used to assign a value to a variable
    += is used to add a value to a variable
    -= is used to subtract a value from a variable
    *= is used to multiply a value to a variable
    /= is used to divide a value from a variable
    %= is used to get the remainder of a value from a variable
    ++ is used to increment a value by 1
    -- is used to decrement a value by 1
    ! is used to negate a value
    ~ is used to negate a value
    & is used to get the address of a variable
    * is used to get the value of a variable
    sizeof is used to get the size of a variable
    && is used to check if two conditions are true
    || is used to check if one of two conditions is true
    & is used to check if two conditions are true
    | is used to check if one of two conditions is true
    ^ is used to check if one of two conditions is true
    << is used to shift bits to the left
    >> is used to shift bits to the right
    == is used to check if two values are equal
    != is used to check if two values are not equal

    int is used to declare an integer variable
    float is used to declare a floating point variable
    double is used to declare a double floating point variable
    char is used to declare a character variable
    void is used to declare a function that does not return a value
    signed is used to declare a signed variable
    unsigned is used to declare an unsigned variable
    short is used to declare a short variable
    long is used to declare a long variable
    struct is used to declare a structure
    union is used to declare a union
    enum is used to declare an enumeration
    typedef is used to declare a type
    auto is used to declare an automatic variable
    register is used to declare a register variable
    static is used to declare a static variable
    extern is used to declare an external variable
    volatile is used to declare a volatile variable
    const is used to declare a constant variable
    goto is used to declare a goto statement
    break is used to declare a break statement
    continue is used to declare a continue statement

    * is a pointer to a pointer 
    ** is a pointer to a pointer to a pointer
    %p is a pointer
    %s is a string
    %d is a decimal
    %c is a character
    %f is a float
    %lf is a double float
    %i is an integer
    %u is an unsigned integer
    %o is an octal integer
    %x is a hexadecimal integer
    %X is a hexadecimal integer
    %e is a float in scientific notation
    %E is a float in scientific notation

   */
// Data types
void dat_types()
{
    //    interget
    int a = 104545;                // is a 4 bit integer
    short b = 1045;                // is a 2 bit integer
    long c = 104154564512646;      // is up a 8 bit integer
    long long d = 104454545656565; // is a 8 bit integer
    unsigned int e = 1465656560;   // is a 4 bit integer  can be only positive
    unsigned short f = 10;         // is a 2 bit integer
    unsigned long g = 10;          // is a 64 bit integer
    unsigned long long h = 10;     // is a 8 bit integer
    signed int i = 10;             // is a 4 bit integer  can be positive or negative
    signed short j = 1450;         // is a 2 bit integer
    signed long k = 10;            // is a 8 bit integer
    signed long long l = 10;       // is a 8 bit integer

    __uint8_t n = 10;                   // is a 8 bit integer
    __uint16_t o = 10;                  // is a 16 bit integer
    __uint32_t p = 10;                  // is a 32 bit integer
    __uint64_t q = 1015456562355656564; // is a 64 bit integer

    // floats
    float r = 10.0f;            // is a 4 bit float can also used f
    double s = 10.0;            // is a 8 bit float
    long double t = 10.5656560; // is a 16 bit float

    // char
    char u = 'a';          // is a 8 bit integer
    unsigned char v = 'a'; // is a 8 bit integer
    signed char w = 'a';   // is a 8 bit integer

    // printf("Size of int is %lu bytes\n", sizeof(w));

    // chararcter are also arrays
    char x[] = "Hello World"; // is a 12 bit integer
    char x1[10] = "Hello";    // is a 8 bit integer
    // printf("Size of is %lu bytes\n  %s", sizeof(x) , x);

    // long senetece can be declared as
    char x2[] = "Hello World, this is a long sentence that can be used to test the size of a char array";

    // printf("Size of  is %lu bytes\n  %s \n", sizeof(x2) , x2);

    // pointer
    int *y = &a; // is a 8 bytes

    printf("Size of  is %lu bytes\n  %d \n", sizeof(y), *y);
    printf("Pointer Value is %p \n", y);
    printf("Pointer Address is %p \n", &y);
    printf("Pointer Address is %p \n", &a);
    // y is a pointer to a variable and &y is the address of the pointer variable and &a is the address of the variable
    // we can also use *y to get the value of the variable and also change the value of the variable
    *y = 10;
    printf("Pointer Value is %p \n", y);
    printf(" Change value is %d \n", *y);
    printf("Pointer Address is %p \n", &y);
}

void pointers()
{
    int az = 5000;
    int *p = &az;
    // az and p are having the same address and value but p is a pointer to az and &p is the address of p and &az is the address of az
    printf("Pointer Address is %p \n", p);
    printf("Pointer Address is %p \n", &p);
    printf("Pointer Address is %p \n", &az);
    printf("Pointer Value is %d \n", *p);
    printf("Pointer Value is %d \n", az);
    printf("Pointer Value is %d \n", *(&az));

    // chaning value of pointer
    *p = 10;
    printf("az value is %d \n", az);
    printf("p value is %d \n", *p);
    printf("p address is we have change the value in this adress %p \n", p);
};

// Bitwise opertaions in C are very important
void bits() {
    
    // basic Rules are 
    // 1. 0 & 0 = 0
    // 2. 0 & 1 = 0
    // 3. 1 & 0 = 0
    // 4. 1 & 1 = 1

    // 5. 0 | 0 = 0
    // 6. 0 | 1 = 1
    // 7. 1 | 0 = 1
    // 8. 1 | 1 = 1
    
    // 9. 0 ^ 0 = 0
    // 10. 0 ^ 1 = 1
    // 11. 1 ^ 0 = 1
    // 12. 1 ^ 1 = 0
    
    // 13. ~0 = 1
    // 14. ~1 = 0
    
    // 15. 0 << 1 = 0
    // 16. 1 << 1 = 10
    // 17. 0 >> 1 = 0
    // 18. 1 >> 1 = 0
    
    int a = 5; // 00000101
    int b = 7; // 00000111
    int c = a & b; // 00000101
    int d = a | b; // 00000111
    int e = a ^ b; // 00000010
    int f = ~a; // 11111010
    int g = a << 1; // 00001010
    int h = a >> 1; // 00000010
    printf("a & b is %d \n", c);
    printf("a | b is %d \n", d);
    printf("a ^ b is %d \n", e);
    printf("~a is %d \n", f);
    printf("a << 1 is %d \n", g);
    printf("a >> 1 is %d \n", h);

};

// common Opertaios
void common() {
    int aa = 500;
    int tt = 400;
    int cc = aa + tt;
    printf("Values of %d + %d is %d \n", aa, tt, cc);
    printf("Direct Operation %d \n", aa + tt);
  
};

int main()
{
    // dat_types();
    // pointers();
    // bits();
    common();
    return 0;
}