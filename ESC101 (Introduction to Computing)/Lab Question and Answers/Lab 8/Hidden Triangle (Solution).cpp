#include<stdio.h>
int main(){
    int n, mat[1000][1000], flag=1;
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
        for(int j=i+1; j<n; j++)
        {
            if(mat[i][j]!=0)
            {
                flag=0; break;
            }
        }
    }
    if(flag==0)
    {
        printf("NOT FOUND");
    }
    else
    printf("FOUND TRIANGLE");
    return 0;
}
