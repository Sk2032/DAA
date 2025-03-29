#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], colors[MAX], n, m;
int isSafe(int node, int c) {
    for (int i = 0; i < n; i++)
        if (graph[node][i] && colors[i] == c)
            return 0;
    return 1;
}

int graphColoring(int node) {
    if (node == n) {
        printf("Solution: ");
        for (int i = 0; i < n; i++)
            printf("%d ", colors[i]);
        printf("\n");
        return 1;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c)) {
            colors[node] = c;
            if (graphColoring(node + 1))
                return 1;
            colors[node] = 0;
        }
    }
    return 0;
}

void main() {
    printf("Enter no of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter no of colors: ");
    scanf("%d", &m);

    if (!graphColoring(0))
        printf("No solution exists!\n");
}
