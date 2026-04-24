#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, i, j, s;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    for(i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &s);

    int dist[n];
    for(i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[s] = 0;

    for(i = 1; i < n; i++) {
        for(j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    for(i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
