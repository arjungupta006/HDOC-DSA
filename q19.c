/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }   
    int closest_sum = arr[0] + arr[1];
    int num1 = arr[0], num2 = arr[1];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(closest_sum)) {
                closest_sum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }
    printf("%d %d", num1, num2);
    
    return 0;
}