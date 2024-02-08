#include <stdio.h>
#include "my_mat.h"
#define INF 2147483647
int shortestPathMat[MAXSIZE][MAXSIZE] ={0};

void getNewMatrix(int neighborsMatrix[MAXSIZE][MAXSIZE]){
    // Get the new matrix from the user
    
    for(int i =0; i< MAXSIZE;i++){
        for(int j = 0; j<MAXSIZE; j++){
            scanf("%d" , &neighborsMatrix[i][j]);
        }
    }
    
    // Initialize shortestPathMat with INF for all positions
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            shortestPathMat[i][j] = INF;
        }
    }
    // Initialize shortestPathMat with the values of the neighborsMatrix
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            if(i==j||neighborsMatrix[i][j]!=0){
                shortestPathMat[i][j] = neighborsMatrix[i][j];
            }
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < MAXSIZE; k++) {
        for (int i = 0; i < MAXSIZE; i++) {
            for (int j = 0; j < MAXSIZE; j++) {
                if(shortestPathMat[i][k]!=INF && shortestPathMat[k][j]!=INF){
                    if (shortestPathMat[i][k] + shortestPathMat[k][j] < shortestPathMat[i][j]) {
                        shortestPathMat[i][j] = shortestPathMat[i][k] + shortestPathMat[k][j];
                    }
                }
            }
        }
    }
}


   
void find_path(int i , int j){
    if(shortestPathMat[i][j]==INF||shortestPathMat[i][j]<=0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }

}

void shortest_path(int i, int j){
    if (shortestPathMat[i][j]!=INF&&shortestPathMat[i][j]!=0){
        printf("%d\n",shortestPathMat[i][j]);
    }
    else{
        printf("-1\n");
    }
}