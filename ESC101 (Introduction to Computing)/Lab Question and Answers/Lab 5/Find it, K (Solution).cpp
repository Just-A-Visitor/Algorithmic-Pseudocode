#include <stdio.h>

int main()
{
    int n, k, temp=0;
    scanf("%d %d",&n,&k);
    int ar[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ar[i]+ar[j]==k)
            {
                temp=temp+1;
            }
        }
    }
    printf("%d",temp);
    return 0;
}

