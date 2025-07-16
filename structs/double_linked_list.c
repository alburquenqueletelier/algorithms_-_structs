#include <stdio.h>
#include <stdlib.h>

/*
* Data structure of the list
*/
typedef struct Node {
    int data;           // Value stored
    struct Node *next;  // Pointer to next Node
    struct Node *prev;  // Pointer to previous Node

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
    newNode->prev = NULL;

    // Return the new Node if there isn't an error
    if (newNode == NULL){
        printf("Memory error\n");
    }

    return newNode;
}

/*
* Insert a new Node in the beginning of the list
* @param head: Pointer to the pointer head of the list
* @param data: Integer value to be stored in the Node
*/
void insertFirst(Node **head, int data){
    // Create a new Node calling the createNode function
    Node *newNode = createNode(data);

    // If the list is empty, set the new Node as the head
    if (*head == NULL){
        *head = newNode;
        return;
    }

    // Set the new Node as the head. Then, set the next of the new Node to the old head.
    // Finally, set the previous of the old head to the new Node
    Node *tmp = *head;
    newNode->next = tmp;
    *head = newNode;
    tmp->prev = newNode;
}

/*
* Insert a new Node at the end of the list
* @param head: Pointer to the pointer head of the list
* @param data: Integer value to be stored in the Node
*/
void insertLast(Node **head, int data){
    // Create a new Node calling the createNode function
    Node *newNode = createNode(data);
    // If the list is empty, set the new Node as the head
    if (*head == NULL){
        *head = newNode;
        return;
    }

    // Get the last Node of the list
    Node *tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    // Set the next of the last Node to the new Node.
    // Then, set the previos of the new Node to the last Node. 
    // Note: when the insertion is done, the new Node is the last Node of the list
    tmp->next = newNode;
    newNode->prev = tmp;
}

/*
* Insert a new Node at a specific position in the list
* @param head: Pointer to the pointer head of the list
* @param data: Integer value to be stored in the Node
* @param position: Position where the new Node will be inserted
* @note : The position is 0-indexed
* @note : Commute the actual Node at the position to the right
*/
void insertInPosition(Node **head, int data, int position){
    // If position is <= 0, is the same as insert at the beginning
    if (position <= 0){
        insertFirst(head, data);
        return;
    }

    // Create a new Node calling the createNode function
    Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }

    // Get the node of the position.
    Node *tmp = *head;
    int count = 0;
    while (tmp->next != NULL && count < position)
    {
        tmp = tmp->next;
        count++;
    }
    // If position >= length of the list, insert at the end
    if (tmp->next == NULL && (position-count)>=1){
        insertLast(head, data);
        return;
    }

    // Set the new Node in the position
    newNode->next = tmp;
    newNode->prev = tmp->prev;
    tmp->prev->next = newNode;
    tmp->prev = newNode;
    
}

/*
* Removes the first Node of the list
* @param head: Pointer to the pointer head of the list
*/
void removeFirst(Node **head){
    // If the list is empty, do nothing
    Node *tmp = *head;
    if (tmp == NULL){
        return;
    }
    
    // Move pointer head to the next Node and delete the first Node
    *head = tmp->next;
    tmp->next->prev = NULL;
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
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    // Set the new last Node next to NULL and delete the last Node
    tmp->prev->next = NULL;
    free(tmp);
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
    // the length of the list, remove the last node
    Node *tmp = *head;
    int count = 0;
    while(tmp->next != NULL && count < position){
        tmp = tmp->next;
        count++;
    }

    // Link the previous node to the next node, then delete the node
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
}

/*
* Remove a node if match the value
* @param head: Pointer to the pointer head of the list
* @param value: Integer value to be removed
*/
void removeByValue(Node **head, int value){
    // If the list is empty, do nothing
    Node *tmp = *head;
    if (tmp == NULL){
        return;
    }

    // Iterate through the list until the value is found or reach the end
    // of the list. If the value is found, remove the node, otherwise, do nothing
    while(tmp != NULL){
        if (tmp->data == value){
            if (tmp->prev != NULL){
                tmp->prev->next = tmp->next;
            } else {
                *head = tmp->next;
            }

            if (tmp->next != NULL){
                tmp->next->prev = tmp->prev;
            }

            free(tmp);
            return;
        }
        tmp = tmp->next;
    }
}

/*
* Prints the entire list
* @param head: Pointer to the head of the list
* @param reverse: Integer Flag to print the list in reverse order.
* @note : Use reverse = 1 to print the list in reverse order
*/
void printList(Node *head, int reverse){
    // If the list is empty, print NULL
    if (head == NULL){
        printf("NULL\n");
        return ;
    }
    // Print the list as appropriate
    Node *pointer = head;
    if (reverse == 1){
        printf("NULL <-");
        while (pointer->next != NULL){
            pointer = pointer->next;
        }
        while (pointer->prev != NULL){
            printf("%i <-> ", pointer->data);
            pointer = pointer->prev;
        }
        printf("%i -> NULL\n", pointer->data);
    } else {
        printf("NULL <-");
        while (pointer->next != NULL){
            printf("%i <-> ", pointer->data);
            pointer = pointer->next;
        }
        printf("%i -> NULL\n", pointer->data);
    }
}


/*
* Free the memory allocated by the double linked list
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

    // Some example usage
    Node *head = NULL;
    printList(head, 0);
    insertFirst(&head, 5);
    insertFirst(&head, 2);
    insertLast(&head, 10);
    insertFirst(&head, 1);

    insertInPosition(&head, 3, 10);

    printList(head, 0);
    printList(head, 1);

    removeFirst(&head);
    removeLast(&head);

    printList(head, 0);
    printList(head, 1);

    removeInPosition(&head, 1);
    printList(head, 0);
    printList(head, 1);
    
    removeByValue(&head, 1);
    removeByValue(&head, 10);
    printList(head, 0);
    printList(head, 1);
    // Some example usage

    // Do not forget to free the memory allocated by the list
    freeList(head);
    return 0;
}