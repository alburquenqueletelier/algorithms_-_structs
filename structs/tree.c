#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *son;
    struct Node *next;
}Node;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Error: cannot alloc memory\n");
        return NULL;
    }
    newNode->data = data;
    newNode->son = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBrother(Node **origen, int data){
    Node *newNode = createNode(data);
    if (newNode == NULL){
        printf("Error: cannot alloc memory\n");
        return NULL;
    }
    if (*origen == NULL){
        *origen = newNode;
        return NULL;
    }
    Node *last = *origen;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}

void insertSon(Node **origen, int data){
    Node *newNode = createNode(data);
    if (newNode == NULL){
        printf("Error: cannot alloc memory\n");
        return;
    }
    if (*origen == NULL){
        *origen = newNode;
        return;
    }
    (*origen)->son = newNode;
}


void printTreeFromLevel(Node *root, int level){
    Node *pnt = root;
    while (pnt != NULL){
        printf("Level %d: ", level);
        printf("%d ", pnt->data);
        Node *bro = pnt->next;
        while (bro != NULL)
        {
            printf("%d ", bro->data);
            bro = bro->next;
        }
        pnt = pnt->son;
        level++;
        printf("\n");
    }
}


int main(){

    // Some case use
    Node *root = createNode(1);
    insertSon(&root, 3);
    insertBrother(&root->son, 5);    

    insertSon(&root->son->son, 10);
    insertBrother(&root->son->son, 12);
    insertBrother(&root->son->son, 13);
    insertBrother(&root->son->son, 14);
    insertSon(&root->son->son->son, 20);
    insertSon(&root->son->son->son->son, 30);
    insertBrother(&root->son->son->son->son, 31);
    insertBrother(&root->son->son->son->son, 32);

    printTreeFromLevel(root, 0);
    // Some case use
    return 0;
}