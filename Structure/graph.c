// Graphs in c 
// Two Methods to represent graphs 
// 1. Adjacency Matrix
// 2 linked list 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Adjacency Matrix
// 1. Create a 2D array of size V*V
// 2. Initialize all elements to 0

#define size 10

void matrix() {
    // fille the matrix with 0
    int adj[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[j][i] = rand() % 1000; // add random number
        }
    }
  
    // show the matrix
    for (int i = 0; i < size; i++) {
            printf("%d ", i);
        for (int j = 0; j < size; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // show repeated numbers
    bool repeated = false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (adj[i][j] == adj[j][i] && i != j) {
                repeated = true;
                printf("Repeated number: %d \n", adj[i][j]);
            }
        }
    }
    if (!repeated) {
        printf("No repeated numbers \n");
    }
};

// Linked List Resentation of Graphs
// 1. Create a node for each vertex
// 2. Create a list for each vertex
// 3. Add the node to the list of each vertex

typedef struct nodetype {
    int info;
    struct nodetype *point;
    struct nodetype *next;
} nodetype;

typedef struct nodetype *node;

node createNode(int info) {
    node temp;
    temp = (node) malloc(sizeof(struct nodetype));
    temp->info = info;
    temp->point = NULL; // act as a vertex
    temp->next = NULL; // act as a list
    return temp;
}

void addNode(node *head, int info) {
    node temp, p;
    temp = createNode(info);
    if (*head == NULL) {
        *head = temp;
    } else {
        p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

// delete a node
void deleteNode(node *head, int info) {
    node p, q;
    p = *head;
    if (p->info == info) {
        *head = p->next;
        free(p);
    } else {
        while (p->next != NULL) {
            if (p->next->info == info) {
                q = p->next;
                p->next = q->next;
                free(q);
                break;
            }
            p = p->next;
        }
    }
}

// search a node
bool searchNode(node head, int info) {
    node p;
    p = head;
    while (p != NULL) {
        if (p->info == info) {
            return true;
        }
        p = p->next;
    }
    return false;
}


void printList(node head) {
    node p;
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->info);
        printf("%p -> ", p->next);
        p = p->next;
    }
    printf("\n");
}

// free the memory
void freeMemory(node *head) {
    node p, q;
    for (int i = 0; i < size; i++) {
        p = head[i];
        while (p != NULL) {
            q = p;
            p = p->next;
            free(q);
        }
    }
}

void graph() {
    node head[size];
    for (int i = 0; i < size; i++) {
        head[i] = NULL;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            addNode(&head[i], rand() % 1000);
        }
    }
    printList(head[0]);

    // search a node
    if (searchNode(head[0], 383)) {
        printf("Found \n");
    } else {
        printf("Not Found \n");
    }

    // delete a node
    deleteNode(&head[0], 383);
    printList(head[0]);
    
    // free the memory
    freeMemory(head);
}



int main()
{
    // matrix();
    graph();

    return 0;
}
