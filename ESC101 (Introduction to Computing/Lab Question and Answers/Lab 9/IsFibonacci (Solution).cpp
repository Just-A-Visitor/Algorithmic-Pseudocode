#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
   if(n==0)
   {
       return 0;
   }
   if(n==1)
   {
       return 1;
   }
   else
   return fib(n-1)+fib(n-2);
}

void check(int key,int a[])
{
    int flag=0;
    for(int i=0; i<20; i++)
    {
        if(a[i]==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}
int main()
{
    int key,a[20],t;
    scanf("%d",&t);
    for(int i=0; i<20; i++)
    {
        a[i]=fib(i);
    }    
    for(int i=0; i<t; i++)
    {
        scanf("%d",&key);
        check(key,a);
    }
    return 0;
}
