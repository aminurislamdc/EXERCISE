#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
        sum=sum+a[i];
    }
    printf("%lld",abs(sum));
    return 0;
}