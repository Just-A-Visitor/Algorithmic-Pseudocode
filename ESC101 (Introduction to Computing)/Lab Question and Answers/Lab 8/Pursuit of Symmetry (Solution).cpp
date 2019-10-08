#include<stdio.h>
int main(){
    int n, flag=1, mat[1000][1000];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j]!=mat[j][i])
            {
                flag=0; break;
            }
        }
    }
    if(flag==0)
    {
        printf("Sorry Shaktimaan");
    }
    else
    printf("Happy Shaktimaan");
    return 0;
}

