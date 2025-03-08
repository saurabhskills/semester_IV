
// Job Scheduling
#include <stdio.h>

int main()
{
    int p[100], d[100];
    int n;

    printf("Enter no. of Jobs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Job %d profit and deadline: ", i + 1);
        scanf("%d", &p[i]);
        scanf("%d", &d[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] < p[j + 1])
            {
                int tempd = d[j];
                d[j] = d[j + 1];
                d[j + 1] = tempd;

                int tempp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempp;
            }
        }
    }

    printf("List of Jobs: ");
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d)", d[i], p[i]);
    }

    printf("\n");
    int s[100][100] = {(0, 0)};
    int max = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        int c = d[i] - 1;
        while (c >= 0)
        {
            if (s[c][0] == 0)
            {
                s[c][0] = p[i];
                s[c][1] = d[i];
                count++;
                break;
            }
            c--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        max += s[i][0];
    }
    printf("\nMax profit = %d\n\n", max);

    printf("Solution: ");
    for (int i = 0; i < count; i++)
    {
        printf("(%d, %d)", s[i][0], s[i][1]);
    }
}