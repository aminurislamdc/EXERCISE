#include<stdio.h>
int main()
{
    int initial, given, bought, b=0, c=0;
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&a[i]);
    }
    initial = a[0];
    given = a[1];
    bought = a[2];
    b=initial-given;
    c=b+bought;
    printf("%d",c);
    
    return 0;

}