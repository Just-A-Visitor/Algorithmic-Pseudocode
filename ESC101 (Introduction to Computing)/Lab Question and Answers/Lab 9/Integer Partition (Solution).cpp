#include<stdio.h>
int arr[10000],x;
void part(int n, int j, int x)
{
    if(n==0)
    {
        for(int i=0; i<x; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n"); return;
    }
    else if(n>0)    
    {
            for(int i=j; i<=n; i++)
        {
            arr[x]=i;
            part(n-i,i,x+1);
        }
    }
    return;
}
int main(){
    int n,x=0;
    scanf("%d",&n);
    for(int j=1; j<=n/2; j++)
    {
        arr[x]=j;
        part(n-j,j,x+1);
    }
    return 0;
}
