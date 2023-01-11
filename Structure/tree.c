// Tree iN C
#include <stdio.h>
#include <stdlib.h>

// tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// create a new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert a node into the tree
void insertNode(node **root, int data)
{
    node *newNode = createNode(data);
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    node *temp = *root;
    while (temp != NULL)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

// print the tree
void printTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printf("Adress :: %p \n", root);
    printTree(root->right);
}

// delete a node from the tree
void deleteNode(node **root, int data)
{
    if (*root == NULL || root == NULL)
    {
        return;
    }
    node *temp = *root;
    node *parent = NULL;
    while (temp != NULL)
    {
        if (data < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            parent = temp;
            temp = temp->right;
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (parent->left == temp)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
                free(temp);
                return;
            }
            else if (temp->left == NULL)
            {
                if (parent->left == temp)
                {
                    parent->left = temp->right;
                }
                else
                {
                    parent->right = temp->right;
                }
                free(temp);
                return;
            }
            else if (temp->right == NULL)
            {
                if (parent->left == temp)
                {
                    parent->left = temp->left;
                }
                else
                {
                    parent->right = temp->left;
                }
                free(temp);
                return;
            }
            else
            {
                node *temp2 = temp->right;
                while (temp2->left != NULL)
                {
                    temp2 = temp2->left;
                }
                temp->data = temp2->data;
                deleteNode(&temp->right, temp2->data);
                return;
            }
        }
    }
}

// free the tree
void freeTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    node *root = NULL;
    insertNode(&root, 5);
    printf("root Adress : %p \n", root);
    printf("root->data : %d \n", root->data);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 1);
    insertNode(&root, 4);
    insertNode(&root, 6);
    insertNode(&root, 8);
    printTree(root);
    printf("\n");
    deleteNode(&root, 5);
    printTree(root);
    printf("\n");
    freeTree(root);
    return 0;
}
