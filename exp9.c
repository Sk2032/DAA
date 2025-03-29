#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], path[MAX], n;

int isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v])
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int hamiltonianCycle(int pos) {
    if (pos == n)
        return graph[path[pos - 1]][path[0]];

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamiltonianCycle(pos + 1))
                return 1;
            path[pos] = -1;
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

    for (int i = 0; i < n; i++)
        path[i] = -1;
    path[0] = 0;

    if (hamiltonianCycle(1)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);
    } else
        printf("No Hamiltonian Cycle exists!\n");
}
