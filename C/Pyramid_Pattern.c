#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int star=1,spac =n-1;
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= spac; a++)
        {
            printf(" ");
        }
        
        for (int j = 1; j <= star; j++)
        {
            printf("*");
        } 
        printf("\n");
        star += 2;
        spac --;   
    }
    return 0;
}