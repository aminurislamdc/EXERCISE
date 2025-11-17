#include<stdio.h>
int main()
{
    int x,p;
    float aminur=0,jannat=0,jaren=0;
    scanf("%d %d",&x,&p);
    aminur=100-x;
    jannat=p/aminur;
    jaren=jannat*100;
    printf("%.2f",(jaren));


    return 0;
}