#include<stdio.h>
int main()
{
   int n, sum=1,max_1=0,flag=0;
   scanf("%d",&n);
   char arr[n],temp;
   for(int i=0; i<n; i++)
   {
       scanf(" %c",&arr[i]);
   }
   int i=0;
   for(i=0; i<n-1;i++)
   {
       if(arr[i]==arr[i+1])
       {
           sum++;
       }
       else
       {
           flag=1;
           if(sum>max_1)
           {
               max_1=sum;
               temp=arr[i];
               sum=1;
           }
           else
           {
               sum=1;
           }
       }
   }
   if(sum>max_1) { printf("%c",arr[n-1]); }
   else
   {
         printf("%c",temp);
   }
 
    return 0;
}

