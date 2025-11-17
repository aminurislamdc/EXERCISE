#include<stdio.h>
int main()
{
    int a[5] = {10,20,30,40,50};
    printf("%p\n",&a[0]);
    printf("%d\n",*a);
    
    return 0;
}