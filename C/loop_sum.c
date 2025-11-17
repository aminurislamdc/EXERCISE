// #include<stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int sum=0;
//     for (int i = 1; i <= n; i++)
//     {
//         sum += i;
//     }
//     printf("%d\n",sum);
// }
// #include<stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int sum=0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (i%2==0)
//         {
//             sum += i;
//             printf("%d\n",sum);
//         }
        
//     }
//     printf("Totel%d ",sum);
// }

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        if (i%2==0)
        {
            printf("%d Even Number\n",i);
        }
        else
        {
            printf("%d odd Number\n",i);
        }
    }
}