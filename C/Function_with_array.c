#include<stdio.h>
void fun(int a[],int n)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    fun(a,n);
    return 0;
}