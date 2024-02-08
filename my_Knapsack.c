#include <stdio.h>
#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int knapSack (int weights[], int values[] , int selected_bool[]){
    int knapsack[MAX_ITEMS+1][MAX_WEIGHT+1];
    //initialize the dynamic programing array:
    //knapsack[i][w] = maximum value that can be obtained with i items and weight w
    
    for(int i = 0; i<=MAX_ITEMS; i++){
        for(int w = 0; w<=MAX_WEIGHT; w++){
            
            if(i==0||w==0){
                knapsack[i][w] = 0;
            }
            
            else if(weights[i-1]<=w){
                int include = values[i-1]+knapsack[i-1][w-weights[i-1]];
                int exclude = knapsack[i-1][w];
                if(include>exclude){
                    knapsack[i][w] = include;
                }
                else{
                    knapsack[i][w] = exclude;
                }
            }
            
            else{
                knapsack[i][w] = knapsack[i-1][w];
            }
        }
    }

    //backtrack to get the selected items
    int i = MAX_ITEMS;
    int w = MAX_WEIGHT;
    while (i > 0 && w > 0) {
        if (knapsack[i][w] != knapsack[i - 1][w]) {
            selected_bool[i-1] = 1; // Set the selected_bool for this item
            w = w- weights[i-1];
        }
        i--;
    } 
    return knapsack[MAX_ITEMS][MAX_WEIGHT];    

}

int main(){
    char items[MAX_ITEMS]={0};
    int weights[MAX_ITEMS]={0};
    int values[MAX_ITEMS]={0};
    int selected_bool[MAX_ITEMS];

    // Get the input from the user
    for(int i = 0; i<MAX_ITEMS; i++){
        scanf(" %c",&items[i]);
        scanf("%d",&values[i]);
        scanf("%d",&weights[i]);
        selected_bool[i] = 0;
    }
    // Call the knapSack function to get the maximum profit
    int bestValue = knapSack(weights,values,selected_bool);

    // Print the results
    printf("Maximum profit: %d\n", bestValue);
    printf("Selected items:");

    for(int i = 0; i<MAX_ITEMS; i++){
        if(selected_bool[i]){
            printf(" %c",items[i]);
        }
    }
}