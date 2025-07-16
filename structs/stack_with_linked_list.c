#include <stdio.h>
#include <stdlib.h>

/*
 * Structure of a integer node in a Stack
 */
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

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
    return newNode;
}

/*
*   Add a new Node to the top of the Stack
*   If the head is null, it will be the first Node
*   @param **head : A double pointer to the head of the Stack
*   @param value : The integer value
*/
void push(Node **head, int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL){
        printf("Push Failed: Unable to create new Node\n");
        return;
    }

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

/*
*   Remove the top Node from the Stack
*   @param **head : A double pointer to the head of the Stack
*/
void pop(Node **head)
{
    if (*head == NULL)
    {
        printf("There isn't a stack \n");
        return;
    }

    Node *tmp = *head;
    (*head) = tmp->next;
    free(tmp);
}

/*
* Prints the stack until reach the level or the end
* @param head: Pointer to the head of the list
* @param reverse: Integer Flag to print the list in reverse order.
* @note : Use reverse = 1 to print the list in reverse order
*/
void printList(Node *head){
    // If the list is empty, print NULL
    if (head == NULL){
        printf("NULL\n");
        return ;
    }
    // Print the list as appropriate
    Node *pointer = head;
    while (pointer != NULL)
    {
        printf("%d -> ", pointer->value);
        pointer = pointer->next;
    }
    printf("NULL\n");
    
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

int main()
{
    
    // Some use case
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, -4);
    push(&head, 10);

    printList(head);

    pop(&head);
    pop(&head);

    printList(head);

    freeList(head);
    // Some use case
    return 0;
}