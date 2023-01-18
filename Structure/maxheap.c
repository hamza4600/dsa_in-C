// Binary search Tree
#include <stdio.h>
#include <stdlib.h>

// is a type of max heap
// name and value of the node
typedef struct node
{
    int key;
    char *value;

    struct node *left;
    struct node *right;
} node;

// create a new node
node *create_node(int key, char *value)
{
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// insert a new node into the tree
node *insert(node *root, int key, char *value)
{
    if (root == NULL)
    {
        return create_node(key, value);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key, value);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key, value);
    }
    else
    {
        root->value = value;
    }

    return root;
}

// search for a node in the tree
node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->key)
    {
        return search(root->left, key);
    }
    else if (key > root->key)
    {
        return search(root->right, key);
    }
    else
    {
        return root;
    }
}

// find the minimum node in the tree
node *find_min(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL)
    {
        return root;
    }

    return find_min(root->left);
}

// print the tree in order
void print_in_order(node *root)
{
    if (root == NULL)
    {
        return;
    }

    print_in_order(root->left);
    printf("%d: %s \n", root->key, root->value);
    print_in_order(root->right);
}

// print the tree in pre order
void print_pre_order(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d: %s \n", root->key, root->value);
    print_pre_order(root->left);
    print_pre_order(root->right);
}

// show root node
void show_root(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("root: %d: %s \n", root->key, root->value);
}

// delete a node from the tree
node *delete(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->key)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        // case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // case 2: one child
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3: two children
        else
        {
            node *temp = find_min(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = delete (root->right, temp->key);
        }
    }

    return root;
}

// free memory of the tree
void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void test()
{
    node *root = NULL;
    root = insert(root, 5, "five");
    root = insert(root, 3, "three");
    root = insert(root, 7, "seven");
    root = insert(root, 1, "one");
    root = insert(root, 4, "four");
    root = insert(root, 6, "six");
    root = insert(root, 8, "eight");

    print_in_order(root); // in sorted order
    printf(" <- Basic of Binary Search Tree -> \n");
    // print_pre_order(root);

    // root
    show_root(root);

    // serach
    printf("search for 3: %s \n", search(root, 3)->value);

    // delete
    root = delete (root, 3);
    printf("delete 3: \n");
    print_in_order(root);

    free_tree(root);
}

int main()
{
    test();
    return 0;
}