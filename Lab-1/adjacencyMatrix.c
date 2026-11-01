#include<stdio.h>
void main() {
  int vertex,edge,i,j;
  printf("Enter the vertex:");
  scanf("%d",&vertex);
  printf("Enter the edges:");
  scanf("%d",&edge);

  int edges[vertex][vertex];
  for(i=0;i<vertex;i++) {
    for(j=0;j<vertex;j++) {
      edges[i][j] = 0;
    }
  } 

  for(i=0;i<edge;i++) {
      scanf("%d",&edges[i][j]);
  }

  for(i=0;i<vertex;i++) {
    for(j=0;j<vertex;j++) {
      printf("%d ",edges[i][j]);
    }
    printf("\n");
  }
}