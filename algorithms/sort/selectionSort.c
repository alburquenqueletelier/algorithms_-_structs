#include <stdio.h>
#include <stdlib.h>

/*
*   Sort the integer array by repeatedly selecting the lowest
*   value and placing it in its correct sorted position
*   @param arr: the array to be sorted
*   @param n : the size of the array
*/
void selectionSort(int *array, int size)
{
    // Break the execution if there isn't array provided or the size is negative
    if (array == NULL || size <= 0)
    {
        printf("Must provide a valid array and size.\n");
        return;
    }

    // Iterate through the array using nested loops to sort its elements in place.
    for (int i = 0; i < size - 1; i++)
    {
        // Define variables to use
        int min_value_index = i;
        int aux;

        // Second cicle for the sub array
        for (int j = i + 1; j < size; j++)
        {
            // Save the index of the min value
            if (array[j] < array[min_value_index])
            {
                min_value_index = j;
            }
        }

        // Set the element in the sorted position and replace the previous one in the element index
        aux = array[i];
        array[i] = array[min_value_index];
        array[min_value_index] = aux;
    }
}

/*
*   Print the array in terminal
*   @param arr: the array to be printed
*   @param n : the size of the array
*/
void printArray(int *arr, int n) {
    // Define pointers to the start and end of the array
    int *pointer, *end;
    pointer = arr;
    end = arr + n;

    // Print each element in the array
    while(pointer < end){
        printf("%d ", *pointer);
        *pointer++;
    }
    printf("\n");
}

int main()
{
    // Some case examples
    int arr[] = {64, 34, -25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array Original: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array Ordenado: ");
    printArray(arr, n);
    // Some case examples
    return 1;
}