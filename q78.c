#include <stdio.h>
#include <limits.h>

int minKey(int key[], int mst[], int n) {
    int min = INT_MAX, min_index, i;
    for(i = 1; i <= n; i++) {
        if(!mst[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, m, i, j, u, v, w;
    scanf("%d %d", &n, &m);

    int graph[n + 1][n + 1];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            graph[i][j] = 0;

    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[n + 1], mst[n + 1];

    for(i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for(i = 1; i <= n; i++) {
        int u = minKey(key, mst, n);
        mst[u] = 1;
        total += key[u];

        for(v = 1; v <= n; v++) {
            if(graph[u][v] && !mst[v] && graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }

    printf("%d", total);

    return 0;
}
