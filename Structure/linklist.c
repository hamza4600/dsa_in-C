// Link List In C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// for sleep
#include <unistd.h>

// link list
typedef struct node
{
    int data;
    struct node *next;
} node;

// create a new node
// this is a function pointer to a function that returns a pointer to a node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert a node at the end of the list
void insertNode(node **head, int data)
{
    node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// print the list
void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf(" -> ");
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// delete a node from the list
void deleteNode(node **head, int data)
{
    if (*head == NULL || head == NULL)
    {
        return;
    }
    if (!(*head)->next && (*head)->data == data) // only one node in the list and it is the one we want to delete
    {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    node *prev = NULL;
    if (temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// reverse the list
void reverseList(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// pop the the last node

node *pop(node **head)
{
    node *temp = *head;
    node *prev = NULL;
    if (temp->next == NULL)
    {
        *head = NULL;
        return temp;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    return temp;
}

// free the  list
void freeList(node **head)
{
    node *temp = *head;
    node *next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

void test1()
{
    // generate a link list
    node *head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    reverseList(&head);
    pop(&head);
    printList(head);
    freeList(&head);
}

// Queue in C
// Queue is a FIFO data structure

// Queue node
node *enqueue(node **head, int data)
{
    insertNode(head, data);
}

// dequeue
node *dequeue(node **head)
{
    node *temp = *head;
    *head = temp->next;
    temp->next = NULL;
    return temp;
}

void queue()
{
    node *head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);
    enqueue(&head, 5);
    printList(head);
    dequeue(&head);
    printList(head);
    freeList(&head);
}
// STack as a link list
// Stack is a LIFO data structure

void stack()
{
    node *head = NULL;
    // push
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    printList(head);
    // pop
    pop(&head);
    printList(head);
    freeList(&head);
}

int main()
{
    printf(" Palying with Link list \n");
    test1();
    printf(" Palying with Queue \n");
    queue();
    printf(" Palying with Stack \n");
    stack();
    return 0;
}