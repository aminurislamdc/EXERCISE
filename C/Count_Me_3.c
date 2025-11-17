#include<stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
    {
        char s[10001];
    scanf("%s",&s);
    int capital_alphabets=0, small_alphabets=0, digits=0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i]>='A' && s[i]<='Z')
        {
            capital_alphabets ++;
        }
        else if (s[i]>='a' && s[i]<='z')
        {
            small_alphabets  ++;
        }
        else if (s[i]>='0' && s[i]<='9')
        {
            digits ++;
        }
    }
    printf("%d ",capital_alphabets);
    printf("%d ",small_alphabets);
    printf("%d\n",digits);
    }
    
    return 0;
}