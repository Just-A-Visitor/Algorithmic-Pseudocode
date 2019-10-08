#include <stdio.h>
void swap(int arr[1000],int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[1000];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0], min=arr[0],min_flag=0, max_flag=0;
    for(int i=1; i<n; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            max_flag=i;
        }
        if(min>arr[i])
        {
            min=arr[i];
            min_flag=i;
        }
    }
    swap(arr,max_flag,min_flag);
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("end"); //do not modify this
    return 0;
}

