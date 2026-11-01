#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int stack[SIZE];
int top = 0;

void push(int x) {
    if(top >= SIZE-1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
} 

int pop() {
    if(top == 0)
        return 0;
    return stack[top--];
}

void dfs(int adj[SIZE][SIZE], int start, int removed, int visited[]) {
    top = 0;
    push(start);

    while(top != 0) {
        int current = pop();
        if(!visited[current]) {
            visited[current] = 1;
            for(int i = SIZE-1; i >= 0; i--) {
                if(i != removed && adj[current][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
} 

void main() {
    // int adj[SIZE][SIZE];
    int visited[SIZE];

    // printf("Enter adjacency matrix:\n");

    // for(int i=0;i<SIZE;i++) {
    //     for(int j=0;j<SIZE;j++) {
    //         scanf("%d",&adj[i][j]);
    //     }
    // }

    int adj[5][5] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,0},
    {0,1,0,0,1},
    {0,0,0,1,0}
  };

    printf("Articulation Points are:\n");

    for(int remove=0; remove<SIZE; remove++) {
        for(int i=0;i<SIZE;i++)
            visited[i]=0;

        int start=0;
        while(start==remove)
            start++;

        dfs(adj,start,remove,visited);

        int cut=0;

        for(int i=0;i<SIZE;i++) {
            if(i!=remove && !visited[i]) {
                cut=1;
                break;
            }
        }
        if(cut)
            printf("%d ",remove);
    }
} 