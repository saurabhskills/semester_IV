#include<stdio.h>



void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        for(int k = 0; k<n; k++){
        printf("%d ", arr[k]);
    }
    printf("\n");
    }
}

int main(){

    int arr[] = {10, 8, 9, 15, 30, 12, 7};
    
    insertionSort(arr,7);

    printf("Sorted\n");

    for(int i = 0; i<7; i++){
        printf("%d ", arr[i]);
    }

    

    return 0;
}