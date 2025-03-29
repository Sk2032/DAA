#include<stdio.h>
#include<stdbool.h>
#define MAX 10

int graph[MAX][MAX], path[MAX], n;

bool isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v])
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

void hamiltonianCycle(int pos, bool *cycleFound) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]]) {
            printf("Hamiltonian Cycle: ");
            for (int i = 0; i < n; i++)
                printf("%d ", path[i]);
            printf("%d\n", path[0]);
            *cycleFound = true;
        }
        return;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamiltonianCycle(pos + 1, cycleFound);
            path[pos] = -1;
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        path[i] = -1;
    path[0] = 0;

    bool cycleFound = false;
    hamiltonianCycle(1, &cycleFound);

    if (!cycleFound) {
        printf("No Hamiltonian Cycle exists!\n");
    }

    return 0;
}

