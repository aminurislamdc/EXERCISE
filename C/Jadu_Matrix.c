#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int Jadu_Matrix[r][c];
    for (int a = 0; a < r; a++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d",&Jadu_Matrix[a][j]);
        }
        
    }
    int jannat=1;
    if (r != c)
    {
        jannat=0;
    }
    for (int a = 0; a < r; a++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((a==j || a+j == r-1) && Jadu_Matrix[a][j]!=1)
            {
                jannat=0;
            }
            if (a!=j && a+j != r-1 && Jadu_Matrix[a][j]!=0)
            {
                jannat=0;
            }
            
        }
        
    }
    
    if (jannat==1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    
   
    
    return 0;
}