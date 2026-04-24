#include <stdio.h>
#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

int getMinIndex() {
    if (size == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIdx])
            minIdx = i;
    }
    return minIdx;
}

int deleteMin() {
    if (size == 0) return -1;
    int idx = getMinIndex();
    int val = pq[idx];
    for (int i = idx; i < size - 1; i++)
        pq[i] = pq[i + 1];
    size--;
    return val;
}

int peek() {
    if (size == 0) return -1;
    int idx = getMinIndex();
    return pq[idx];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } 
        else if (op[0] == 'd') {
            printf("%d\n", deleteMin());
        } 
        else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }

    return 0;
}
