#include<stdio.h>
int main()
{
    char aj[101];
    scanf("%s",&aj);
    int count = 0;
    for (int i = 0; aj[i] != '\0'; i++)
    {
        count++;
    }
    
    printf("%d",count);
    return 0;
}