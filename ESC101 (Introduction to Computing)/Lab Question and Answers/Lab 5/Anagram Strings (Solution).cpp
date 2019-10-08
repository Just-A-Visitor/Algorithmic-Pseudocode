#include <stdio.h>
int main(){
    
    char arr1[500], arr2[500];
    int flag[256]={0},temp=0;
    int i=0,n1, n2;
    scanf("%d %d",&n1,&n2);
    if(n1!=n2)
    {
        printf("no");
    }
    else
    {
        for(int i=0; i<n1; i++)
        {
            scanf(" %c",&arr1[i]);
        }
        for(int i=0; i<n2; i++)
        {
            scanf(" %c",&arr2[i]);
            flag[arr2[i]-'a']++;
        }
        for(int i=0; i<n1; i++)
        {
            if(flag[arr1[i]-'a']>0)
            {
                flag[arr1[i]-'a']--;
            }
            else
            {
                temp=1;
                break;
            }
        }
        if(temp==1)
        {
            printf("no");
        }
        else
        printf("yes");
    }
    return 0;
}
  
