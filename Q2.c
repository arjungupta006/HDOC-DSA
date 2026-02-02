//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

//Delete an element from the desired location with user defined index in an array in C
#include <stdio.h>

int main() {
    int arr[100], size, index, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the index of the element to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return 1;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }  
    size--;
    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}