// STack and Queue implementation

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Stack implementation
class Stack
{
    int vector[100];
    int top;

public:
    Stack() { top = -1; }
    void push(int x);
    int pop();
    void print();
};

void Stack::push(int x)
{
    vector[++top] = x;
}

int Stack::pop()
{
    return vector[top--];
}

void Stack::print()
{
    cout << "Stack: Items" << endl;
    for (int i = 0; i <= top; i++)
    {
        cout << vector[i] << endl;
    }
}
void test1()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.print();
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}

// Link List implementation
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkList
{
    Node *head;

public:
    LinkList() { head = NULL; }
    void insert(int x);
    void print();
};

void LinkList::insert(int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
}

void LinkList::print()
{
    Node *temp = head;
    cout << "Link List: Items" << endl;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void test2()
{
    LinkList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.print();
}

int main()
{
    test1();
    test2();
    return 0;
}