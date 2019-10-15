#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, min_flag=0, max_flag=0;
    scanf("%d",&n);
    int a[1000];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int max=a[0], min=a[0];
    for(int i=1; i<n; i++)
    {
        if(max<a[i])
        {
            max=a[i]; max_flag=i;
        }
        if(min>a[i])
        {
            min=a[i]; min_flag=i;
        }
    }
    
    int k=max_flag-min_flag;
    printf("%d",abs(k));
    return 0;
    
}


