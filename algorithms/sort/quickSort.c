
/**
 * quickSort.c
 * Implementation of the Quick Sort algorithm in C.
 *
 * This script demonstrates the divide-and-conquer sorting technique using quick sort.
 * Functions:
 *   - sortPartition: Partitions the array around a pivot for quick sort.
 *   - quickSort: Recursively sorts an array using quick sort.
 *   - randArray: Generates a random unique integer array.
 *   - printArray: Utility to print the contents of an array.
 *   - main: Example usage of quick sort.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Partitions the array around a pivot for quick sort.
 * Elements less than the pivot are moved to the left, greater to the right.
 *
 * @param array Pointer to the array to partition
 * @param left Left index of the subarray
 * @param right Right index of the subarray
 * @return The partition index for further sorting
 */
int sortPartition(int* array, int left, int right) {
    int pivot = array[left + (right - left) / 2]; 
    int left_index = left;
    int right_index = right;
    int aux;

    while (left_index <= right_index) {
        while (array[left_index] < pivot) left_index++;
        while (array[right_index] > pivot) right_index--;

        if (left_index <= right_index) {
            aux = array[right_index];
            array[right_index] = array[left_index];
            array[left_index] = aux;
            left_index++;
            right_index--;
        }
    }

    return left_index; 
}

/**
 * Recursively sorts the array using the quick sort algorithm.
 *
 * @param array Pointer to the array to be sorted
 * @param left Left index of the subarray to sort
 * @param right Right index of the subarray to sort
 */
void quickSort(int* array, int left, int right) {
    if (left < right) {
        int pivot = sortPartition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot, right);
    }
}


/**
 * Generate random unique integer array [0, size]
 * @param size Number of elements
 * @return pointer to the first element of the array
 */
int *randArray(int size)
{
    int count=0;
    int random_int;
    int max_size = 1000;

    if (size < 0 || size > max_size)
    {
        printf("Error: size must be in range of [0,max_size;]");
        return NULL;
    }


    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Error: memory not allocated");
        return NULL;
    }

    bool *used = (bool *)calloc(size, sizeof(bool));
    if (used == NULL)
    {
        printf("Error: memory not allocated");
        free(array);
        return NULL;
    }

    while(count < size){
        random_int = rand() % size;
        if(!used[random_int]){
            array[count] = random_int;
            used[random_int] = true;
            count++;
        }
    }

    free(used);
    return array;
}

/**
 * Prints the elements of an integer array.
 *
 * @param array Pointer to the array to print
 * @param size Number of elements in the array
 */
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            printf("%d, ", array[i]);
        }
        else
        {
            printf("%d\n", array[i]);
        }
    }
}


/**
 * Main function demonstrating the use of quick sort.
 * Creates an example array, prints it before and after sorting.
 */
int main(){
    // Some use case
    int *arr = randArray(50);    
    printf("Before sort: \n");
    printArray(arr, 50);

    quickSort(arr,0,50-1);
    printf("After sort:\n");
    printArray(arr, 50);

    free(arr);
    arr = NULL;

    // Some use case
    return 0;
}