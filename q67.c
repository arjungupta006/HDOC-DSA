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

void dfs(int v, struct Node* adj[], int visited[], int stack[], int *top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex])
            dfs(temp->vertex, adj, visited, stack, top);
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

int main() {
    int n, m, i, u, v;
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
    }

    int stack[n], top = -1;

    for(i = 0; i < n; i++) {
        if(!visited[i])
            dfs(i, adj, visited, stack, &top);
    }

    while(top >= 0)
        printf("%d ", stack[top--]);

    return 0;
}
