#include<stdio.h>
#include<stdlib.h>
int **c;//defining a 2d matrix
/* the function mult_mat multiplies the matrix according to the given rules and returns the sum*/
int mult_mat(int **A, int l[3][3], int row, int col)
{
    int sum=0;
    for(int i=row; i<row+3; i++)
    {
        for(int j=col; j<col+3; j++)
        {
            sum+= (*(*(A+i)+j))*l[i-row][j-col];
        }
    }
    return sum;
}
/*THe function gen_convol convoluses the image, hence returning a pointer to pointer*/
int **gen_convol(int **A, int n, int k[3][3])
{
    for(int i=0; i<n-2; i++)
    {
        for(int j=0; j<n-2; j++)
        {
            *(*(c+i)+j)=mult_mat(A,k,i,j);
        }
    }
    return c;
}
int main(){
    int n;
    scanf("%d",&n);
    //allocating the memory
    int **ans; int **A; int k[3][3];
    c=(int**)malloc((n-2)*sizeof(int*));
    for(int i=0; i<n-2; i++)
    {
        c[i]=(int*)malloc((n-2)*sizeof(int));
    }
    //allocating the memory//
    A=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        A[i]=(int*)malloc(n*sizeof(int));
    }
    //scanning the inputs
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",*(A+i)+j);
        }
    }
    //scanning the inputs
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d",&k[i][j]);
        }
    }
    ans=gen_convol(A,n,k);
    //Printing the values//
    for(int i=0; i<n-2; i++)
    {
        for(int j=0; j<n-2; j++)
        {
            printf("%d ",*(*(ans+i)+j));
        }
        printf("\n");
    }
    //Freeing the memory//
    for(int i=0; i<n; i++)
    {
        free(*(A+i));
    }
    //freeing the memory//
    for(int i=0; i<n-2; i++)
    {
        free(*(c+i));
    }
    free(A); free(c);
    return 0;
}

