#include<stdio.h>
#include<string.h>
void par(char arr[1000], int i, int len)
{
    if(arr[i]!='(')
    {
        return par(arr,i+1,len);
    }
    else
    {
        while(arr[i]!=')')
        {
            printf("%c",arr[i]);
            i++;
        }
    printf("%c",')');
    }
}
int main(){
    int len; char arr[1000];
    scanf("%s",arr);
    len=strlen(arr);
    par(arr,0,len);
    return 0;
}



