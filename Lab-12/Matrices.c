#include <stdio.h>
void main() {
    int n = 5, m = 4;
    int adj[5][5] = {0};
    int degree[5][5] = {0};
    int lap[5][5] = {0};

    int edges[4][2] = {
        {1, 2},
        {2, 3},
        {4, 5},
        {1, 5}
    };

    int i, j, u, v;

    // Construct Adjacency Matrix
    for (i = 0; i < m; i++) {
        u = edges[i][0] - 1;
        v = edges[i][1] - 1;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Construct Degree Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            degree[i][i] += adj[i][j];
        }
    }

    // Construct Laplacian Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            lap[i][j] = degree[i][j] - adj[i][j];
        }
    }

    // Print Adjacency Matrix
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    // Print Degree Matrix
    printf("\nDegree Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", degree[i][j]);
        printf("\n");
    }

    // Print Laplacian Matrix
    printf("\nLaplacian Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", lap[i][j]);
        printf("\n");
    }
}