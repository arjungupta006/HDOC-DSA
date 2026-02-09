/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh*/
#include <stdio.h>
#include <string.h>
            
int main() {
    char code_name[100];
    fgets(code_name, sizeof(code_name), stdin);
    
    int length = strlen(code_name);
    if (length > 0 && code_name[length - 1] == '\n') {
        code_name[length - 1] = '\0';
        length--;
    }
    
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", code_name[i]);
    }
    printf("\n");
    
    return 0;
}