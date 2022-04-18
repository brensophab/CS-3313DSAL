#include<stdio.h>
#include<stdlib.h>

/* to implement, Merge two subarrays of arr[], merge sorting using user input, and printlist*/

void mergeSort(int[],int, int, int);
void partition(int[], int, int);

//recursively divide array 
void partition(int list[], int left, int right){
   int middle;

    if(left < right){
        middle = (left + right) / 2;
        partition(list, left, middle);
        partition(list, middle+1, right);
        mergeSort(list, left, middle, right);
    }

}

void mergeSort(int list[], int left, int middle, int right)
{
    int i, k;
    int mid, le;
    int tempArr[100];
    le = left;
    i = left;
    mid = middle + 1;

    while((le <= middle) && (mid <=right)){
        if(list[le] <= list[mid]){
            tempArr[i] = list[le];
            le++;
        }
        else{
            tempArr[i] = list[mid];
            mid++;
        }
        i++;
    }

    if(le > middle){
        for(k = mid; k <= right; k++){
            tempArr[i] = list[k];
        i++;
        }
    }
    else{
        for(k = le; k <= middle; k++){
            tempArr[i] = list[k];
            i++;
        }
    }

    for(k = left; k <= right; k++){
        list[k] = tempArr[k];
    }
}

int main()
{
    int list[100];
    int i, size;
 
    printf("Enter total number of elements:");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for(i = 0; i < size; i++)
    {
         scanf("%d", &list[i]);
    }
    partition(list, 0 , size-1);
    printf("Sorted array is:\n");
   for(i = 0;i < size; i++)
    {
         printf("%d ",list[i]);
    }
 
   return 0;
}
