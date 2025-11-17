// #include <stdio.h>

// int main() {
//     int N, num, positive_sum = 0, negative_sum = 0;

//     // Read the number of values
//     scanf("%d", &N);

//     // Process each number
//     for (int i = 0; i < N; i++) {
//         scanf("%d", &num);
//         if (num > 0) {
//             positive_sum += num;  // Add positive numbers
//         } else if (num < 0) {
//             negative_sum += num;  // Add negative numbers
//         }
//     }

//     // Output the sums
//     printf("%d %d\n", positive_sum, negative_sum);

// //     return 0;
// }
#include<stdio.h>
int main()
{
    int n, valu, sum_pos=0, sum_neg=0;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&valu);
        if (valu > 0)
        {
            sum_pos=sum_pos+valu;
        }
        else if (valu < 0)
        {
            sum_neg=sum_neg+valu;
        }
        
    }

    printf("%d %d",sum_pos,sum_neg);
    
    return 0;
}