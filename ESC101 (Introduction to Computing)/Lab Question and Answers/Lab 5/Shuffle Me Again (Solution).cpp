#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    char a[n];
    int b[n];
    char c[n];
    for(int i=0; i<n; i++)
    {
        scanf(" %c",&a[i]);
    }
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&b[j]);
            c[j]=a[b[j]-1];
        }
        
        for(int x=0; x<n; x++)
        {
           a[x]=c[x];
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%c",a[i]);
    }
    return 0;
}

