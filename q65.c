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

int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp != NULL) {
        int u = temp->vertex;

        if(!visited[u]) {
            if(dfs(u, v, adj, visited))
                return 1;
        } else if(u != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
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

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int hasCycle = 0;

    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adj, visited)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}
