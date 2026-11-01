#include<stdio.h>
#define MAX 4
#define n 4

int adj[MAX][MAX] = {
  {0,1,1,0},
  {1,0,1,1},
  {1,1,0,0},
  {0,1,0,0}
};

int edges[4][2] = {
  {0,1},
  {0,2},
  {1,2},
  {1,3}
};

void dfs(int arr[MAX][MAX],int visited[MAX],int v) {
  visited[v] = 1;
  for(int i=0;i<MAX;i++) {
    if(arr[v][i] && !visited[i]) {
      dfs(arr,visited,i);
    }
  }
}