#include<stdio.h>
#include<string.h>
int flag_e, flag_l, flag_f,n;
void elfish(int i, char a[1000])
{
    if((a[i]=='e' && flag_l==0) && flag_f==0)
    {
        flag_e=1; return elfish(i+1,a);
    }
    if((a[i]=='l' && flag_e==1) && flag_f==0)
    {
        flag_l=1; return elfish(i+1,a);
    }
    if((a[i]=='f' && flag_e==1) && flag_l==1)
    {
        printf("Yes"); return;
    }
    else
    {
        if(i>n-1)
        {
            printf("No"); return;
        }
        else
        {
            return elfish(i+1,a);
        }
    }
}
int main(){
    flag_e=0; flag_l=0; flag_f=0;
    char arr[1000];
    scanf("%s",arr);
    n=strlen(arr);
    elfish(0,arr);
    return 0;
}
