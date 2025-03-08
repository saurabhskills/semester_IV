#include<stdio.h>


void bubbleSort(int arr[], int n) {
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            flag =0;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            printf("Already Sorted");
            return;
        }
        for(int k = 0; k < n; k++){
        printf("%d ", arr[k]);
        }
        printf("\n");
        
    }
}

int main(){
    int arr[] = {1, 2, 30, 40, 5,4,3};
    bubbleSort(arr, 7);

    return 0;
}