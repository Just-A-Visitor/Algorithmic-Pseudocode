#include<stdio.h>
int mat[1000][1000];
int max(int a,int b)
{
    return (a>b)?a:b;
}
int lcs(char str1[10000], char str2[10000],int n1, int n2)
{
    if(n1==0 || n2==0) return 0;// base case..
    if(str1[n1-1]==str2[n2-1])
    {
        return 1+mat[n1-1][n2-1];
    }
    else
    {
        return max(mat[n1-1][n2], mat[n1][n2-1]);
    }
}
int main(){
    int n1,n2; char str1[1000], str2[1000];
    scanf("%d %d",&n1,&n2);
    scanf("%s",str1);
    scanf("%s",str2);
    for(int i=0; i<100; i++)
    {
        mat[0][i]=0; mat[i][0]=0;// initialising
    }
    if(str1[0]==str2[0])
    {
        for(int i=1; i<100; i++)
        {
            mat[i][1]=1; mat[1][i]=1;//initialising
        }
    }
    else
    {
        for(int i=1; i<100; i++)
        {
            mat[i][1]=0; mat[1][i]=0;// initialising
        }
    }
    for(int i=2; i<=n1; i++)
    {
        for(int j=2; j<=n2; j++)
        {
            mat[i][j]=lcs(str1,str2,i,j);// finding the values of subproblems
        }
    }
    int z=mat[n1][n2];
    printf("%d",z);//printing the values
    return 0;
}


