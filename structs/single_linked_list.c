#include <stdio.h>
#include <stdlib.h>

// Estructura de datos para un nodo de la lista
typedef struct Node
{
    int value;          // Valor del nodo
    struct Node* next;  // Puntero al siguiente nodo
} Node;

/*
 * Insertar un nodo al comienzo de la lista.
 * @param **head Doble puntero al primer nodo de la lista.
 * @param data Valor entero a insertar en el nodo.
 */
void insertFirst (Node **head, int data){
    // Se crea el nuevo nodo
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;

    Node *tmp = *head;
    // Si tmp es NULL entonces la lista está vacía
    // Caso contrario se asgina el nodo al comienzo
    if (tmp == NULL){
        newNode->next = NULL;
        *head = newNode;
    } else {
        newNode->next = tmp;
        *head = newNode;
    }
}

/*
 * Insertar un nodo al final de la lista.
 * @param **head Doble puntero al primer nodo de la lista.
 * @param data Valor entero a insertar en el nodo.
 */
void insertLast (Node **head, int data){
    // Se crea el nuevo nodo
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;

    // Puntero para recorrer la lista
    Node *pointer = *head;

    // Si lista vacía entonces se asigna el nuevo nodo
    if (pointer == NULL){
        *head = newNode;
        return;
    }

    // Se recorre la lista hasta el último nodo
    // y se asgina el nuevo nodo al final
    while (pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = newNode;
}

/*
 * Insertar un nodo en la posición deseada.
 * Desplaza al nodo que está en esa posición hacia la derecha.
 * @param **head Doble puntero al primer nodo de la lista.
 * @param data Valor entero a insertar en el nodo.
 * @param position Posición en la que se insertará el nuevo nodo. 
 * Si es <= 0 se insertará en el comienzo. 
 * Si es >= al tamaño de la lista se insertará al final.
 */
void insertInPosition(Node **head, int data, int position){
    
    Node *pointer = *head;
    // Si position es menor o igual a 0, o head es NULL entonces se asigna el nuevo nodo al comienzo
    if (position <= 0 || pointer == NULL){
        insertFirst(head, data);
        return;

    }
    // Se crea el nuevo nodo
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;

    // Se busca el nodo previo a la position donde se desea insertar el nuevo nodo
    int index = 1;
    while(index < position && pointer->next != NULL){
        pointer = pointer->next;
        index+=1;
    }

    // Se reemplaza el nodo de la position deseada por el nuevo nodo, y este se enlaza al nodo siguiente
    // que vendría siendo el que estaba antes en la posición que usa.
    Node *tmp = pointer->next;
    pointer->next = newNode;
    newNode->next = tmp;
}

/*
 * Imprime en consola los valores de los nodos de la lista en el rango deseado.
 * @param **head Doble puntero al primer nodo de la lista.
 * @param init Posición inicial del rango. 
 * Si es <= 0 se imprime desde el comienzo.
 * Si es >= al tamaño de la lista se imprime el último nodo.
 * @param end Posición final del rango.
 * Debe ser >= que init. Si end >= largo de la lista se imprime hasta el final.
 */
void printList(Node *head, int init, int end){

    if (end < init){
        printf("Error: El rango de impresión es inválido.\n");
        return;
    }
    // Se asigna puntero para recorrer lista y un índice
    Node *pointer = head;
    int index = 0;

    // Se alcanza el nodo desde el cual se quiere comenzar a imprimir los datos
    while(index < init && pointer->next != NULL){
        pointer = pointer->next;
        index++;
    }

    // Se recorre la lista desde el nodo incial definido hasta el nodo deseado o el final de la lista
    while (index < end && pointer != NULL)
    {
        printf("%i -> ",pointer->value);
        pointer = pointer->next;
        index++;
    }

    printf("NULL\n");
    
}


int main (){
    
    // Ejemplo de consumo
    Node *head = NULL;
    insertInPosition(&head, 5, 1);
    insertFirst(&head, 1);
    insertFirst(&head, 2);

    insertLast(&head, 3);

    insertInPosition(&head, 6, -10);

    printList(head, 0, 10);
    free(head);
    return 0;
}