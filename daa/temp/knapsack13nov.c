#include <stdio.h>
// Defining item attributes
struct item
{
    int id;
    int wt;
    int p;
    float ppw;
};

int main()
{
    struct item items[100];
    int n, k;
    // Taking item details
    printf("Enter no. of process: ");
    scanf("%d", &n);
    printf("Enter knapsack size: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight and profit of item %d: ", i + 1);
        items[i].id = i + 1;
        scanf("%d", &items[i].wt);
        scanf("%d", &items[i].p);
        items[i].ppw = (items[i].p * 1.0) / items[i].wt;
    }

    // Sorting items accoding to ppw
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (items[j].ppw > items[j + 1].ppw)
            {
                struct item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Selecting items
    int sol[100][100] = {0};
    int currsize = 0;
    float profit = 0;
    int idx = 0;
    int selected = 0;
    while (currsize <= k && idx < k)
    {
        if (currsize + items[n - 1 - idx].wt <= k)
        {
            currsize = currsize + items[n - 1 - idx].wt;
            profit = profit + items[n - 1 - idx].wt * items[n - 1 - idx].ppw;
            sol[selected][0] = items[n - 1 - idx].id;
            sol[selected][1] = items[n - 1 - idx].wt;
            selected++;
        }
        else
        {
            int takewt = k - currsize;
            currsize = currsize + takewt;
            profit = profit + takewt * items[n - 1 - idx].ppw;
            sol[selected][0] = items[n - 1 - idx].id;
            sol[selected][1] = takewt;
            selected++;
        }
        idx++;

        if (currsize == k)
        {
            break;
        }
    }

    // Final solution
    printf("Maximum profit = %f \n", profit);
    printf("The solution is: <\n");
    for (int i = 0; i < selected; i++)
    {
        printf("Item no. %d, selected weight = %d \n", sol[i][0], sol[i][1]);
    }
    printf("Remaining items are not selected. >");

    return 0;
}