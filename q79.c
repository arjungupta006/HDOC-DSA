#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->w = w;
    n->next = NULL;
    return n;
}

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct HeapNode* arr;
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if(l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if(r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if(smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

struct HeapNode extractMin(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify(h, 0);
    return root;
}

void insertHeap(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = dist;

    while(i && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    int n, m, i, u, v, w, s;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    for(i = 1; i <= n; i++)
        adj[i] = NULL;

    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        struct Node* n1 = createNode(v, w);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node* n2 = createNode(u, w);
        n2->next = adj[v];
        adj[v] = n2;
    }

    scanf("%d", &s);

    int dist[n + 1];
    for(i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap* h = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    h->size = 0;
    h->arr = (struct HeapNode*)malloc((n+1) * sizeof(struct HeapNode));

    dist[s] = 0;
    insertHeap(h, s, 0);

    while(h->size > 0) {
        struct HeapNode min = extractMin(h);
        int u = min.v;

        struct Node* temp = adj[u];
        while(temp != NULL) {
            v = temp->v;
            w = temp->w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for(i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}
