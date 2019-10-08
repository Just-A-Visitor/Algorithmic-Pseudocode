#include<stdio.h>
char arr[5][5];
int path(int i, int j)
{
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    if(arr[i][j]=='.')
    {
        return path(i-1,j) +path(i,j-1);
    }
    else return 0;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }
    printf("%d",path(m-1,n-1));
    return 0;
}

