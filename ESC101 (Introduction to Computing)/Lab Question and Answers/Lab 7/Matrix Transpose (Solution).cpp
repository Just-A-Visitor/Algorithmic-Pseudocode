#include<stdio.h>
int main(){
    int m,n;
    int a[10000];//Since, the input array is of size m*n
    scanf("%d %d",&m,&n);//Scanning the outputs
    for(int i=0; i<m*n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int k=0; k<n; k++)
    {
            for(int i=k; i<n*m; i=i+n)//Since, every element is of the form of i+n ;
            {
                printf("%d,",a[i]);
            }
    printf("\n");
    }
    return 0;
}
