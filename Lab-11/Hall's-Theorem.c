#include <stdio.h>

int graph[4][4] = {
    {1, 1, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {0, 0, 1, 1}
};

int subsets[15][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},

    {1,1,0,0},
    {1,0,1,0},
    {1,0,0,1},
    {0,1,1,0},
    {0,1,0,1},
    {0,0,1,1},

    {1,1,1,0},
    {1,1,0,1},
    {1,0,1,1},
    {0,1,1,1},

    {1,1,1,1}
};

int checkHallsCondition() {
    int i, j, k;
    int leftCount, rightCount;
    int used[4];

    /*
       Darek subset mate one by one check karvanu.
       Pehla to subset ma ketla vertex che e count karvana.
       Pachhi ena badha neighbour find karvana.
       Same neighbour ne ek j vaar count karvo.

       Jo koi pan subset mate right side na neighbour < left side na vertex
       hoy to Hall's condition satisfy nahi thay.

       Badha subset mate condition satisfy thay to Hall's condition satisfy thay.
    */

    // Write code here

    return 0;
}

void main() {
    int ans;
    ans = checkHallsCondition();
    if(ans == 1)
        printf("Hall's condition is satisfied");
    else
        printf("Hall's condition is not satisfied");
}