/*
    DATE: 11/12/2024
    QUESTION:
    WAP to implement Dynamic Programming Design techniques by using: 
        1. Matrix Chain Multiplication
        2. Longest Common Subsequence
*/

#include <stdio.h>
#include <limits.h>

int dp[100];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int MCM(int i, int j) {
    if (i == j) {
        return 0;
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = MCM(i, k) + MCM(k + 1, j) + dp[i - 1] * dp[k] * dp[j];
        minCost = min(minCost, cost);
    }

    return minCost;
}

int main() {
    dp[0] = 35;
    dp[1] = 15;
    dp[2] = 5;
    dp[3] = 10;
    dp[4] = 20;

    int n = 5; // Number of matrices
    int result = MCM(1, n - 1);

    printf("Minimum number of multiplications is %d\n", result);

    return 0;
}
