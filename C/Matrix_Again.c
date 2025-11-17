#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int M[r=r+2][c=c+2];
    for (int a = 2; a < r; a++)
    {
        for (int j = 2; j < c; j++)
        {
            scanf("%d",&M[a][j]);
        }
        
    }
    for (int i = 2; i < c; i++)
    {
        printf("%d ",M[r-1][i]);
    }
    printf("\n");
    for (int i = 2; i < r; i++)
    {
        printf("%d ",M[i][c-1]);
    }
    
    
    return 0;
}