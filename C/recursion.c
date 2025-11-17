#include<stdio.h>
void hello()
{
    printf("hello");
}
void hi()
{
    printf("hi\n");
    hello();
}
int main()
{
    hi();
    return 0;
}