#include<stdio.h>
void main() {
  int vertex,edge,i,j;
  printf("Enter the no. of vertex:");
  scanf("%d",&vertex);
  printf("Enter the edges:");
  scanf("%d",&edge);

  int edges[edge][2];
  int visited_edges[edge];

  for(i=0;i<edge;i++) {
    visited_edges[i] = 0;
    for(j=0;j<=1;j++) {
      scanf("%d",&edges[i][j]);
    }
  }  
  for(i=0;i<edge;i++) {
    if(visited_edges[i]==1) continue;
    printf("\n%d -> ",edges[i][0]);
    printf("%d",edges[i][1]);
    visited_edges[i] = 1;
    for(j=i+1;j<edge;j++) {
      if(edges[i][0]==edges[j][0]) {
        printf(", %d",edges[j][1]);
        visited_edges[j] = 1;
      }
    }
  }
}