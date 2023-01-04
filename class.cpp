// Basic of classes in cpp
#include <iostream>
#include <vector>

using namespace std;

class Car
{
public:
    string name;
    int number;
    void print()
    {
        cout << name << '\n';
        cout << number << endl;
    };
};

void test1()
{
    Car car;
    car.name = "Mercendies 15";
    car.number = 155521;
    car.print();
};

// constructore for setting properties of class
class Student
{
public:
    string brand;
    string name;
    string time;
    bool repair;

    Student(string x, string y, string z, bool a)
    {
        brand = x;
        name = y;
        time = z;
        repair = a;
    }
    void print() {
        cout << brand << endl;
        cout << name << endl;
        cout << time << endl;
        cout << repair << endl;
    }
};
void xbe() {
    Student stu("sxbx" , "cdjcbl" , "cg-xs-sx-xs", false);
    stu.print();
};
// can also declear outside of A function 
int
main()
{
    xbe();
    return 0;
};
