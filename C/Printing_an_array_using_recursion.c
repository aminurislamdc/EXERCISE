#include<stdio.h>
void print_array(long long int a[],int n,int i)
{
    if (i==n)
    {
        return;
    }
    print_array(a,n,i+2);
    printf("%lld ",a[i]);
    
    
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
    }
    print_array(a,n,0);
    return 0;
}