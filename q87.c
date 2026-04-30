#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int left = 0, right = n - 1, found = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            found = mid;
            break;
        } else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (found != -1)
        printf("%d", found);
    else
        printf("-1");

    return 0;
}