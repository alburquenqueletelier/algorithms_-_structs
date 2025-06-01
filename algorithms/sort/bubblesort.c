#include <stdio.h>

/*
*   Sort an array of integer in ascending order
*   @param arr: the array to be sorted
*   @param n: the size of the array
*/
void bubbleSort(int *arr, int n) {
    // Iterate through the array twice
    // The first cicle sorts the largest element to the end
    // The second cicle repeat the process until the array is sorted
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            // If the current element is greater than the next one, swap them
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Some example of use
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *pointer = arr;
    int *end = arr + n;
    printf("Array Original: ");
    while(pointer < end){
        printf("%d ", *pointer);
        *pointer++;
    }

    bubbleSort(arr, n);
    
    printf("\nArray Ordenado: ");
    pointer = arr;
    while(pointer < end){
        printf("%d ", *pointer);
        *pointer++;
    }
    printf("\n");
    // Some example of use
    return 0;
}
