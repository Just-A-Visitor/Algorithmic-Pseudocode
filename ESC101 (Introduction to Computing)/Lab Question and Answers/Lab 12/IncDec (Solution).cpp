#include<stdio.h>
#include<stdlib.h>
/*The function find checks the existence of key, the parameter dir is the type of seq(1 for increasing 0 for decreasing)*/
int find(int *arr, int start, int end, int key, int dir)
{
    if(start>end) return 0;
    int mid=(start+end)/2;
    if(arr[mid]==key) return 1;
    if(dir==1)
    {
          if(arr[mid]>key) return find(arr,start,mid-1,key,1);
          if(arr[mid]<key) return find(arr,mid+1,end,key,1);
    }
    else
    {
        if(arr[mid]<key) return find(arr,start,mid-1,key,0);
        if(arr[mid]>key) return find(arr,mid+1,end,key,0);
    }
}
/*The function find_ind_pivot finds the index of pivot element*/
int find_ind_pivot(int *arr,int start, int end)
{
    int mid=(start+end)/2;
    if(mid==0) return mid;
    if(arr[mid]>arr[mid-1])
    {
        if(arr[mid]>arr[mid+1])
        {
            return mid;
        }
        else return find_ind_pivot(arr,mid,end);
    }
    else
    {
        return find_ind_pivot(arr,start,mid);
    }
}
int main(){
    int n,q,key;
    //scanning the inputs//
    scanf("%d",&n);
    int *arr;
    //memory allocation through malloc;
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d",arr+i);
    }
    //find pivot//
    int piv=find_ind_pivot(arr,0,n-1);
    //check the no. of queries//
    scanf("%d",&q);
    //printing the conditions//
    for(int i=0; i<q; i++)
    {
        scanf("%d",&key);
    int ans=find(arr,0,piv,key,1)||find(arr,piv,n-1,key,0);
        if(ans==1) printf("Yes\n");
        else printf("No\n");
    }
    //freeing the memory//
    free(arr);
    return 0;
}
