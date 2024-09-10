#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

// 1. Linear Search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// 2. Binary Search
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

// 3. Binary Search with recursion
int recBinarySearch(int arr[], int l, int h, int x)
{
    if (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return recBinarySearch(arr, l, mid - 1, x);

        return recBinarySearch(arr, mid + 1, h, x);
    }

    // Element is not present in array
    return -1;
}

// 4. Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 5. Selection Sort
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
        swap(&arr[min], &arr[i]);
    }
}

// 6. Insertion Sort
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

// 7. Quick Sort
int partition(int array[], int p, int r)
{
    int x = array[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (array[j] < x)
        {
            i = i + 1;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[r]);
    return i + 1;
}

void quickSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

// 8. Merge Sort
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

// 9. Heap Sort
// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

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

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    // Step 1: Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to the end (largest element)
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int choice, key, index;
    char ch;
    int arr[5] = {1, 20, 12, 13, 15};
    int size = 5;

    do
    {
        printf("\n----------------------------  Menu  -------------------------------------\n");
        printf("Enter\n");
        printf("1: To print array\t\t\t");
        printf("2: To enter elements of the array\n");
        printf("3: To Sort the array\t\t\t");
        printf("4: For Linear Search\n");
        printf("5: For Binary Search\t\t\t");
        printf("6: For Recursive Binary Search\n");
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
            printf("\nEnter\n");
            int a;
            printf("1: for Bubble Sort\t\t\t");
            printf("2: for Insertion Sort\n");
            printf("3: for Selection Sort\t\t\t");
            printf("4: for Quick Sort\n");
            printf("5: for Merge Sort\t\t\t");
            printf("6: for Heap Sort\n");
            printf("Enter your choice here: ");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                bubbleSort(arr, size);
                printf("Using Bubble sort: ");
                printArray(arr, size);
                break;
            case 2:
                insertionSort(arr, size);
                printf("Using Insertion sort: ");
                printArray(arr, size);
                break;
            case 3:
                selectionSort(arr, size);
                printf("Using Selection sort: ");
                printArray(arr, size);
                break;
            case 4:
                quickSort(arr, 0, size - 1);
                printf("Using Quick sort: ");
                printArray(arr, size);
                break;
            case 5:
                mergeSort(arr, 0, size-1);
                printf("Using Merge sort: ");
                printArray(arr, size);
                break;
            case 6:
                heapSort(arr, size);
                printf("Using Heap sort: ");
                printArray(arr, size);
                break;
            default:
                printf("please enter a vailid option\n");
            }
            break;

        case 4:
            printf("Enter the key:");
            scanf("%d", &key);
            index = linearSearch(arr, size, key);
            if (index != -1)
            {
                printf("%d is present at %d\n", key, index);
            }
            else
            {
                printf("%d is not present\n", key);
            }
            break;

        case 5:
            printf("Making sure array is sorted:\n");
            selectionSort(arr, size);
            printf("Binary Search operation:\n");
            printf("Enter the key:");
            scanf("%d", &key);
            index = binarySearch(arr, size, key);
            if (index != -1)
            {
                printf("%d is present at %d\n", key, index);
            }
            else
            {
                printf("%d is not present\n", key);
            }
            break;
        case 6:
            printf("Making sure array is sorted:\n");
            selectionSort(arr, size);
            printf("Recursive Binary Search operation:\n");
            printf("Enter the key:");
            scanf("%d", &key);
            index = recBinarySearch(arr, 0, size - 1, key);
            if (index != -1)
            {
                printf("%d is present at %d\n", key, index);
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
        scanf(" %c", &ch);
    } while (ch == 'y');

    return 0;
}
