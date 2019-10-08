#include<stdio.h>
int substr(char str1[1000],char str2[1000], int n2, int i)
{
    for(int j=0; j<n2; j++)
    {
        if(str1[i]!=str2[j])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main(){
    char str1[1000], str2[1000];
    int n1, n2, z, i=0;
    int ch=getchar();
    while(ch!='\n')
    {
        str1[i]=ch; i++; ch=getchar();
    }
    n1=i; i=0; ch=getchar();
    while(ch!='\n')
    {
        str2[i]=ch; i++; ch=getchar();
    }
    n2=i;
    if(n2>n1)
    {
        printf("NO");
    }
    else
    {
        for(int i=0; i<=n1-n2; i++)
        {
            z=substr(str1, str2,n2,i);
            if(z==1)
            {
               printf("YES"); break;
            }
        }
        if(z==0)
        {
            printf("NO");
        }
    }
    return 0;
}

