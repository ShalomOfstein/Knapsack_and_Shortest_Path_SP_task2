#include <stdio.h>
#include "my_mat.h"
/*
this program gets a graph from the user with up to 10 nodes (after the user enters the letter A)
then the user can ask for the shortest path between two nodes (C)
or if there is a pathe between two nodes (B)
to exit the user needs to enter the letter D
*/

// main function that gets the input and calls the functions
int main(){
    int neighborsMatrix[MAXSIZE][MAXSIZE];
    char letter =0;
    int i=0;
    int j=0;
    
    while(letter!='D'){  //exit when the user enters the letter D
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