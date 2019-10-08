#include<stdio.h>
int sum_prdct(int sum[1000], int product[1000],int i ,int j)
{
    int a,b;
    if(i==0)
    {
        a=sum[j];
        b=product[j];
    }
    else
    {
        a=sum[j]-sum[i-1];
        b=product[j]/product[i-1];
    }
    if(a==b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(){
    int n,k=0,sum[10000],product[10000];
    scanf("%d",&n);
    int arr[10000];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int s=0, prdct=1;
    for(int i=0; i<n; i++)
    {
        s=s+arr[i];
        prdct=prdct*arr[i];
        sum[i]=s;
        product[i]=prdct;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            k=k+sum_prdct(sum, product,i,j);
        }
    }
    printf("%d",k);
    return 0;
}

