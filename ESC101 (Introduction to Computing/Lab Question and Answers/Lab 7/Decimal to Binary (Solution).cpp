#include<stdio.h>
int count, len;
void div_2(int arr[100000])
{
    int r=0;
    for(int x=count; x<len; x++)
    {
        int z=10*r+arr[x]; r=z%2;
        arr[x]=z/2;
    }
    if(arr[count]==0) count++;
    return;
}
int main(){
    int ch=getchar(); int x=0, j=0, bin[100000], arr[100000]; count=0;
    while(ch!=EOF)
    {
        arr[j]=ch-'0';
        j++; ch=getchar();
    }
    len=j;
    while(count<len)
    {
       bin[x]=arr[len-1]%2; x++;
        div_2(arr);
    }
    for(int i=x-1; i>=0; i--)
    {
        printf("%d",bin[i]);
    }
    return 0;
}

