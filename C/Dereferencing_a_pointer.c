#include<stdio.h>
int main()
{
    int x = 100;
    printf("%d\n",x);
    int* ptr;
    ptr = &x;
    printf("%p\n",ptr);
    return 0;
}