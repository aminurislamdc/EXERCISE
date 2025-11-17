#include<stdio.h>
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    if (0 <= A || B <=100)
    {

        if (A >= B)
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }

    }    
        return 0;
}