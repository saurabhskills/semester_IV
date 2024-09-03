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

void linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("%d is found at %d\n", key, i);
            return;
        }
    }
    printf("%d is not found.\n", key);
    return;
}

int binarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
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

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;
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

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

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
    }
}
int main()
{
    int choice, key, choice2, in;
    char ch;
    int arr[5] = {1, 2, 12, 13, 15};
    int size = 5;

    do
    {
        printf("\n\t\t---------- Menu  ---------- \t\t\n");
        printf("1 to print array\n");
        printf("2 to enter elements of the array\n");
        printf("3 to Sort the array\n");
        printf("4 for linear search\n");
        printf("5 for binary search\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printArray(arr, size);
            break;
        case 2:
            printf("Enter elements in array:");
            inputArray(arr, size);
            break;

        case 3:
            printf("Enter\n");
            int a;
            printf("1 for Bubble Sort\n");
            printf("2 for Insertion Sort\n");
            printf("3 for Selection Sort\n");
            printf("Enter your choice here: ");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                bubbleSort(arr, size);
                break;
            case 2:
                insertionSort(arr, size);
                break;
            case 3:
                selectionSort(arr, size);
                break;
            }
            break;

        case 4:
            printf("Enter the key:");
            scanf("%d", &key);
            linearSearch(arr, size, key);
            break;

        case 5:
            printf("Making sure array is sorted:\n");
            selectionSort(arr, size);
            printf("Now performing binarysearch operation\n");
            printf("Enter the key:");
            scanf("%d", &key);
            in = binarySearch(arr, size, key);
            if (in != -1)
            {
                printf("%d is present at %d\n", key, in);
            }
            else
            {
                printf("%d is not present\n", key);
            }
            break;

        default:
            printf("please enter a vailid option\n");
        }

        printf("Would you like to continue(y/n):");
        scanf("    %c", &ch);
    } while (ch == 'y');

    return 0;
}
