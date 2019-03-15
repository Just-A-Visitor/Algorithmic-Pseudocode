#include<stdio.h>
#include<string.h>
void clean(char arr[1000], int i, int n)
{
    if(i==n-1)
    {
        printf("%c",arr[n-1]); return;
    }
    else
    {
        while(i<n-1 && arr[i]==arr[i+1])
        {
            i++;
        }
        printf("%c",arr[i]);
        clean(arr,i+1,n);
    }
}
int main()
{
    char str[1000];
    scanf("%s",str);
    int n=strlen(str);
    clean(str,0,n);
    return 0;
}

