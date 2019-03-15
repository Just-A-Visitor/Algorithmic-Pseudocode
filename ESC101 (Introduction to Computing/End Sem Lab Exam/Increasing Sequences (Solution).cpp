#include<stdio.h>
/* The idea is to place a 'for loop' inside the function which overwrites the value of array to be printed such that every element to be printed is greater than previous one, and when length of array becomes k, print it.*/
void seq(int n, int k, int arr[10000], int j, int x)
{
    /* printing the array-- base case*/
    if(x==k)
    {
        for(int i=0; i<k; i++)
        {
            printf("%d",arr[i]);
        }
        printf("\n"); return;
    }
    /*considering all elemnts greater than previous*/
    for(int i=j+1; i<=n; i++)
    {
        arr[x]=i;
        seq(n,k,arr,i,x+1);
    }
}
int main(){
    /* declaring the variables*/
    int k,n;
    /* scanning the inputs*/
    scanf("%d %d",&k,&n);
    /*declaring the array to store values*/
    int arr[k];
    /* printing the sequence*/
    seq(n,k,arr,0,0);
    return 0;
}


