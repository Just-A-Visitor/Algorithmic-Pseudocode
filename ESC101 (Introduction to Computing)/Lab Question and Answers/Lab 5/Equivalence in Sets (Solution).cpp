#include<stdio.h>
int main()
{
    int n,k,set=1,flag[1000]={0},arr[1000];
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int i=k;
    while(arr[i]!=k)
    {
        set++; i=arr[i];
    }
    printf("%d",set);
    return 0;
}

