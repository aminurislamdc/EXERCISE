#include<stdio.h>
int main()
{
    char aj[1000001];
    fgets(aj,1000001,stdin);
    for (int i = 0;aj[i] != '\\'; i++)
    {
        printf("%c",aj[i]);
    }
    
    return 0;
}