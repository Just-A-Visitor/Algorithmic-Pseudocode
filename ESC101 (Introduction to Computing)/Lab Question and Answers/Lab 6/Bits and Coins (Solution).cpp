#include<stdio.h>
int fact(int k)
{
    int fact=1;
    for(int i=k; i>=1; i--)
    {
        fact=fact*i;
    }
    return fact;
}
int main(){
    int N,flag=1, k=0, sum=0;
    int t[1000];
    scanf("%d",&N);
    int a[N];
    for(int i=0; i<N; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<N-1; i++)
    {
        if(a[i+1]>a[i])
        {
            flag=flag+1;
            
        }
        else
        {
            t[k]=flag;
            k++;
            flag=1;
        }
    }
    t[k]=flag;
    k++;
    for(int i=0; i<N-1; i++)
    {
        if(a[i+1]<a[i])
        {
            flag=flag+1;
            
        }
        else
        {
            t[k]=flag;
            k++;
            flag=1;
        }
    }
    t[k]=flag;
    for(int i=0; i<=k; i++)
    {
        if(t[i]==2)
            {
                sum=sum+1;
            }
    else
    if(t[i]!=1)
        {
            int x1=fact(t[i]);
            int x2=fact(t[i]-2);
            int x3=fact(2);
            int x4=x1/(x2*x3);
            sum=sum+x4;
        }
    }
    printf("%d",sum);
    return 0;
}

