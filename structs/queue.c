#include <stdio.h>
#include <stdlib.h>



/*
* Structure of a integer node in a Stack
*/
typedef struct Node{
    int value;
    struct Node *next, *prev;
} Node;

/*
*  Struct of the queue
*/
typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

/*
*   Create a Node
*   @param value: The integer value to be stored
*   @return : A pointer to the newly created Node
*/
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    // Return the new Node if there isn't an error
    if (newNode == NULL)
    {
        printf("Memory error: Unable to allocate memory\n");
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Queue *createQueue(){
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void enqueue(Queue **queue, int value){
    Node *newNode = createNode(value);
    if (newNode == NULL){
        printf("Memory error: Unable to allocate memory\n");
        return;
    }

    if ((*queue)->front == NULL || (*queue)->rear == NULL){
        (*queue)->front = newNode;
        (*queue)->rear = newNode;
        return;
    }

    (*queue)->rear->next = newNode;
    newNode->prev = (*queue)->rear;
    (*queue)->rear = newNode;
}

void dequeue(Queue **queue){
    if ((*queue) == NULL || (*queue)->front == NULL){
        printf("Error: Queue is empty\n");
        return;
    }

    if ((*queue)->front->next == NULL){
        (*queue)->front = NULL;
        (*queue)->rear = NULL;
        printf("The queue is now empty\n");
        return;
    }

    Node *tmp = (*queue)->front;
    (*queue)->front = (*queue)->front->next;
    (*queue)->front->prev = NULL;
    free(tmp);
}

/*
* Prints the queue
* @param *queue: Pointer to the queue
* @param inOrder: 0 for backward, 1 for forward
*/
void printList(Queue *queue, int inOrder){
    if (inOrder != 0 && inOrder != 1){
        printf("inOrder only takes values 0 or 1");
        return;
    }
    // If the list is empty, print NULL
    if (queue == NULL){
        printf("The queue is empty\n");
        return ;
    }
    
    // Print the list as appropriate
    Node *pointer;
    if (inOrder == 1){
        pointer = queue->front;
        printf("Init ");
        while(pointer != NULL){
            printf("%d <-> ", pointer->value);
            pointer = pointer->next;
        }
        printf("End \n");
    }else{
        pointer = queue->rear;
        printf("End ");
        while (pointer != NULL)
        {
            printf("%d <-> ", pointer->value);
            pointer = pointer->prev;
        }
        printf("Init \n");
    } 
}

/*
* Free the memory allocated by the linked list
* @param head: Pointer to the head of the list
*/
void freeList(Node *head){
    Node *tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }

}

int main(){
    // Some case use
    Queue *queue = createQueue();
    enqueue(&queue, 5);
    enqueue(&queue, 2);
    enqueue(&queue, 4);

    printList(queue, 0);
    printList(queue, 1);

    dequeue(&queue);

    printList(queue, 1);

    freeList(queue->front);
    free(queue);
    // Some case use
    return 0;
}