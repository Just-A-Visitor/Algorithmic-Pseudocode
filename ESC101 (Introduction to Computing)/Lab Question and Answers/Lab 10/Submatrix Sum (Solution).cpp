#include<stdio.h>
int arr[100][100],m,n;
int sum(int i, int j, int row, int col)
{
    int temp_2=0;
    for(int x=i; x<(i+row); x++)
    {
        for(int y=j; y<(j+col); y++)
        {
            temp_2 +=arr[x][y];
        }
    }
    return temp_2;
}
int sub_mat(int row, int col)
{
    int temp_1=0;
    for(int i=0; i<=m-row; i++)
    {
        for(int j=0; j<=n-col; j++)
        {
            temp_1 +=sum(i,j,row,col);
        }
    }
    return temp_1;
}
int main(){
    int final_sum=0;
    scanf("%d %d",&m,&n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int row=1; row<=m; row++)
    {
        for(int col=1; col<=n; col++)
        {
            final_sum +=sub_mat(row,col);
        }
    }
    printf("%d",final_sum);
    return 0;
}


