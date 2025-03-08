/*

Write a c program to implement Heap sort Algorithm.

*/
#include<stdio.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

void makeHeap(int arr[], int n, int i)
{
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively makeHeap the affected subtree
        makeHeap(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Step 1: Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        makeHeap(arr, n, i);

    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to the end (largest element)
        swap(&arr[0], &arr[i]);

        // Call makeHeap on the reduced heap
        makeHeap(arr, i, 0);
    }
}


int main(){

    int sky[] = {23,12,13,543,7};
    for(int i = 0; i< 5; i ++){
        printf("%d ",sky[i]);
    }

    heapSort(sky, 5);
    printf("\n");
    for(int i = 0; i< 5; i ++){
        printf("%d ",sky[i]);
    }
    return 0;
}