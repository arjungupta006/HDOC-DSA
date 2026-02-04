/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"
*/
#include <stdio.h>

int main() {
    int arr[100], size, key, comparisons = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}