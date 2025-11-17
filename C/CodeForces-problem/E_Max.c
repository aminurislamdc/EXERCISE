#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int m = 0;
    for (int i = 1; i <= 5; i++)
    {
        int val;
        scanf("%d",&val);
        if (val > m)
        {
           m = val;
        }
    }
        printf("%d",m);
    return 0;
}