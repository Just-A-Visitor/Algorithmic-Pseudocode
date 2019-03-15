#include <stdio.h>
#include<stdlib.h>
void BitFlip( int *p )
{
    if(*p==1) *p=0;
    else *p=1;
}

int main(){
    int n, m, t;
    scanf("%d %d",&n,&m);
    int *p;
    p=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d",p+i);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d",&t);
        BitFlip(p+t);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d",*(p+i));
    }
    free(p);
    return 0;
}




