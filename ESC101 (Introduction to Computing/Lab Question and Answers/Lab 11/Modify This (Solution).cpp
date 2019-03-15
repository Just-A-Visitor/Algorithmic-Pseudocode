#include <stdio.h>
void Increment( int *p1, int delta){
    *p1=*p1+delta;//Declaring the functions//
}

int main(){
    int n,m, arr[10000],delta,x;
    scanf("%d %d",&n,&m);//scanning the inputs
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);//filling the array
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&x,&delta);
        Increment(arr+x,delta);//using the functions
    }
    for(int i=0; i<n-1; i++)
    {
        printf("%d,",arr[i]);//printing the values.
    }
    printf("%d",arr[n-1]);//for avoiding the last comma//
    return 0;
}
