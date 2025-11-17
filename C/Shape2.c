#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int count=n,star=1,space=n-1;
    for (int i = 1; i <= n; i++)
    {
        for (int jan = 1; jan<=space;)
        {
            printf(" ");
        }
        
        for (int j = 1; j <= star; j++)
        {
            printf("*");
            
        }
        printf("\n");
        space--;
        star++;
        count++;
    }
    
    return 0;
}