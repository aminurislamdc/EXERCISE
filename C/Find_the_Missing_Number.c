#include <stdio.h>

int main()
{
    int T;
    long long int M;
    int A,B,C,aminur_jannat;

    scanf("%d",&T);
    long long P;
    for (int i = 0; i < T; T--)
    {
        scanf("%lld %d %d %d",&M,&A,&B,&C);
        P = A * B * C;

        if (P == 0)
        {
            if (M == 0)
            {
                printf("0\n");
            } else
            {
                printf("-1\n");
            }
        }
        else if (M % P == 0)
        {
            aminur_jannat = M / P;
            printf("%d\n", aminur_jannat);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}