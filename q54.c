#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n)
                nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int result[2 * MAX][MAX];
    int count[2 * MAX] = {0};

    int offset = MAX;

    queue[rear++] = (struct Pair){root, 0};

    int min_hd = 0, max_hd = 0;

    while (front < rear) {
        struct Pair curr = queue[front++];
        struct Node* node = curr.node;
        int hd = curr.hd;

        result[hd + offset][count[hd + offset]++] = node->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    for (int i = min_hd; i <= max_hd; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", result[i + offset][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
