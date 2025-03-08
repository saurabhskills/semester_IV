#include<stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    printf("Birnary Search:\n");

    int arr[5] = {1,2,5,34,32};
    printf("%d is found at %d",32,binarySearch(arr, 5, 32));

    return 0;
}