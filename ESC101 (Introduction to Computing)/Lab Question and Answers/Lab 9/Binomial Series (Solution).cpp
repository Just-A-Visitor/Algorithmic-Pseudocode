#include<stdio.h>
int count;
long long int bin(int n, int k)
{
    count++;
    if(n<k)
    {
        return 0;
    }
    if(k==0)
    {
        return 1;
    }
    return bin(n-1,k)+bin(n-1,k-1);
}
int main(){
    count=0;
    int n,k,t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&n,&k);
        printf("%lld %d",bin(n,k),count); count=0;
        printf("\n");
    }
    return 0;
}

