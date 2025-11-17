#include<stdio.h>

void fun(int x)
{
    printf("%d\n",x);
    printf("fun founction: %p\n",&x);
}
int main()
{
    int x = 10;
    fun(x);
    printf("%d\n",x);
    printf("main founction: %p\n",&x);

    return 0;
}