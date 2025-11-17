#include<stdio.h>
#include<string.h>
int main()
{
    char a[101], b[101];
    scanf("%s %s",&a,&b);
    // int len_a = strlen(a);
    // int len_b = strlen(b);
    strcat(a,b);
    printf("%s",a);
    

    return 0;
}