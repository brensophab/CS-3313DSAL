#include<stdlib.h>
#include<stdio.h>

//find the max of two ints
int max(int a, int b){
    return a>b?a:b;
}

//find the maximum value that can be put in a knapsack of capacity w
int knapsack(int w, int *wt, int *val, int n){
    int i, j;
    int **K = (int **)malloc(sizeof(int*)*(n+1)); //allocate memory for K
    for(i=0; i<=n; i++){
        K[i] = (int *)malloc(sizeof(int)*(w+1)); // allocate memory for each row
    }
    for(i=0; i<=n; i++){ //initialize the first row
        for(j=0; j<=w; j++){ //initialize the first column
            if(i==0 || j==0){ //if i==0 or j==0, then the value is 0
                K[i][j] = 0;
            }
            else if(wt[i-1]<=j){ //if the weight of the item is less than or equal to the capacity of the knapsack
                K[i][j] = max(val[i-1]+K[i-1][j-wt[i-1]], K[i-1][j]); //find the max of the value of the item plus the value of the knapsack minus the weight of the item
            }
            else{
                K[i][j] = K[i-1][j]; //if the weight of the item is greater than the capacity of the knapsack, then the value of the knapsack is the value of the knapsack from the previous row
            }
        }
    }
    return K[n][w]; // returns the maximum value that can be put in a knapsack of capacity w
}

int main(){
//    
    int wt[] = {3,4,7,8,9}; //weight array
    int val[] = {4,6,11,13,15}; //value array
    int w = 17; // capacity
    int n = sizeof(val)/sizeof(val[0]);

    printf("%d\n", knapsack(w, wt, val, n));
    return 0;
}