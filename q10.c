/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO
*/
#include <stdio.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    int left = 0;
    int right = 0;
    while (s[right] != '\0' && s[right] != '\n') {
        right++;
    }
    right--; 
    int is_palindrome = 1; 
    while (left < right) {
        if (s[left] != s[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }
    if (is_palindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    
    return 0;
}