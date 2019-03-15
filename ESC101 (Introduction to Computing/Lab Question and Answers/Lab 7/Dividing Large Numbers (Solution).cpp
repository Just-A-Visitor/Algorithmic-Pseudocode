#include<stdio.h>
int ans[10000],x,r;
void divide(int arr[],int n)
{
    for(int i=0; i<x; i++)
    {
        int z=10*r+arr[i];
        ans[i]=z/n; r=z%n;
    }
    
}
int main(){
    int arr[10000],n; x=0; r=0;
    int ch=getchar();
    while(ch!=' ')
    {
        arr[x]=ch-'0';  x++; ch=getchar();
    }
    scanf("%d",&n);
    divide(arr,n);
    int temp=0;
    while(ans[temp]==0)
    {
        temp++;
    }
    
    for(int i=temp; i<x; i++)
    {
        printf("%d",ans[i]);
    }
    printf(" %d",r);
    return 0;
}

// Write a function which takes as arguments the input dividend and divisor and performs the division
