#include <stdio.h>

void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    return;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Merge Sort
void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k++] = L[i++];
        }
        else
        {
            array[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        array[k++] = L[i++];
    }

    while (j < n2)
    {
        array[k++] = R[j++];
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main(){

    int sky[100];
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    inputArray(sky,size);

    mergeSort(sky, 0, size-1);

    printf("The sorted array is: ");
    printArray(sky,size);


    return 0;
}