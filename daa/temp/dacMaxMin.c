/*

Write a c program to implement finding Min & Max in Array using DAC design technique.

*/
#include<stdio.h>

struct result
{
    int min;
    int max;
};


struct result DACMinMax(int a[], int low, int up, int min, int max){
    struct result temp;
    if(low == up){
        temp.min = a[low];
        temp.max = a[up];
        return temp;
    }
    else if(low == up-1){
        if(a[low] < a[up]){
            temp.min = a[low];
            temp.max = a[up];
        }
        else{
            temp.min = a[up];
            temp.max = a[low];
        }
        return temp;
    }
    else{
        int mid = (low + up)/2;
        struct result result1, result2;

        
        result1 = DACMinMax(a, low, mid, min, max);
        result2 = DACMinMax(a, mid +1, up, min, max);

        if(result1.min < result2.min){
            min = result1.min;
        }
        else{
            min = result2.min;
        }

        if(result1.max < result2.max){
            max = result2.max;
        }
        else{
            max = result1.max;
        }
        temp.max = max;
        temp.min = min;
        return temp;
    }

    
    

    

}
int main(){

    int sky[] = {23,12,13, -10,543,7,-1};
    struct result sol = DACMinMax(sky, 0, 6,-1,-1);
    printf("Max = %d Min = %d",sol.max, sol.min);

    return 0;
}