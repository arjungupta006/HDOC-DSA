#include <stdio.h>

int main() {
    int n, i, j, sum, maxLen = 0;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++) {
        sum = 0;
        for(j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0 && (j - i + 1) > maxLen)
                maxLen = j - i + 1;
        }
    }

    printf("%d", maxLen);

    return 0;
}
