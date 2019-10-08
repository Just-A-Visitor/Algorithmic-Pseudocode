#include <stdio.h>
int ans[100000],n1,n2;
void merge(int arr1[],int arr2[], int i, int j, int x) {
    if(i==n1)
    {
        for(int z=j; z<n2; z++)
        {
            ans[x]=arr2[z]; x++;
        }
        return;
    }
    if(j==n2)
    {
        for(int z=i; z<n1; z++)
        {
            ans[x]=arr1[z]; x++;
        }
        return;
    }
    if(arr1[i]<arr2[j])
    {
        ans[x]=arr1[i];
        merge(arr1,arr2,i+1,j,x+1);
    }
    else
    {
        ans[x]=arr2[j];
        merge(arr1,arr2,i,j+1,x+1);
    }
    return;
}

int main() {
    int arr1[10000],arr2[10000];
    scanf("%d",&n1);
    for(int i=0; i<n1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&n2);
    for(int i=0; i<n2; i++)
    {
        scanf("%d",&arr2[i]);
    }
    merge(arr1,arr2,0,0,0);
    for(int i=0; i<n1+n2; i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}

