#include <stdio.h>
void bellmanFord(int n, int edges[][3], int e, int src) {
    int distance[n], previous[n];
    for (int i = 0; i < n; i++) {
        distance[i] = 99999;
                previous[i] = -1;
    }
    distance[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (distance[u] != 99999 && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
            }
        }
    }
    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (distance[u] != 99999 && distance[u] + weight < distance[v]) {
            printf("Error: Negative cycle exists!\n");
            return;
        }
    }
    printf("Vertex  Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, distance[i]);
}
void main() {
    int n, e, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    int edges[e][3];
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);

    printf("Enter source vertex: ");
    scanf("%d", &src);
    bellmanFord(n, edges, e, src);
}
