#include <stdio.h>
#include "my_mat.h"
int main(){
    int neighborsMatrix[MAXSIZE][MAXSIZE];
    char letter =0;
    int i=0;
    int j=0;
    while(letter!='D'){
        scanf("%c",&letter);
        if(letter == 'A'){
            getNewMatrix(neighborsMatrix);
        }
        else if(letter=='B'){
            scanf("%d",&i);
            scanf("%d",&j);
            find_path(i , j);
        }
        else if(letter=='C'){
            scanf("%d",&i);
            scanf("%d",&j);
            shortest_path(i,j);

        }
    }


}