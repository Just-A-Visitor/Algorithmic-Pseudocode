#include<stdio.h>
int arr[100000],mat[100000],n, total;
int sum(int i, int j)
{
    if(i==j) return arr[i];
    if(i==0) return mat[j];
    if(j>=n) return total-mat[i-1]+mat[j%n];
    else return mat[j]-mat[i-1];
}
int main(){
    int ans[100000], z=0, max=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        z=z+arr[i]; mat[i]=z;
    }
    z=0; total=mat[n-1];
    for(int x=0; x<n-1; x++)
    {
        for(int i=0; i<n; i++)
        {
            ans[z]=total-sum(i,i+x);
            if(ans[z]>max)
            {
                max=ans[z];
            }
            z++;
        }
    }
    if(total>max) max=total;
    printf("%d",max);
    return 0;
}

