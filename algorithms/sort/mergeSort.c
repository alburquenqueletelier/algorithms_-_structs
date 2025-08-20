
/**
 * mergeSort.c
 * Implementation of the Merge Sort algorithm in C.
 *
 * This script demonstrates the divide-and-conquer sorting technique using merge sort.
 * Functions:
 *   - merge: Merges two sorted subarrays into a single sorted array.
 *   - mergeSort: Recursively sorts an array using merge sort.
 *   - printArray: Utility to print the contents of an array.
 *   - main: Example usage of merge sort.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Merges two sorted subarrays of array[] into a single sorted subarray.
 * The first subarray is array[left..middle]
 * The second subarray is array[middle+1..right]
 *
 * @param array Pointer to the array to be sorted
 * @param left Left index of the subarray
 * @param middle Middle index, separating the two subarrays
 * @param right Right index of the subarray
 */
void merge(int *array, int left, int middle, int right)
{

    int i, j, k;
    int size_left = middle - left + 1;
    int size_right = right - middle;

    // Create temp arrays
    int L[size_left], R[size_right];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < size_left; i++)
        L[i] = array[left + i];
    for (j = 0; j < size_right; j++)
        R[j] = array[middle + 1 + j];

    // Merge the temp arrays back into array[left..right
    i = 0;
    j = 0;
    k = left;
    while (i < size_left && j < size_right)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elemiddleents of L[],
    // if there are any
    while (i < size_left)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remiddleaining elemiddleents of R[],
    // if there are any
    while (j < size_right)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Recursively sorts the array using the merge sort algorithm.
 *
 * @param array Pointer to the array to be sorted
 * @param left Left index of the subarray to sort
 * @param right Right index of the subarray to sort
 */
void mergeSort(int *array, int left, int right)
{
    if (array == NULL)
    {
        printf("There isn't any array of integers");
        return;
    }

    if (right > left)
    {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
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

int main()
{

    // Some case use
    int size = 50;
    int *arr = randArray(size);
    printf("Before sort: \n");
    printArray(arr, size);
    mergeSort(arr, 0, size-1);
    printf("After sort: \n");
    printArray(arr, size);
    free(arr);
    arr=NULL;
    // Some case use

    return 0;
}