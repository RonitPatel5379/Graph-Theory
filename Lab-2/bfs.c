#include <stdio.h>
void main() {
    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    }; 

    int visited[5] = {0};
    int queue[5];
    int front = 0, rear = 0;
    int i, current;

    visited[0] = 1;
    queue[rear++] = 0; // enqueue
    
    printf("BFS Traversal: ");
    while(front < rear) {
        current = queue[front++]; // dequeue
        printf("%d ", current);

        for(i = 0; i < 5; i++) {
            if(graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i; // enqueue
            }
        }
    } 
}