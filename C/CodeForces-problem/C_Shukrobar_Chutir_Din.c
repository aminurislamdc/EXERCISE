#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int k,m,n;
        scanf("%d %d %d",&k,&m,&n);
        int total_day=0,total_milk=0;
        total_day=(n/7);
        total_milk=total_day*k*m;

        printf("%d\n",total_milk);
        
    }
    
    return 0;
}