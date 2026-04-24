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
    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex])
            dfs(temp->vertex, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m, i, u, v;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    int visited[n + 1];

    for(i = 1; i <= n; i++) {
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

    dfs(1, adj, visited);

    for(i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}
