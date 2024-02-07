#include <stdio.h>
#include "my_mat.h"
#define INF 2147483647
int shortestPathMat[MAXSIZE][MAXSIZE] ={0};

void getNewMatrix(int neighborsMatrix[MAXSIZE][MAXSIZE]){
    // Initialize shortestPathMat with INF for all positions
    
    for(int i =0; i< MAXSIZE;i++){
        for(int j = 0; j<MAXSIZE; j++){
            scanf("%d" , &neighborsMatrix[i][j]);
        }
    }
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            shortestPathMat[i][j] = INF;
        }
    }
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            if(i==j||neighborsMatrix[i][j]!=0){
                shortestPathMat[i][j] = neighborsMatrix[i][j];
            }
        }
    }
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