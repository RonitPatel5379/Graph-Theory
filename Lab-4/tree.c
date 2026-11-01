#include<stdio.h>
#include<stdbool.h>
#define N 999
void main() {
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    int adj[v][v];
    int dist[v][v];

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges:\n");
    for(int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
        adj[w][u] = 1;
    }

    int degree[v];
    int eccentricity[v];

    printf("\nPendant Vertices:\n");
    for(int i = 0; i < v; i++) {
        degree[i] = 0;
        for(int j = 0; j < v; j++) {
            degree[i] += adj[i][j];
        }
        if(degree[i] == 1) {
            printf("%d ", i);
        }
    }

    printf("\n\nDegree of Each Vertex:\n");
    for(int i = 0; i < v; i++) {
        printf("Vertex %d = %d\n", i, degree[i]);
    } 

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j)
                dist[i][j] = 0;
            else if(adj[i][j] == 1)
                dist[i][j] = 1;
            else
                dist[i][j] = N;
        }
    }
    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nDistance Matrix:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("Eccentricity of each vertex:\n");
    int min_eccentricity = 999;
    for(int i=0;i<v;i++) {
        int max_d = 0;
        for(int j=0;j<v;j++) {
            if(dist[i][j] != 999 && dist[i][j] > max_d) {
                max_d = dist[i][j];
            }
        }
        eccentricity[i] = max_d;
        if(eccentricity[i] < min_eccentricity) {
            min_eccentricity = eccentricity[i];
        }
        printf("Vertex %d: %d\n",i,eccentricity[i]);
    }
    printf("\n");

    printf("Center of the tree:");
    for(int i=0;i<v;i++) {
        if(eccentricity[i] == min_eccentricity) {
            printf("%d ",i);
        }
    }
    printf("\n");

    bool is_connected = true;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(dist[i][j] == 999) {
                is_connected = false;
            }
        }
    }

    printf("Confirmation whether the graph is a tree:");
    if(is_connected && (e==v-1)) {
        printf("Yes,Graph is a Tree.");
    }
    else {
        printf("No,Graph is not a Tree.");
    }
}