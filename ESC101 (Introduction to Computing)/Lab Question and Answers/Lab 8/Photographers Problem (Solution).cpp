#include<stdio.h>
int n;
void swap(int a[][n],int i, int j)
{
    int temp=0;
    temp=a[i][j];
    a[i][j]=a[j][i];
    a[j][i]=temp;
}
int main(){

    scanf("%d",&n);
    int a[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(i!=j)
            {
                swap(a,i,j);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",a[n-i-1][j]);
        }
        printf("\n");
    }
    return 0;
}
