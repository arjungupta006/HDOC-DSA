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

int main() {
    int n, m, i, u, v;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int indegree[n];

    for(i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    int queue[n], front = 0, rear = 0;

    for(i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while(temp != NULL) {
            indegree[temp->vertex]--;
            if(indegree[temp->vertex] == 0)
                queue[rear++] = temp->vertex;
            temp = temp->next;
        }
    }

    return 0;
}
