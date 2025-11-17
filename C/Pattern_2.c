#include<stdio.h>
int main()
{
    int n,spac,star;
    scanf("%d",&n);
    spac=n-1;
    star=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < spac; j++)
        {
            printf(" ");
        }
        for (int a = i+1 ; a > 0; a--)
        {
            printf("%d",a);
        }
        printf("\n");
        spac--;

    }
    
    return 0;
}