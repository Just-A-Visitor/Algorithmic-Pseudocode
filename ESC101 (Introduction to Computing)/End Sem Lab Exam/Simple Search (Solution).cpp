#include<stdio.h>
/* the idea is to search using simple binary search and include the arr[mid] in any one of the 2 searches, so that it is not neglected. Also, if(start)>(end) return -1, means the number to be searched is itself the least.*/
long long int bin_search(long long int arr[10000], int start, int end, int k)
{
    /*base case*/
    if(start>end) return -1;
    if(start==end)
    {
        if(arr[end]==k || arr[end]<k) return end;
        else return end-1;
    }
    /* breaking into two parts, one which includes mid also*/
    int mid=(start+end)/2;
    if(arr[mid]>k) return bin_search(arr, start,mid,k);
    if(arr[mid]<k) return bin_search(arr,mid+1,end,k);
    /* if arr[mid]==key*/
    else return mid;
}
int main(){
    //declaring the int types//
    long long int arr[10000];
    long long int q,k,n;
    //scanning the inputs//
    scanf("%lld",&n);
    //filling the array//
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    //number of test cases//
    scanf("%lld",&q);
    //printing the desired values//
    for(int i=0; i<q; i++)
    {
        scanf("%lld",&k);
        long long int z=bin_search(arr,0,n-1,k);
        printf("%lld\n",z);
    }
    return 0;
}
