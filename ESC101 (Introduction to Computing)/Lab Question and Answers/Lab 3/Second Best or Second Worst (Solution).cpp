#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);
    if(a,b,c>=-1000 && a,b,c<=1000)//Checking the outputs//
    {
    
    if(a>b && a>c)
    {
        if(b>c)
        printf("%d",b);
        else
        printf("%d",c);
        
    }
    else
    {
        if(b>a && b>c)
        {
            if(a>c)
            printf("%d",a);
            else
            printf("%d",c);
            
            }
            else
            {
                if(c>a && c>b)
                {
                    if(a>b)
                    printf("%d",a);
                    else
                    printf("%d",b);
                }
            }
   
   if(a==b)
   printf("%d",a);
   else
   if(a==c)
   printf("%d",a);
    }
        
    }
    else
    printf("Invalid Entry");
   return 0;
}

