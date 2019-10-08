#include <stdio.h>
#include<string.h>
char ans[1000]; int j,n;
swap(int arr[1000],int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void perm(char arr[], int i, int n,int j)
{
    if(i==n-1)
    {
        printf("%s\n",ans); return;
    }
    else
    {
        for(int k=0; k<n; k++)
        {
            swap(arr,k,j);
            perm(arr,k+1,n,j);
            swap(arr,k,j);
        }
    }
    
}

int main()
{
    char str[1000];
    scanf("%s",str);
    n=strlen(str);
    perm(str,0,n,0);
    return 0;
}


