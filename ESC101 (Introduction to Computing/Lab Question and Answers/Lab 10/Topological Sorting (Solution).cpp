#include<stdio.h>
int main(){
    int n,j;
    scanf("%d",&n);
    int flag[n], mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0; i<n; i++) { flag[i]=0; }
    for(int num=0; num<n; num++)
    {
        for(int i=0; i<n; i++)
        {
            if(flag[i]==1)  { continue; }
            for(j=0; j<n; j++)
            {
                if(mat[i][j]==1) { break; }
            }
            if(j==n)
            {
                flag[i]=1;
                for(int x=0; x<n; x++)
                {
                    mat[x][i]=0;
                }
                printf("%d ",i+1); break;
            }
        }
    }
    return 0;
}


