/*
    Write a C/C++ program to implement dynamic programming design techniques by using:
        TODAYS LAB
        1. Fibonacci Series
        2. 0/1 knapsack problem
        NEXT LAB
        3. Longest common subsequence
        4. Matrix chain Multiplication
*/
#include<stdio.h>
// Fibonacci Series
//int dp[100];
//int dp[100];
int fib(int n){
    int dp[n+1];

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++ ){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
};
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int f = fib(num);
    printf("Fib(%d) = %d", num,f);

    return 0;

}