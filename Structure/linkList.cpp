// Linklist 
#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkList {
    private:
        Node *head, *tail;
    public:
        LinkList() {
            head = NULL;
            tail = NULL;
        }
        void addNode(int n) {
            Node *temp = new Node;
            temp->data = n;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                tail = temp;
                temp = NULL;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        void display() {
            Node *temp = new Node;
            temp = head;
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
        void insertStart(int value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        void insertPosition(int pos, int value) {
            Node *pre = new Node;
            Node *cur = new Node;
            Node *temp = new Node;
            cur = head;
            for (int i = 1; i < pos; i++) {
                pre = cur;
                cur = cur->next;
            }
            temp->data = value;
            pre->next = temp;
            temp->next = cur;
        }
        void deleteFirst() {
            Node *temp = new Node;
            temp = head;
            head = head->next;
            delete temp;
        }
        void deleteLast() {
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            tail = previous;
            previous->next = NULL;
            delete current;
        }
        void deletePosition(int pos) {
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            for (int i = 1; i < pos; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
        }
};



int main () {
    
    LinkList a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.addNode(5);
    a.display();
    
 
    return 0;
}
