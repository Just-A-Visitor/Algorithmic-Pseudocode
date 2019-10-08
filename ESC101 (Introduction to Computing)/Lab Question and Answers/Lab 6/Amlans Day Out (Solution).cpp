#include<stdio.h>
int main(){
    int n,k,j=0;
    scanf("%d %d",&n,&k);
    int key[100]; char arr[1000],temp[1000];
    for(int i=0; i<n; i++)
    {
        scanf(" %c",&arr[i]);
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d",&key[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(j>=k)
        {
            j=0; i--; continue;
        }
        else
        {
            temp[i]=arr[i]+key[j];
            int val=temp[i];
            if(val>90)
            {
                val=val%90+64;
                temp[i]=val;
            }
            j++;
            printf("%c",temp[i]);
        }
    }
    
    return 0;
}
