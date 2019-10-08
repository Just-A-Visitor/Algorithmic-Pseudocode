#include<stdio.h>
int sub_sum(int arr[1000],long long  int n, long long int k)
{
    if(n==1)
    {
        if(arr[0]==k) return 1;
        else return 0;
    }
    else
    {
        if(arr[n-1]==k)
        {
            return sub_sum(arr,n-1,k)+sub_sum(arr,n-1,k-arr[n-1]) +1 ;
        }
    else
    {
        return sub_sum(arr,n-1,k)+sub_sum(arr,n-1,k-arr[n-1]);
    }
}
}
int main()
{
    int arr[1000]; long long int n,k;
    scanf("%lld %lld",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    long long int z=sub_sum(arr,n,k);
    if(k==0) printf("%lld",z+1);
    else printf("%d",z);
    return 0;
}
