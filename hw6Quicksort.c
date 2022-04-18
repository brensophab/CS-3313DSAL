#include<stdlib.h>
#include<stdio.h>






void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int left, int right){
    if(right==left+1){
        if(arr[left]>arr[right]){swap (&arr[left], &arr[right]);}
       return left; //lowest val
       }

    int tempArray[] = {arr[left], arr[(left+right)/2], arr[right]};

    if(tempArray[0] > tempArray[1]){swap(&tempArray[0],&tempArray[1]);}
    if(tempArray[0] > tempArray[2]){swap(&tempArray[0],&tempArray[2]);}
    if(tempArray[1] > tempArray[2]){swap(&tempArray[1],&tempArray[2]);}

    arr[left] = tempArray[0];
    arr[(left+right)/2] = tempArray[2];
    arr[right] = tempArray[1];

    int piv = arr[right];
    int i = left-1;
    for(int j = left; j<right; j++){
        if(arr[j] <= piv){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    
    swap(&arr[i+1],&arr[right]);

    return i+1;
}

void quickSort(int arr[], int left, int right){
    if(left<right){
        int indexPartition = partition(arr, left, right);

        quickSort(arr,left,indexPartition-1);
        quickSort(arr,indexPartition+1,right);
    }
}
int main(){
    int list[100];
    int i, size;
 
    printf("Enter total number of elements:");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for(i = 0; i < size; i++)
    {
         scanf("%d", &list[i]);
    }
    quickSort(list, 0 , size-1);
    printf("Sorted array is:\n");
   for(i = 0;i < size; i++)
    {
         printf("%d ",list[i]);
    }
 
   return 0;
}