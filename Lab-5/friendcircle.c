#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
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

void dfs(int adj[SIZE][SIZE],int visited[],int start) {
  // int visited[SIZE] = {0};
  // printf("DFS Traversal: ");
  // push(0);
  push(start);

  while(top!=0) {
    int current = pop();
    if(!visited[current]) {
      visited[current] = 1;
      // printf("%d ",current);

      for(int i = SIZE - 1;i >= 0; i--) {
        if(adj[current][i] == 1 && !visited[i]) {
          push(i);
        }
      }
    }
  } 
}

void main() {
  int adj[4][4] = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,1,1},
    {0,0,1,1}
  };

  int visited[SIZE] = {0};
  int count = 0;

  for(int i=0;i<SIZE;i++) {
    if(!visited[i]) {
      dfs(adj,visited,i);
      count++;
    }
  }
  printf("Total Friend Circles:%d",count);
}