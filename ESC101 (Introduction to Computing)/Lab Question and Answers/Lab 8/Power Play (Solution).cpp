#include<stdio.h>
int mat[100][100];
int max(int a, int b, int c)
{
    int z;
    if(a>b)  z=(a>c)?a:c;
    else z=(b>c)?b:c;
    return z;
}
int main(){
    int h,w,arr[100][100], temp=0;
    scanf("%d %d",&h,&w);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int j=0; j<w; j++)
    {
        mat[0][j]=0; mat[h+1][j]=0;
    }
    for(int i=1; i<h+1; i++)
    {
        mat[i][0]=arr[i-1][0];
    }
    for(int j=1; j<w; j++)
    {
        for(int i=1; i<h+1; i++)
        {
            mat[i][j]=max(mat[i][j-1], mat[i+1][j-1], mat[i-1][j-1]) +arr[i-1][j];
        }
    }
    for(int i=1; i<h+1; i++)
    {
        if(mat[i][w-1]>temp)
        {
            temp=mat[i][w-1];
        }
    }
    printf("%d",temp);
    return 0;
}

