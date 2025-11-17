#include<stdio.h>
int main()
{
    int N=0;
    scanf("%d",&N);
    if (N==1)
    {
         if (N%2!=0)
    {
        int n=N+5;
    int spac=n-1,hass=1;
    for (int i = 0; i < n; i++)
    {
        if (i==n)
        {
            return 0; 
        }
        else
        {
            for (int j = 0; j < spac; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < hass; a++)
        {
            printf("*");
        }
        
        if (hass==10+N)
        {
            printf("\n");
            break;
        }
        else
        {
            printf("\n");
            spac--;
            hass +=2;
        }
        
        
        }
        
    int again_spac=(hass/2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < again_spac; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < N; a++)
        {
            printf("*");
        }
        printf("\n");
    }
    }
    }
    }
    
    if (N==3)
    {
        if (N%2!=0)
    {
        int n=N+5;
    int spac=n-2,hass=1;
    for (int i = 0; i < n; i++)
    {
        if (i==n)
        {
            return 0; 
        }
        else
        {
            for (int j = 0; j < spac; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < hass; a++)
        {
            printf("*");
        }
        
        if (hass==10+N)
        {
            printf("\n");
            break;
        }
        else
        {
            printf("\n");
            spac--;
            hass +=2;
        }
        
        
        }
        
    }
    int again_spac=(hass/2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < again_spac; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < N; a++)
        {
            printf("*");
        }
        printf("\n");
    }
    }
    }
    
    if (N==5)
    if (N%2!=0)
    {
        int n=N+5;
    int spac=n-3,hass=1;
    for (int i = 0; i < n; i++)
    {
        if (i==n)
        {
            return 0;
        }
        else
        {
            for (int j = 0; j < spac; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < hass; a++)
        {
            printf("*");
        }
       
        if (hass==10+N)
        {
            printf("\n");
            break;
        }
        else
        {
            printf("\n");
            spac--;
            hass +=2;
        }
       
       
        }
       
    }
    int again_spac=(hass/2)-1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < again_spac; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < N; a++)
        {
            printf("*");
        }
        printf("\n");
    }
    }

    return 0;
}