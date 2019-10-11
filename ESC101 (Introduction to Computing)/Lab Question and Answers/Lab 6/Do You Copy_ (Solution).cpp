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
            int N,n,r;
            int a[100];
            scanf("%d",&N);
            for(int i=0; i<N; i++)
            {
                scanf("%d %d",&n,&r);
                int x=fact(n);
                int y=fact(r);
                int z=fact(n-r);
                int w=x/(y*z);
                a[i]=w;
            }
    for(int j=N-1; j>=0; j--)
    {
        printf("%d\n",a[j]);
    }
            
            
    return 0;
}

