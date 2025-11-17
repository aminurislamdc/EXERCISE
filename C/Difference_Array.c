#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A;
    scanf("%d",&A);

    for (int a = 0; a < A; a++)
    {
        int N;
        scanf("%d",&N);
        int a[N], b[N], c[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (b[i] > b[j])
                {
                    int jannat;
                    jannat = b[i];
                    b[i] = b[j];
                    b[j] = jannat;
                }
            }
        }

        
        for (int jannat = 0; jannat < N; jannat++)
        {
            c[jannat] =a[jannat] - b[jannat];
        }
        for (int aminur = 0; aminur < N; aminur++)
        {
            printf("%d ", abs(c[aminur]));
        }
        printf("\n");
    }

    return 0;
}