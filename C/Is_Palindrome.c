#include<stdio.h>
#include<string.h>
int is_palindrome(char aminur[])
{
    char jannat[1000];
    int size = strlen(aminur);
    int j=0;
    for (int i = size-1; i >= 0; j++,i--)
    {
        jannat[j]=aminur[i];
        
    }
    jannat[j] = '\0';
    int d=strcmp(aminur,jannat);
    return d;
}
int main()
{
    char aminur[1000];
    scanf("%s",aminur);

    int d = is_palindrome(aminur);
    if (d==0)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    
    
    return 0;
}