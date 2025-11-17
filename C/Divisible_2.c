#include<stdio.h>
int main()
{
int N;
scanf("%d",&N);
if (21 <= N && N <= 10000)
{
for (int i = 1; i <= N; i++)
{
   if ( i%3==0 && i%7==0 )
{
   printf("%d\n",i);
}
}
}
}
