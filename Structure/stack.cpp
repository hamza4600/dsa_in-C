// stack in c++

#include <iostream> // for cin and cout
#include <vector>   // for vector  or array

using namespace std;
// stack is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO(last-in first-out) data structure.

class Stack
{
private:
    vector<int> v;

public:
    void push(int data)
    {
        v.push_back(data);
    }
    bool empty()
    {
        return v.size() == 0;
    }
    void pop()
    {
        if (!empty())
        {
            v.pop_back();
        }
    }
    int top()
    {
        return v[v.size() - 1];
    }
    int size()
    {
        return v.size();
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i * i);
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "Size of stack is " << s.size() << endl;
    return 0;
}