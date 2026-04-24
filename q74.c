#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, i, j, count, max = 0;
    scanf("%d", &n);

    char names[n][100];
    for(i = 0; i < n; i++)
        scanf("%s", names[i]);

    char winner[100];

    for(i = 0; i < n; i++) {
        count = 1;
        for(j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0)
                count++;
        }

        if(count > max) {
            max = count;
            strcpy(winner, names[i]);
        } else if(count == max) {
            if(strcmp(names[i], winner) < 0)
                strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, max);

    return 0;
}
