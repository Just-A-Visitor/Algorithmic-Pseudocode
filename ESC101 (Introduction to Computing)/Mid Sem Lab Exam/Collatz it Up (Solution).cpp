#include<stdio.h>
int main(){
    int T, val[1000];
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        scanf("%d",&val[i]);      
    }
    for(int j=0; j<T; j++)
    {
        int flag=0;                         
        while(val[j]!=1)
        {
            if(val[j]%2==0)
            {
                val[j]=(val[j])/2;
                flag=flag+1;
            }
            else
            {
                val[j]=(3*val[j])+1;
                flag=flag+1;
            }
        }
        if(flag<=500)
        {
            printf("%d\n",flag);    
        }
        else
        {
            printf("Out of range");
        }
   }    
    return 0;
}
