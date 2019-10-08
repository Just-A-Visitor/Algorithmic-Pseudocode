#include<stdio.h>
#include<stdlib.h>
int count_em(int arr[1000],int n)
{
    int sum=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
        int z=abs(arr[j]-arr[i]);
        sum=sum + (z<(j-i)?1:0);
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[1000];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",count_em(arr,n));
    return 0;
}
