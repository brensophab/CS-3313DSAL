#include<stdio.h>
#include<stdlib.h>
void printArray(int *array, int size){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%i, ", array[i]);
    }
    printf("]");
}
int main(){
    int amount;
    printf("Enter amount of integers in array\n");
    scanf("%d", &amount);
    int *array = malloc(amount*sizeof(*array));

    for(int i = 0; i < amount; i++){
        printf("enter digits");
        scanf("%d", &array[i]);

        
    }
    printArray(array, amount);

        free(array);

        return 0;
}