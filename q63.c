#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex])
            dfs(temp->vertex, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m, i, u, v, s;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int visited[n];

    for(i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    scanf("%d", &s);

    dfs(s, adj, visited);

    return 0;
}
