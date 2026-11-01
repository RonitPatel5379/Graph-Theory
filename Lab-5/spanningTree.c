#include<stdio.h>
void main() {
  int v,e,i,j;
  int u[50],w[50];
  printf("Enter the no. of vertex:");
  scanf("%d",&v);
  printf("Enter the edges:");
  scanf("%d",&e);
  printf("Enter edges:\n");
  int visited[v] = {0};
  for(i=0;i<e;i++) {
    scanf("%d %d",&u[i],&w[i]);
  }
  visited[0] = 1;
  printf("Spanning Tree Edges:\n");
  for(i=0;i<e;i++) {
    if(visited[u[i]] == 0 || visited[w[i]] == 0) {
      printf("(%d,%d)\n",u[i],w[i]);
      visited[u[i]] = 1;
      visited[w[i]] = 1;
    }
  }
}