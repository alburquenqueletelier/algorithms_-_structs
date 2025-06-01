#include <stdio.h>

/*
*   Sort an array of integer in ascending order
*   @param arr: the array to be sorted
*   @param n: the size of the array
*/
void insertionSort(int *arr, int n) {
    // Define variables to iterate and swap
   int i, j, key;

   // Iterate through the array starting from the second element
   for (i = 1; i<n; i++){
    key = arr[i];

    // Initialize j to the previous element
    j = i-1;

    // Swap elements until the key is in the correct position
    while(j>=0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }

    // Insert the key at the correct position
    arr[j+1] = key;
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

int main() {
    // Some example of use
    int arr[] = {64, 34, -25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *pointer = arr;
    int *end = arr + n;
    printf("Array Original: ");
    printArray(arr, n);

    insertionSort(arr, n);
    
    printf("Array Ordenado: ");
    printArray(arr, n);
    // Some example of use
    return 0;
}
