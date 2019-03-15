#include <stdio.h>
#include<string.h>
int main(){
    
    char arr1[50000], arr2[50000];
    int flag[256]={0},temp=1;
    int i=0,n1, n2;
    scanf("%s",arr1); scanf("%s",arr2);
    n1=strlen(arr1);  n2=strlen(arr2);
    for(int i=0; i<n2; i++)
    {
        flag[arr2[i]-'a']++;
    }
    if(n1!=n2)
    {
        printf("FAIL");
    }
    else
    {
        for(int i=0; i<n1; i++)
        {
            if(flag[arr1[i]-'a']>0)
            {
                flag[arr1[i]-'a']--;
            }
            else
            {
                temp=0;
                break;
            }
        }
        if(temp==0)
        {
            printf("FAIL");
        }
        else
        printf("PASS");
    }
    return 0;
}
  

