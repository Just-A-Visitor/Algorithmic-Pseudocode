#include<stdio.h>
#include<string.h>
void ast(char arr[1000],int i, int len)
{
    if(i==len-1)
   {
       printf("%c",arr[len-1]);
       return;
   }
   else
   {
       if(arr[i]==arr[i+1])
        {
            printf("%c*",arr[i]);
            ast(arr,i+1,len);
        }
        else
        {
            printf("%c",arr[i]);
            ast(arr,i+1,len);
        }
    }
 }
int main(){
    char array[1000];
    scanf("%s",array);
    int len=strlen(array);
    ast(array,0,len);
    return 0;
}
