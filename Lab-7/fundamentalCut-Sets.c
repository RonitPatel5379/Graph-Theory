#include <stdio.h>
void main() {
    int n, e;
    int u[20], v[20];
    int branch;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter all edges:\n");
    for(int i = 0; i < e; i++) {
        scanf("%d%d", &u[i], &v[i]);
    } 

    printf("Enter number of branches (Spanning Tree Edges): ");
    scanf("%d", &branch);

    printf("\nFundamental Cut-Sets:\n");

    for(int i = 0; i < branch; i++) {
        printf("Cut-Set %d: ", i + 1);
        printf("(%d,%d) ", u[i], v[i]);
        for(int j = branch; j < e; j++) {
            printf("(%d,%d) ", u[j], v[j]);
        }
        printf("\n");
    }
}

// #include <stdio.h>

// int main()
// {
//     int n, e, i, j;
//     int graph[10][10] = {0};
//     int degree[10] = {0};
//     int u, v, min = 100;

//     printf("Enter number of vertices: ");
//     scanf("%d", &n);

//     printf("Enter number of edges: ");
//     scanf("%d", &e);

//     printf("Enter edges (u v):\n");
//     for(i = 0; i < e; i++)
//     {
//         scanf("%d%d", &u, &v);
//         graph[u][v] = 1;
//         graph[v][u] = 1;
//         degree[u]++;
//         degree[v]++;
//     }

//     // Find minimum degree
//     for(i = 0; i < n; i++)
//     {
//         if(degree[i] < min)
//             min = degree[i];
//     }

//     printf("\nVertex Connectivity = %d", min);
//     printf("\nEdge Connectivity = %d", min);

//     // Fundamental Cut-Set
//     printf("\n\nFundamental Cut-Sets:\n");
//     for(i = 0; i < n - 1; i++)
//     {
//         printf("(%d - %d)\n", i, i + 1);
//     }

//     // Graph Type
//     if(min > 1)
//         printf("\nGraph is Non-Separable");
//     else
//         printf("\nGraph is Separable");

//     return 0;
// }