/*
Write a c/cpp program to implement greedy design techniques by using
    1. Knapsack-problem
    2. Huffman-Encoding
    3. Job-Sequencing with Deadlines
*/

#include <stdio.h>

int main()
{
    int wt[100], p[100];
    float ppw[100];
    int n, k;
    // Taking item details from user.
    printf("Enter no. of process: ");
    scanf("%d", &n);
    printf("Enter knapsack size: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight and profit of item %d: ", i + 1);
        scanf("%d", &wt[i]);
        scanf("%d", &p[i]);
        ppw[i] = (float(p[i])) / wt[i];
    }

    // Sorting items according to ppw.
    // Using bubble sort.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (ppw[j] > ppw[j + 1])
            {
                float temp = ppw[j];
                ppw[j] = ppw[j + 1];
                ppw[j + 1] = temp;

                int tempwt = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = tempwt;

                int tempp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempp;
            }
        }
    }

    // printing the sorted list.
    for (int i = 0; i < n; i++)
    {
        printf("Item %d, weight = %d, profit = %d and ppw = %f \n", i + 1, wt[n - 1 - i], p[n - 1 - i], ppw[n - 1 - i]);
    }

    // Selection of items
    int sol[100] = {0};
    int currsize = 0;
    float profit = 0;
    int idx = 0;
    int selected = 0;
    while (currsize <= k)
    {
        if (currsize + wt[n - 1 - idx] <= k)
        {
            currsize = currsize + wt[n - 1 - idx];
            profit = profit + wt[n - 1 - idx] * ppw[n - 1 - idx];
            sol[selected] = wt[n - 1 - idx];
            selected++;
        }
        else
        {
            int takewt = k - currsize;
            currsize = currsize + takewt;
            profit = profit + takewt * ppw[n - 1 - idx];
            sol[selected] = takewt;
            selected++;
        }
        idx++;

        if (currsize == k)
        {
            break;
        }
    }

    // Final output.
    printf("Maximum profit = %f \n", profit);
    printf("The solution is: <");
    for (int i = 0; i <= selected; i++)
    {
        printf("%d, ", sol[i]);
    }
    printf(">");

    return 0;
}