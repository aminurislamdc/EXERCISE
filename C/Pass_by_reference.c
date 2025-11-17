#include<stdio.h>

void fun(int* p)
{
    *p = 20;
}
int main()
{
    int x = 10;
    fun(&x);
    printf("%d\n",x);
    printf("main founction: %p\n",&x);

    return 0;
}