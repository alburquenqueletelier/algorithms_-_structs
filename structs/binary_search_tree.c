#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/**
 * Create a new node with the given data.
 * @param data The data to be stored in the new node.
 */
Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error: Memory not allocated.\n");
        return NULL;
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int findMinValue(Node *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty.\n");
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int findMaxValue(Node *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty.\n");
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

void insertNode(Node **root, int value)
{
    Node *new_node = createNode(value);
    if (*root == NULL)
    {
        (*root) = new_node;
        return;
    }

    Node *pnt = *root;
    while (1)
    {
        if (pnt->data < value && pnt->right != NULL)
        {
            pnt = pnt->right;
        }
        else if (pnt->data > value && pnt->left != NULL)
        {
            pnt = pnt->left;
        }
        else if (pnt->data == value)
        {
            printf("Error: Node already exists.\n");
            return;
        }
        else
        {
            break;
        }
    }

    if (pnt->data > value)
    {
        pnt->left = new_node;
    }
    else
    {
        pnt->right = new_node;
    }
}

/**
 * Delete a node from the binary search tree by its value.
 * @param root Double pointer to the root of the binary search tree.
 * @param target The value of the node to be deleted.
 * @param flag Indicate if the message should be printed or not. 1 for print, 0 for not print.
 */
void deleteNodeByValueAlgorithm(Node **root, int target, int flag)
{
    // If tree is empty
    if (*root == NULL)
    {
        printf("Error: There isn't any node to delete.\n");
        return;
    }

    // If the target value is found
    if ((*root)->data == target)
    {
        Node *temp = (*root);
        // Case Leaf Node or One Child Node
        if ((*root)->left == NULL)
        {
            (*root) = (*root)->right;
            free(temp);
            if (flag == 1)
            {
                printf("The node with value %d has been deleted.\n", target);
            }
        }
        else if ((*root)->right == NULL)
        {
            (*root) = (*root)->left;
            free(temp);
            if (flag == 1)
            {
                printf("The node with value %d has been deleted.\n", target);
            }
        }
        // Case 2 child
        else
        {
            // Iterating to find the node with the minimum value of right subtree
            Node *pnt = (*root)->right;
            while (pnt->left != NULL)
            {
                pnt = pnt->left;
            }
            // Replace the value only
            (*root)->data = pnt->data;
            // Delete the node with the minimum value of right subtree
            if (flag == 1)
            {
                printf("The node with value %d has been deleted.\n", target);
            }
            deleteNodeByValueAlgorithm(&((*root)->right), pnt->data, 0);
        }
    }
    else if ((*root)->data < target)
    {
        deleteNodeByValueAlgorithm(&((*root)->right), target, 1);
    }
    else
    {
        deleteNodeByValueAlgorithm(&((*root)->left), target, 1);
    }
}

/**
 * Wrapper function to delete a node by value from a binary tree.
 * @param root Pointer to the root node of the binary tree.
 * @param target Value of the node to be deleted.
 */
void deleteNodeByValue(Node **root, int target)
{
    deleteNodeByValueAlgorithm(root, target, 1);
}


/**
 * RID
 */
void printPreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

/**
 * IRD
 */
void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

/**
 * IDR
 */
void printPostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

/*
 * Free the memory allocated by the linked list
 * @param head: Pointer to the head of the list
 */
void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
    root = NULL;
}

int main()
{
    // some case uses
    Node *root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 3);

    printPreOrder(root);
    printf("\n");

    printInOrder(root);
    printf("\n");

    printPostOrder(root);
    printf("\n");

    deleteNodeByValue(&root, 10);
    printInOrder(root);
    printf("\n");

    deleteNodeByValue(&root, findMinValue(root));
    printInOrder(root);
    printf("\n");

    deleteNodeByValue(&root, findMaxValue(root));
    printInOrder(root);
    printf("\n");

    freeTree(root);
    // some case uses
    return 0;
}