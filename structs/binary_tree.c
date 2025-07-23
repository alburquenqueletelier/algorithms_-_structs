#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node **pather, int data, int left)
{
    if (left > 1 || left < 0)
    {
        printf("Invalid left value\n Use 0 for left child and 1 for right child\n");
        return;
    }

    Node *newNode = createNode(data);
    if (*pather == NULL)
    {
        *pather = newNode;
        return;
    }

    if (left == 0)
    {
        (*pather)->left = newNode;
    }
    else
    {
        (*pather)->right = newNode;
    }
}

void deleteFromNode(Node **origin)
{
    if (*origin == NULL)
    {
        return;
    }
    deleteFromNode(&(*origin)->left);
    deleteFromNode(&(*origin)->right);
    free(*origin);
    *origin = NULL;
}

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
 * RID
 * IRD
 * IDR
 */

int main()
{

    // Some case use
    Node *root = NULL;
    insertNode(&root, 5, 0);
    insertNode(&root, 2, 0);
    insertNode(&root, 1, 1);

    insertNode(&root->left, 3, 0);
    insertNode(&root->left, 4, 1);

    insertNode(&root->right, -3, 0);
    insertNode(&root->right, -4, 1);

    insertNode(&root->right->left, -5, 0);
    insertNode(&root->right->left, 10, 1);

    printPreOrder(root);
    printf("\n");
    deleteFromNode(&root->right);
    printPreOrder(root);
    printf("\n");
    // Some case use
    return 0;
}