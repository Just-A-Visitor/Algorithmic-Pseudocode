#include<stdio.h>
#include<string.h>
int palindrome(char str[100000], int i, int j, int size)
{
    if(i>=j) return size;
    if(str[i]!=str[j]) return 0;
    else return palindrome(str,i+1,j-1,size);
}
int main(){
    char str[100000]; int sum,n;
    scanf("%s",str);
    n=strlen(str);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            sum=palindrome(str,j,n-1-i+j,n-i);
            if(sum>0)
            {
                i=n+30; break;
            }
        }
    }
    printf("%d",sum);
    return 0;
}

