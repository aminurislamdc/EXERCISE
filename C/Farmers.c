#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    
    for (int i = 0; i < t; i++)
        {
        int aminur,jannat,day;
        scanf("%d %d %d",&aminur, &jannat, &day);
        int work_in_a_day=0,complete_work=0,rasult=0,totel_man=0;
        work_in_a_day = aminur*day;
        totel_man = aminur + jannat;
        complete_work = work_in_a_day/totel_man;
        rasult = day - complete_work;
        printf("%d\n",rasult);
        }

    return 0;
}