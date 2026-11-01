#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int stack[SIZE];
int top = 0;

void push(int x) {
  if(top >= SIZE - 1) {
    printf("Stack Overflow.\n");
  }
  else {
    stack[++top] = x;
  }
}   

int pop() {
  if(top == 0) {
    return 0;
  }
  return stack[top--];
} 

void dfs(int adj[SIZE][SIZE]) {
  int visited[SIZE] = {0};
  printf("DFS Traversal: ");
  push(0);

  while(top!=0) {
    int current = pop();
    if(!visited[current]) {
      visited[current] = 1;
      printf("%d ",current);

      for(int i = SIZE - 1;i >= 0; i--) {
        if(adj[current][i] == 1 && !visited[i]) {
          push(i);
        }
      }
    }
  } 
}

void main() {
  int adj[5][5] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {1,1,0,1,1},
    {0,0,1,0,0},
    {0,0,1,0,0}
  };
  dfs(adj);
} 