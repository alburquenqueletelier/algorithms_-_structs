#include <stdio.h>
#include <stdlib.h>

void print_search_result(int index, int target){
    if(index == -1){
        printf("Target %d not found in the array\n", target);
    } else {
        printf("Target %d found at index %d\n", target, index);
    }
}

int binary_search(int *array, int arraySize, int target, int left, int right){
    if (left > right) {
        print_search_result(-1, target);
        return -1;
    }

    int n = left + (right - left) / 2;

    if (array[n] == target){
        print_search_result(n, target);
        return n;
    }

    if (array[n] > target){
        return binary_search(array, arraySize, target, left, n - 1);
    } else {
        return binary_search(array, arraySize, target, n + 1, right);
    }

    return -1;
}

int expoential_search(int *array, int size, int target){
    if (array[0]==target){
        printf("Value %d found in index %d\n", target, 0);
        return 0;
    }
    int n=1;
    while (n < size && array[n] < target )
    {
        n*=2;
    }

    return binary_search(array, size, target, n/2, n < size ? n : size - 1);
}

int main(){

    // Some examples of uses
    int array[] = {1, 2, 3, 4, 5};
    int target = 4;
    expoential_search(array, 5, target);

    target = 1;
    expoential_search(array, 5, target);

    target = 10;
    expoential_search(array, 5, target);

    // Some examples of uses
    return 0;
}