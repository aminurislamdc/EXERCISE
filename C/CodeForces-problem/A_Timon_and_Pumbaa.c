#include<stdio.h>
int main()
{
    int a,b,jaren;
    scanf("%d %d", &a, &b);
    jaren=a-b;
    if (jaren>=0)
    {
        printf("%d",jaren);
    }
    else
    {
        printf("0");
    }
    

    return 0;
}