#include<stdio.h>
int main()
{
    int A,division;
    scanf("%d",&A);
    division=A/1000;
    if (division%2==0)
        {
            printf("EVEN");
        }
        else
        {
            printf("ODD");
        } 

        return 0;
}