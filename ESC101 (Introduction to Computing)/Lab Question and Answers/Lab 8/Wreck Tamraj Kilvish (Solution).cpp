#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char arr[100][100];
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n; j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }
    for(int x=n-1; x>=0; x--)
    {
        int g=x;
       for(int j=0; (j<n && g<n);j++)
       {
           printf("%c",arr[g][j]); g++;
       }
       if(x!=0) printf(" ");
    }
    return 0;
}


