# include <stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int sum=0;
    int i=a;
    for(; i<=b;i++){
        sum=sum+i;
    }
    printf ("%d",sum);
    return 0;
}


