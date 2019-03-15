#include<stdio.h>
int count;
long long int d(int n)
{
    count++;
    if(n<2)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    return (n-1)*(d(n-1) + d(n-2));
}
int main(){
    count=0;
    int n,t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d",&n);
        printf("%lld %d",d(n),count); count=0;
        printf("\n");
    }
    return 0;
}
