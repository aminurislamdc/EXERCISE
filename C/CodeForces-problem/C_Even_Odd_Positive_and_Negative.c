#include<stdio.h>
int main()
{
    int n;
    int x;
    int eve=0,odd=0,pos=0,neg=0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        if (x%2==0)
        {
            eve++;
        }
        else
        {
            odd++;
        }
        if (x>0)
        {
            pos++;
        }
        else if(x<0)
        {
            neg++;
        }
    }
    printf("Even: %d\n",eve);
    printf("Odd: %d\n",odd);
    printf("Positive: %d\n",pos);
    printf("Negative: %d",neg);
    return 0;
}