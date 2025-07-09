#include <stdio.h>
#include <stdlib.h>

void print_search_result(int index, int target);

/*
* Return the minimum integer value between two integers.
* @param numA: The first integer.
* @param numB: The second integer.
* @return: The minimum integer value.
*/
int min(int numA, int numB) {
    return (numA > numB) ? numB : numA;
}

/*
* Fibonacci integer Search Algorithm.
* Search for an integer target within an integer array 
* @param *array : pointer to the array of integer
* @param arraySize : size of the array
* @param target : target integer to be searched
* @return : index of the target if found, -1 otherwise
*/
int fibonacci_search(int *array, int arraySize, int target){

    // Init fibonacci vars and offset
    int fib_left, fib_cen , fib_right, offset;
    fib_left = 0;
    fib_cen = 1;
    fib_right = fib_cen + fib_left;
    offset = -1;

    // Reach the first fibonacci sequence greater than the length of the array
    while(fib_right < arraySize){
        fib_left = fib_cen;
        fib_cen = fib_right;
        fib_right = fib_cen + fib_left;
    }

    // Iterate over the array using fibonacci partitions. 
    while(fib_left > 0){
        int i = min(offset+fib_left, arraySize-1);
        if(target == array[i]){
            printf("Lo encontré altiro\n");
            return i;
        }

        // If target is greater than the element, move offset (the index). 
        // Always reduce the fibonacci sequence
        if(array[i] < target){
            offset=i;
            fib_right = fib_cen;
            fib_cen = fib_left;
            fib_left = fib_right - fib_cen;
        } else {
            fib_cen = fib_cen - fib_left;
            fib_right = fib_left;
            fib_left = fib_right - fib_cen;
        }
    }

    // Check if the last pending element is the target.
    if (fib_cen == 1 && array[offset+1] == target){
        return offset+1;

    } 

    return -1;
}

/*
* Print the index of the target integer if found, -1 otherwise
* @param index : index of the target
* @param target : target integer
*/
void print_search_result(int index, int target){
    if(index == -1){
        printf("Target %d not found in the array\n", target);
    } else {
        printf("Target %d found at index %d\n", target, index);
    }
}

int main(){

    // Some examples of uses
    int array[] = {1, 2, 3, 4, 5};
    int target = 4;
    int result = fibonacci_search(array, 5, target);
    print_search_result(result, target);
    
    target = 5;
    result = fibonacci_search(array, 5, target);
    print_search_result(result, target);
    
    target = 10;
    result = fibonacci_search(array, 5, target);
    print_search_result(result, target);

    // Some examples of uses

    return 0;
}