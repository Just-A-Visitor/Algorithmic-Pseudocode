#include<stdio.h>
void spiral(int mat[1000][1000], int i, int j, int n)
{
    int flag=0;
    for(int z=i; z<n; z++)
    {
        printf("%d ",mat[i][z]); flag=1;
    }
    for(int z=i+1; z<n; z++)
    {
        printf("%d ",mat[z][n-1]); flag=1;
    }
    for(int z=n-2; z>=j; z--)
    {
        printf("%d ",mat[n-1][z]); flag=1;
    }
    for(int z=n-2; z>i; z--)
    {
        printf("%d ",mat[z][j]); flag=1;
    }
    if(flag==0) return;
    else return spiral(mat,i+1,j+1,n-1);
}
int main()
{
    int n, mat[1000][1000];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    spiral(mat,0,0,n);
    return 0;
}
