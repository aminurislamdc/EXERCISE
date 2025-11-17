#include<stdio.h>
int main()
{
    int n,k,output=0;
    scanf("%d %d",&n,&k);
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a[i]);
    }
    for (int  i = 1; i <= n; i++)
    {
        if (i==k && a[i]%k==0)
        {
            output++;
        }
        
    }
    printf("%d",output);


    return 0;
}