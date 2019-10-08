#include <stdio.h>
int main() {
    int flag[10000]={0}, n1, n2, arr1[1000], arr2[1000];
    scanf("%d %d",&n1,&n2);
    for(int i=0; i<=n1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(int j=0; j<=n2; j++)
    {
        scanf("%d",&arr2[j]);
    }
    for(int i=0; i<=n1; i++)
    {
        for(int j=0; j<=n2; j++)
        {
            flag[i+j]=flag[i+j]+arr1[i]*arr2[j];
        }
    }
    printf("%d\n",n1+n2);
    for(int i=0; i<=n1+n2; i++)
    {
        printf("%d ",flag[i]);
    }
    return 0;
}
