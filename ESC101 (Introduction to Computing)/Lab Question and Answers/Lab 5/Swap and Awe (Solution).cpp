#include<stdio.h>

int main()
{
    int n,m,x,y,temp=0;
    int a[1000];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&x,&y);
        temp=a[x];
        a[x]=a[y];
        a[y]=temp;
    }
    for(int j=0; j<n-1; j++)
    {
        printf("%d,",a[j]);
    }
    printf("%d",a[n-1]);
    return 0;
}

