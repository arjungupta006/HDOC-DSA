/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation*/
#include <stdio.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    int length = 0;
    while (s[length] != '\0' && s[length] != '\n') {
        length++;
    }
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
                 
    return 0;
}