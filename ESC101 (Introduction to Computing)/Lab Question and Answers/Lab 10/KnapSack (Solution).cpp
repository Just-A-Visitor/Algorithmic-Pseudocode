#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int knap(int cost[1000], int wt[1000],int n, int size)\
{
    if(n<=0 || size<=0) return 0;
    if(wt[n-1]>size) return knap(cost,wt,n-1,size);
    else
    {
        return max((cost[n-1]+knap(cost,wt,n-1,size-wt[n-1])), knap(cost,wt,n-1,size));
    }
}
int main(){
    int cost[1000],wt[1000],n,size,j=0;
    scanf("%d %d",&size,&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&cost[i]);
        scanf("%d",&wt[j]); j++;
    }
    int z=knap(cost,wt,n,size);
    printf("%d",z);
    return 0;
}

