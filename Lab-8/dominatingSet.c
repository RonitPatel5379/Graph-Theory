#include<stdio.h>
#define v 4
int adj[v][v]={
  {0,1,1,0},
  {1,0,1,1},
  {1,1,0,0},
  {0,1,0,0}
};

int single[4][1]={
  {0},
  {1},
  {2},
  {3}
};

int pairs[6][2]={
  {0,1},
  {0,2},
  {0,3},
  {1,2},
  {1,3},
  {2,3}
};

int tripale[4][3]={
  {0,1,2},
  {0,1,3},
  {0,2,3},
  {1,2,3}
};

int quads[1][4]={
  {0,1,2,3} 
};

int dominat(int set[], int size){
    int dominate[v]={0};
    for(int i=0;i<size;i++){
        int u = set[i];
        dominate[u] = 1;

        for(int j=0;j<v;j++){
            if(adj[u][j]==1){
                dominate[j] = 1;
            }
        }
    }

    for(int j=0;j<v;j++){
        if(dominate[j] != 1){
            return 0;
        }
    }
    return 1;
}

void printSet(int set[], int size){
    printf("\n { ");
    for(int j=0;j<size;j++){
       printf(" %d, ",set[j]);
    }
    printf("}");
}

void main(){
    int n = v + 1;

    for(int i=0;i<4;i++){
        if(dominat(single[i],1)){
            printSet(single[i],1);
            n = 1;
        }
    }
 
    for(int i=0;i<6;i++){
        if(dominat(pairs[i],2)){
            printSet(pairs[i],2);
            if(n > 2){
                n = 2;
            }
        }
    }
 
    for(int i=0;i<4;i++){
        if(dominat(tripale[i],3)){
            printSet(tripale[i],3);
            if(n>3){
            n = 3;
            }
        }
    }

    for(int i=0;i<1;i++){
        if(dominat(quads[i],4)){
            printSet(quads[i],4);
            if(n>4){
            n = 4;
            }
        }
    }
}