#include<stdio.h>
int main(){
    char input=0; int S1=0,S2=0,S3=0,S4=0,S5=0,S6=0,S7=0;
    while(input!='O')
    {
        scanf("%c",&input);
        if(input=='T')
        {
            S1=S1+1;
        }
        if(input=='S')
        {
            S2=S2+1;
        }
        if(input=='F')
        {
            S3=S3+1;
            
        }
        if(input=='P')
        {
            S4=S4+1;
        }
        if(input=='D')
        {
            S5=S5+1;
        }
        if(input=='N')
        {
            S6=S6+1;
        }
        if(input=='I')
        {
            S7=S7+1;
        }
    }
    if(S1==3 && S2==1 && S3<=6 && S5<=30 && S6>=3 && S7>=3)
    {
        printf("DOCTOR");
    }
    else
    printf("NOT A DOCTOR");
    return 0;
}


