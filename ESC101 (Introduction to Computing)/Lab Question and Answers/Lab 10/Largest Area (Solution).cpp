#include<stdio.h>
int arr[100][100],n,m;
int prdct(int i, int j, int row, int col)
{
    for(int x=i; x<i+row; x++)
    {
        for(int y=j; y<j+col; y++)
        {
            if(arr[x][y]==0) return 0;
        }
    }
    return row*col;
}
int sub_mat(int row, int col)
{
    int temp_1;
    for(int i=0; i<=n-row; i++)
    {
        for(int j=0; j<=m-col; j++)
        {
            temp_1=prdct(i,j,row,col);
            if(temp_1!=0) return temp_1;
        }
    }
    return 0;
}
int main()
{
    int temp_3=0,z;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int row=1; row<=n; row++)
    {
        for(int col=1; col<=m; col++)
        {
            z=sub_mat(row,col);
            //printf("%d ",z);
            if(z>temp_3) temp_3=z;;
        }
    }
    printf("%d",temp_3);
    return 0;
}

