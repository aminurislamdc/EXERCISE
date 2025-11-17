#include<stdio.h>
int main()
{
    char s[1000001];
    scanf("%s",&s);
    int consonants=0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u')
        {}
        else
        {
            consonants++;
        }
    }
    printf("%d",consonants);
    return 0;
}