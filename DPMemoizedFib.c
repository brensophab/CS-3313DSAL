#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
// max of two ints
int max(int a, int b){
    return a>b?a:b;
}

// Use a DP memoized approach to find the nth term of a fibonacci sequence
uint64_t fib(uint64_t n){
    uint64_t *fibArray = (uint64_t *)malloc(sizeof(uint64_t)*(n+1)); //allocate memory for fibArray
    fibArray[0] = 0; //base case
    fibArray[1] = 1; //base case
    for(uint64_t i = 2; i<=n; i++){ //loop through the array
        fibArray[i] = fibArray[i-1] + fibArray[i-2]; // index of array is the nth term of the fibonacci sequence and is equal to the sum of the previous two terms
    }
    return fibArray[n];
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("%d\n", fib(n));

    return EXIT_SUCCESS;
}