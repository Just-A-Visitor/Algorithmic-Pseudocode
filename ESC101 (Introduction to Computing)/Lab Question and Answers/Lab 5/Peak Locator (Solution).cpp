#include <stdio.h>

int main()
{
    int n,temp=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1; i<n-1; i++)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            temp=temp+1;
        }
    }
    printf("%d",temp);
    return 0;
}

