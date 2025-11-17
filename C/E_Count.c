#include<stdio.h>
int main()
{
    char aj[1000001];
    scanf("%s",&aj);
    int len = strlen(aj);
    int sum=0;
    for (int i = 0; i<len ; i++)
    {
        sum += aj[i]-'0';

    }
    printf("%d",sum);
    return 0;
}