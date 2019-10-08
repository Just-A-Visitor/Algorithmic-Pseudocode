#include<stdio.h>

int main()
{
    int n,flag=0;
    scanf("%d",&n);
    char a[1000];
    for(int i=0; i<n; i++)
    {
        scanf(" %c",&a[i]);
    }
    for(int i=0; i<=n/2; i++)
    {
        if(a[i]!=a[n-1-i])
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    return 0;
}
