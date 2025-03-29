#include <stdio.h>
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int dist[n][n];
    printf("Enter adjacency matrix :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  if (dist[i][k] != -1 && dist[k][j] != -1) {
                    int newDist = dist[i][k] + dist[k][j];
                    if (dist[i][j] == -1 || newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
    }
    printf("Shortest distance matrix :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
