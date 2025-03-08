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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int p[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i-1] <= j)
                dp[i][j] = max(p[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main() {
    int n, k;
    printf("Enter no. of items: ");
    scanf("%d",&n);
    printf("Enter knapsack size: ");
    scanf("%d",&k);
    int p[100], wt[100];
    for(int i = 0; i <n; i++){
        scanf("%d",&wt[i]);
        scanf("%d",&p[i]);
    }
    printf("Maximum value in Knapsack = %d", knapSack(k, wt, p, n));
    return 0;
}
