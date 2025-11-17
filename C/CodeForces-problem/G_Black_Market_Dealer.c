#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int prices[n], resell[n], profits[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &resell[i]);
        profits[i] = resell[i] - prices[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profits[i] < profits[j])
            {
                int temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;
            }
        }
    }

    int max_profit = 0;
    for (int i = 0; i < k; i++)
    {
        max_profit += profits[i];
    }
    
    if (max_profit > 0)
    {
        printf("%d\n", max_profit);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}