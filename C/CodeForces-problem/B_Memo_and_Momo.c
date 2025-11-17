#include<stdio.h>
int main()
{
    long long int a,b,k;
    scanf("%lf %lf %lf",&a,&b,&k);
    if (k/a==0.0 && k/b==0.0)
    {
        printf("Both");
    }
    else if (k/a==0.0 && k/b!=0.0)
    {
        printf("Memo");
    }
    else if (k/a!=0.00 && k/b==0.00)
    {
        printf("Momo");
    }else if (k/a!=0.00 && k/b!=0.00)
    {
        printf("No One");
    }
    return 0;
}