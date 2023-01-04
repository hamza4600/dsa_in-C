#include <iostream>
#include <cmath>
#include <string>

using namespace std; // is use to name and object in the std namespace

// function
void data()
{
    int zx = 0;          // is 2 or 4 byte of memory
    double asa = 55.25;  // is 8 byte of memory
    char name = 'a';     // is 1 byte  of memory
    string na = "Hamza"; // each character is 1 byte of memory
    bool isTrue = true;  // 4 byte of memory
    cout << "Data type " << zx << asa << name << na << isTrue << endl;

    // mutiple varibale s
    int x = 10, y = 20, z = 30;
    cout << "multiple Varibale declear :: " << x + y + z << endl;
    // cin is use to get input from user
}

void assigment()
{
    int x = 10;
    int y = 20;
    int z = 30;
    cout << "Assigment Operator " << x << y << z << endl;
    // Assigment Operator
    // =, +=, -=, *=, /=, %=, &=, |=, ^=, >>=, <<=
    int zz = 50;
    int zaa = zz / 2;
    cout << "Modulas " << zaa << endl;
    int az = zz >> 2; // can be written as >>=
    cout << "Right Shift " << az << endl;
    int za = zz << 2; // can be written as <<=
    cout << "Left Shift " << za << endl;
    int ya = zz & 2; // can be written as &=
    cout << "Bitwise AND " << ya << endl;
    int at = zz | 2; // can be written as |=
    cout << "Bitwise OR " << at << endl;
    int ata = zz ^ 2; // can be written as ^=
    cout << "Bitwise XOR " << ata << endl;

    // Arithmetic Operator
    // +, -, *, /, %, ++, --

    // Relational Operator
    // ==, !=, >, <, >=, <=

    // Logical Operator
    // &&, ||, !

    // Bitwise Operator
    // &, |, ^, ~, <<, >>

    // Ternary Operator
    // ?:

    // Assignment Operator
    // =, +=, -=, *=, /=, %=, &=, |=, ^=, >>=, <<=
}

void logical()
{
    int aa = 50;
    int bb = 60;
    if (aa == 50 && bb == 60)
    {
        cout << "Logical Operator " << aa << bb << endl;
    }
    if (aa != 50 || bb != 60)
    {
        cout << "Logical Operator " << aa << bb << endl;
    }
    if (aa > bb)
    {
        cout << "Logical Operator " << aa << bb << endl;
    }
}

void mathoperations()
{
    int qa = 450;
    cout << "Math Operations " << qa << endl;
    cout << "Math min " << min(450, 45) << endl;
    cout << "Math max " << max(450, 45) << endl;
    cout << "Math sqrt " << sqrt(450) << endl;
    cout << "Math round " << round(450.45) << endl;
    cout << "Comapre " << (10 < 20) << endl; // return 1 or 0  means true or false
    // cout << "Math ceil " << ceil(450.45) << endl;
    // cout << "Math floor " << floor(450.45) << endl;
}

void statements()
{
    int qwe = 89;
    int tre = 78;
    if (qwe >= tre)
    {
        cout << "If Statement " << qwe << tre << endl;
    }
    else if (qwe <= tre)
    {
        cout << "Else If Statement " << qwe << tre << endl;
    }
    else
    {
        cout << "Else Statement " << qwe << tre << endl;
    }
}
void switchs()
{
    int days = 5;
    switch (days)
    {
    case 2:
        cout << "Monday" << endl;
        break;
    case 3:
        cout << "Tuesday" << endl;
        break;
    case 4:
        cout << "Wednesday" << endl;
        break;
    case 5:
        cout << "Thursday" << endl;
        break;
    default:
        cout << "Not Found" << endl;
        break;
    }
}
//  loops whiel
void whiles()
{
    int o = 0;
    while (o < 10)
    {
        cout << "While Loop " << o << endl;
        o++;
    }
}
void fors()
{
    for (int i = 0; i <= 10; i++)
    {
        cout << "For Loop " << i << endl;
    }
}
void breaks()
{
    int y = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            break; // can also be used in while loop and continue can also be used in while loop
        }
        cout << "Break " << i << endl;
    }
}
void arrays()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array " << arr[0] << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Array " << arr[i] << endl;
    }
    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
}

void structs()
{
    //  they are used to combine data of different types into a single works like a class

    struct cars
    {
        string brand;
        string model;
        int year;
    } car1, car2;

    car1.brand = "BMW";
    car1.model = "X5";
    car1.year = 1999;

    car2.brand = "Ford";
    car2.model = "Mustang";
    car2.year = 1969;

    cout << "Struct " << car1.brand << " " << car1.model << " " << car1.year << endl;
    cout << "Struct " << car2.brand << " " << car2.model << " " << car2.year << endl;
}
// reference
void references()
{
    int x = 10;
    int &y = x; // reference variable
    cout << "Reference " << x << y << endl;
    y = 20;
    cout << "Reference " << x << y << endl;
    cout << "Reference Memeory Address " << &x << " : : " << &y << endl;
}

// pointers
void pointers()
{
    // is a varibale that stores the address of another variable as its value  * is ued to declare a pointer and & is used to get the address of a variable
    //  if we chnage the value of a pointer it will also change that original value
    string food = "Pizza";
    string *ptr = &food;
    cout << "Pointer " << food << " : : " << &food << endl;
    *ptr = "Hamburger";
    cout << "Pointer " << food << " : : " << &food << endl; // memory address will be same
}

//  Parameter Passing to a functions with respect to data types

void stri(string name = "No Name") // default parameter
{
    cout << "String " << name << endl;
}

//  return type function
int add(int a, int b)
{
    return a + b;
}
//  pass value by referience
void swaping(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void passValues()
{
    stri("Hamza");
    stri();
    cout << "Add " << add(10, 20) << endl;
    int po = 100;
    int po1 = 200;
    swaping(po, po1);
    cout << "Swaping  one , two" << po << " : : " << po1 << endl;
}
//  function oveerloading means same function name but different parameters

class Car
{
public:
    string brand;
    string model;
    int year;
    Car(string x, string y, int z) // constructor
    {
        brand = x;
        model = y;
        year = z;
    }
    //  method
    void myMethod()
    {
        cout << "Method " << brand << " " << model << " " << year << endl;
    }
};

int main()
{
    cout << " Let get started with C++ \n\n ";
    cout << " Let get started with C++" << endl;
    data();
    assigment();
    logical();
    mathoperations();
    statements();
    switchs();
    whiles();
    fors();
    breaks();
    arrays();
    structs();
    references();
    pointers();
    passValues();
    // object
    Car car1 = Car("BMW", "X5", 1999);
    car1.myMethod();
    //  vector is a dynamic array which can grow and shrink in size it is a template class

    return 0; // end of main function
}