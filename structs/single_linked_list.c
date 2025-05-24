#include <stdio.h>
#include <stdlib.h>

/*
* Data structure of the list
*/
typedef struct Node
{
    int data;           // Value stored
    struct Node* next;  // Pointer to next Node
} Node;

/*
* Create a new Node and return it
* @param data: Integer value to be stored in the Node
* @return Node*: Pointer to the pointer new Node
*/
Node* createNode(int data){
    // Allocate memory for the new Node
    Node *newNode = (Node*)malloc(sizeof(Node));
    // Set the data of the new Node
    newNode->data = data;
    newNode->next = NULL;

    // Return the new Node if there isn't an error
    if (newNode == NULL){
        printf("Memory error\n");
    }

    return newNode;
}

/*
 * Inserts a node at the beginning of the list.
 * @param **head Double pointer to the first node of the list.
 * @param data Integer value to insert into the node.
 */
void insertFirst (Node **head, int data){
    // Create a new node
    Node *newNode = createNode(data);

    // If the list is empty, set the new node as the head
    // Otherwise , set the new node as the head and set the current head as the next node
    Node *tmp = *head;
    if (tmp == NULL){
        newNode->next = NULL;
        *head = newNode;
    } else {
        newNode->next = tmp;
        *head = newNode;
    }
}

/*
 * Inserts a node at the end of the list.
 * @param **head Double pointer to the first node of the list.
 * @param data Integer value to insert into the node.
 */
void insertLast (Node **head, int data){
    // Create a new node
    Node *newNode = createNode(data);

    
    // If the list is empty, set the new node as the head
    Node *pointer = *head;
    if (pointer == NULL){
        *head = newNode;
        return;
    }

    // Get the last node and set its next node as the new node
    while (pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = newNode;
}

/*
 * Inserts a node at the desired position.
 * Shifts the node currently at that position to the right.
 * @param **head Double pointer to the first node of the list.
 * @param data Integer value to insert into the node.
 * @param position Position where the new node will be inserted.
 * @note : If position <= 0, it will be inserted at the beginning.
 * @note : If position >= the list size, it will be inserted at the end.
 */
void insertInPosition(Node **head, int data, int position){
    
    Node *pointer = *head;
    // If position is less than or equal to 0, or head is NULL, 
    // then the new node is assigned to the beginning.
    if (position <= 0 || pointer == NULL){
        insertFirst(head, data);
        return;

    }
    // Create a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // Find the node before the desired position
    int index = 1;
    while(index < position && pointer->next != NULL){
        pointer = pointer->next;
        index+=1;
    }

    // The node at the desired position is replaced by the new node, 
    // and this new node is linked to the next node, which was
    // previously at that position.
    Node *tmp = pointer->next;
    pointer->next = newNode;
    newNode->next = tmp;
}

/*
* Deletes the first node of the list
* @param **head Double pointer to the first node of the list
*/
void removeFirst(Node **head){
    // If the list is empty, do nothing
    Node *tmp = *head;
    if (tmp == NULL){
        return;
    }
    
    // Move pointer head to the next Node and delete the first Node
    *head = tmp->next;
    free(tmp);
}

/*
* Removes the last node from the list.
* @param head: Pointer to the pointer head of the list
*/
void removeLast(Node **head){
    // If the list is empty, do nothing
    Node *tmp = *head;
    if (tmp == NULL){
        return;
    }

    // Get the last Node
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }

    // Remove the last Node
    Node *nodeToDelete = tmp->next;
    tmp->next = NULL;
    free(nodeToDelete);
}

/*
* Remove a node by its position
* @param head: Pointer to the pointer head of the list
* @param position: Position of the node to be removed
* @note : The position is 0-indexed
* @note : Position <= 0 will remove the first node
* @note : Position >= length of the list will remove the last node
*/
void removeInPosition(Node **head, int position){
    // If the list is empty, do nothing
    if (*head == NULL){
        return;
    }

    // Remove the first node if position is 0 or less
    if (position <= 0){
        removeFirst(head);
        return;
    }

    // Get the node at the position. If the position is greater than
    // the length of the list, reach the end of the list
    Node *tmp = *head;
    int count = 1;
    while(tmp->next != NULL && count < position){
        tmp = tmp->next;
        count++;
    }

    // If tmp reach the end of the list, call removeLast
    // Otherwise, remove the node at the position
    if (tmp->next != NULL){
        Node *nodeToDelete = tmp->next;
        tmp->next = tmp->next->next;
        free(nodeToDelete);
    } else {
        removeLast(head);
    }
}

/*
* Remove a node if match the data
* @param head: Pointer to the pointer head of the list
* @param data: Integer data to be removed
*/
void removeByValue(Node **head, int data){
    // If the list is empty, do nothing
    Node *tmp = *head;
    if (tmp == NULL){
        return;
    }

    if (tmp->data == data){
        removeFirst(head);
        return;
    }

    // Iterate through the list until the data is found or reach the end
    // of the list. If the data is found, remove the node, otherwise, do nothing
    while(tmp->next != NULL){
        if (tmp->next->data == data){

            Node *aux = tmp->next;
            tmp->next = tmp->next->next;
            free(aux);
            return;
        }
        tmp = tmp->next;
    }
}

/*
 * Prints the values of the list nodes within the desired range to the console.
 * @param **head Double pointer to the first node of the list.
 * @param init Starting position of the range.
 * If <= 0, printing starts from the beginning.
 * If >= the list size, only the last node is printed.
 * @param end Ending position of the range.
 * Must be >= init. If end >= list length, printing continues to the end.
 */
void printList(Node *head, int init, int end){

    // If the range is invalid, print message error and do nothing
    if (end < init){
        printf("Error: El rango de impresión es inválido.\n");
        return;
    }

    // Itarate through the list until reach the init position
    Node *pointer = head;
    int index = 0;
    while(index < init && pointer->next != NULL){
        pointer = pointer->next;
        index++;
    }

    // Print the values of the list until reach the end position
    while (index < end && pointer != NULL)
    {
        printf("%i -> ",pointer->data);
        pointer = pointer->next;
        index++;
    }

    printf("NULL\n");
    
}

/*
 * Frees memory space used by the list nodes.
 * @param *head Pointer to the first node.
*/
void freeList(Node *head){
    Node *tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}


int main (){
    
    // Some example usage
    Node *head = NULL;
    insertInPosition(&head, 5, 1);
    insertFirst(&head, 1);
    insertFirst(&head, 2);

    insertLast(&head, 3);

    insertInPosition(&head, 6, -10);

    printList(head, 0, 10);

    removeFirst(&head);
    printList(head, 0, 10);
    
    removeLast(&head);
    printList(head, 0, 10);

    removeInPosition(&head, 1);
    printList(head, 0, 10);

    removeByValue(&head, 5);
    printList(head, 0, 10);
    // Some example usage

    // Do not forget to free the memory allocated by the list
    freeList(head);

    return 0;
}