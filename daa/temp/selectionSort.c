#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);

        for(int k = 0; k<n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main(){
    int a[] = {1,25,3,42,36,63};
    selectionSort(a,6);

    return 0;
}