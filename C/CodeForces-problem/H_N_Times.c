#include<stdio.h>
void Aminur_Islam(int n)
{
    for (int a = 0; a < n; a++)
    {
        int a,b;
        scanf("%d %c",&a,&b);
        for (int j = 0; j < a; j++)
        {
            printf("%c ",b);
        }
        printf("\n");
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    Aminur_Islam(n);

    return 0;
}