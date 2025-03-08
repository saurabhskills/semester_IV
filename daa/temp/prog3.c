/*
Write a c program to implement recursive function of following problems.

    1. Factorial of a given number.
    2. Fibonnaci series
    3. Tower of Hanoi.
    4. Binary Search.
    5. Linear Search.

*/

#include<stdio.h>
static int count;

int fact(int n){

    if(n == 0 | n == 1)
    return 1;

    return n * fact(n-1);
}

int fib(int n){

    if( n == 0)
    return 0;

    if( n == 1)
    return 1;

    return fib(n-1) + fib(n-2);
}

void TOH(int n, char S, char D, char T){
    
    if(n>0){
        TOH(n-1, S, T, D);
        printf("\n");
        printf("%c -> %c\n", S, D);
        count++;
        TOH(n-1, T, D, S);
    }
    
    return;
}

int binSearch(int a[], int l, int h, int k)
{

    int mid = l + (h - l)/2;

    while(l <= h)
    {
        if(a[mid] == k)
        {
            return mid;
        }

        if(a[mid] < k)
        {
           return binSearch(a, mid+1, h, k);
        }
        else
        {
            return binSearch(a, l, mid-1, k);
        }

            return -1;
    }
}

int Linear(int a[], int size, int key){


    if(a[size-1] == key)
    return size-1;

    else
    return Linear(a, size-1, key);

    return -1;

}

int main(){

    printf("%d\n", fact(5));

    for(int i = 0; i <= 5; i++){
        printf("%d ", fib(i));

    }


    int sky[] = {1,2,3,4,5};
    int key = 5;
    int index = binSearch(sky, 0, 4, key);

    printf("\nUsing Binary Search\n");


    if(index == -1){
        printf("\n%d key is not present\n",key);
    }
    else{
        printf("\n%d key is present at index %d\n",key, index);
    }

    printf("\nUsing Linear Search\n");

    int index1 = Linear(sky, 5, key);

    if(index1 == -1){
        printf("\n%d key is not present\n",key);
    }
    else{
        printf("\n%d key is present at index %d\n",key, index1);
    }

    
    TOH(3,'S', 'D', 'T');
    printf("%d",count);

    return 0;
}