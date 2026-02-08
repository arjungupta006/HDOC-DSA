/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b
*/
#include <stdio.h>

int main() {
    
    int a, b;
    scanf("%d %d", &a, &b);
    int result = 1; 
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    printf("%d\n", result);

}