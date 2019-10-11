#include<stdio.h>
int main(){
    int n, a[10000], flag[20]={0};
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);  flag[a[i]]++;
    }
    for(int i=0; i<20; i++)
    {
        printf("%d,",flag[i]);
    }
    printf("\n");
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<flag[i]; j++)
        {
            printf("%d,",i);
        }
    }
    
    return 0;
}
