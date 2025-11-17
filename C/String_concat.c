#include<stdio.h>
#include<string.h>
int main()
{
    char a[101], b[101];
    scanf("%s %s",&a,&b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; i <= len_b; i++)
    {
        a[i+len_a] = b[i];
    }
    printf("%s",a);
    

    return 0;
}