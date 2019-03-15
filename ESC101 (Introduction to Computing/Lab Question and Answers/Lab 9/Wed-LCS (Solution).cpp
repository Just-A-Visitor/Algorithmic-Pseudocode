#include<stdio.h>
#include<string.h>
int mat[100][100]; char str1[100], str2[100];
int max(int a, int b)
{
    return (a>b)?a:b;
}
int lcs(int n1, int n2)
{
    if(n1==0||n2==0) return 0;
    if(str1[n1-1]==str2[n2-1]) return 1+mat[n1-1][n2-1];
    else
    return max(mat[n1-1][n2], mat[n1][n2-1]);
}

void fill_mat(int n1, int n2)
{
    for(int i=0; i<=n1; i++)
    {
        for(int j=0; j<=n2; j++)
        {
            mat[i][j]=lcs(i,j);
        }
    }
}
int main()
{
    scanf("%s",str1);
    scanf("%s",str2);
    int n1= strlen(str1);
    int n2=strlen(str2);
    fill_mat(n1,n2);
    printf("%d",mat[n1][n2]);
    return 0;
}
