#include<stdio.h>
int a,b,c,d;//Declaring the global variables//
int mult(int ar[a][b], int br[c][d], int s, int i, int j)
{
    int z=0;
    for(int k=0; k<s; k++)//s is the no. of column of 1st matrix//
    {
        z=z+ar[i][k]*br[k][j];//applying the formula tof ind the value
    }
    return z;
}
int main(){

    scanf("%d %d",&a,&b);//Scanning the inputs//
    int arr1[a][b];
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            scanf("%d",&arr1[i][j]);//filling the matrices//
        }
    }
    scanf("%d %d",&c,&d);
    int arr2[c][d];
    int mat[a][d];//Defining a new array//
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<d; j++)
        {
            scanf("%d",&arr2[i][j]);//filling the values//
        }
    }
if(b!=c)
{
    printf("INVALID INPUT");//checking the validity//
}
else
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<d; j++)
        {
            mat[i][j] = mult(arr1, arr2, b, i, j);//taking the values//
            printf("%d ",mat[i][j]);//printing//
        }
        printf("\n");
    }
}
    return 0;
}
