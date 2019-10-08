#include<stdio.h>
int cal;
long long int ack(int m, int n)
{
    cal++;
    if(m==0)
    {
        return n+1;
    }
    if(m>0 && n==0)
    {
        return ack(m-1,1);
    }
    else
    {
        return ack(m-1,ack(m,n-1));
    }
}
int main(){
    cal=0;
    int m,n,t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&m,&n);
        printf("%lld %d\n",ack(m,n),cal);
        cal=0;
    }
    return 0;
}
