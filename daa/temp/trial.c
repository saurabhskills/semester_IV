#include <stdio.h>

void knapsack(int n, int wt[], int p[], int k) {
    float ppw[100];
    for (int i = 0; i < n; i++) {
        ppw[i] = (float)p[i] / wt[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ppw[j] < ppw[j + 1]) {
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

    int currsize = 0;
    float profit = 0;
    int idx = 0;
    while (currsize < k && idx < n) {
        if (currsize + wt[idx] <= k) {
            currsize += wt[idx];
            profit += p[idx];
        } else {
            int takewt = k - currsize;
            profit += takewt * ppw[idx];
            currsize += takewt;
        }
        idx++;
    }

    printf("Maximum profit = %f\n", profit);
}

int main() {
    int wt[100], p[100];
    int n, k;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack size: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and profit of item %d: ", i + 1);
        scanf("%d", &wt[i]);
        scanf("%d", &p[i]);
    }

    knapsack(n, wt, p, k);

    return 0;
}
