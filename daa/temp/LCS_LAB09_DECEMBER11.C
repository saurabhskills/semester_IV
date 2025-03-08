/*
    DATE: 11/12/2024
    QUESTION:
    WAP to implement Dynamic Programming Design techniques by using:
        1. Matrix Chain Multiplication
        2. Longest Common Subsequence
*/

#include <stdio.h>

// char X[] = "sky";
// int i = 3;
// char Y[] = "sskyssak";
// int j = 8;

char X[] = "qpqrr";
int i = 5;
char Y[] = "pqprqrp";
int j = 7;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int LCS(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (X[i - 1] == Y[j - 1])
        return (1 + LCS(i - 1, j - 1));

    if (X[i - 1] != Y[j - 1])
    {

        return (max(LCS(i - 1, j), LCS(i, j - 1)));
    }
}
int main()
{
    int a = LCS(i, j);
    printf("Length of Longest Common Subsequence: %d\n", a);
    return 0;
}