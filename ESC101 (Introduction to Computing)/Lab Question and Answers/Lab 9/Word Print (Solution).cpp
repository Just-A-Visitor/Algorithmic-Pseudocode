#include <stdio.h>
#include<string.h>
char ans[1000]; int j;
void perm(char str[], int n, int j, int k)
{
    if(j==k)
    {
        printf("%s\n",ans); return;
    }
    else
{
        for(int i=0; i<n; i++){
            ans[j]=str[i];
            perm(str,n,j+1,k);
        }
    }
    
}

int main()
{
    int n,k;
    scanf("%d %d",&k,&n);
    char str[1000];
    scanf("%s",str);
    perm(str,n,0,k);
    return 0;
}



