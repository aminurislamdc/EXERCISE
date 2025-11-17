#include<stdio.h>
int main()
{
    int n,spac,star;
    scanf("%d",&n);
    spac=n-1;
    star=1;
    for (int i = 1; i <= (2*n)-1; i++)
    {
        for (int j = 1; j <= spac; j++)
        {
            printf(" ");
        }
        for (int a = 1; a <= star; a++)
        {
            printf("*");
        }
        if (i<=n-1)
        {
            spac--;
            star=star+2;
        }
        else
        {
            spac++;
             star=star-2;
        }
        
        printf("\n");
    }
    return 0;
}