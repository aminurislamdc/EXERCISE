#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int s=1,sp=((10+n)/2);
    for (int i = 0; i < 10+n; i+=2)
    {
        for (int j = 0; j < sp; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < s; k++)
        {
            printf("*");
        }
        sp--;
        s+=2;
        printf("\n");
    }
    int asp=(10/2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < asp; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < n; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    
    return 0;
}