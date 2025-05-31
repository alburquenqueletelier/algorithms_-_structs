#include <stdio.h>
#include <stdlib.h>

void print_search_result(int index, int target);

/*
* Recursive binary integer search algorithm
* @param *array : pointer to the array of integer
* @param arraySize : size of the array
* @param target : target integer to be searched
* @left : left index of the array
* @right : right index of the array
* @return : index of the target integer if found, -1 otherwise
*/
int binary_int_search(int *array, int arraySize, int target, int left, int right){

    // Find the pivot index
    int n = (left+right)/2;

    // Base condition 
    if (left >= right) {
        n = -1;
        print_search_result(n, target);
        return n;
        
    }

    // If the target is at the pivot index return index
    if (array[n] == target){
        print_search_result(n, target);

        return n;
    }

    // If the target is less than the pivot element, search in the left half
    // Otherwise, search in the right half
    if(array[n] > target){
        right = n-1;
        binary_int_search(array, n, target, left, right);
    } else {
        left = n+1;
        binary_int_search(array, n, target, left, right);
    }

}

/*  Binary search initializer
*   @param *array : pointer to the array of integer
*   @param arraySize : size of the array
*   @param target : target integer to be searched
*   @return binary_int_search (array, arraySize, target, 0, arraySize-1)
*/
int binary_search(int *array, int arraySize, int target){
    // Call the binary_int_search function with the initial parameters
    int response = binary_int_search(array, arraySize, target, 0, arraySize - 1);
}

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
    int result = binary_search(array, 5, target);

    target = 1;
    result = binary_search(array, 5, target);

    target = 10;
    result = binary_search(array, 5, target);

    // Some examples of uses

    return 0;
}