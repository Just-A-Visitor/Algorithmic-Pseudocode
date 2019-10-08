#include<stdio.h>
int main(){
    int k1,k2,k3;
    scanf("%d%d%d",&k1,&k2,&k3);//Input//
    if(k1,k2,k3>=0 && k1,k2,k3<=100)
    {
    char c; int z;
    scanf(" %c",&c);
    if(c>='a' && c<='z')//Checking the conditions//
    {
    c=c+k1;//If the character is a lowercase alphabet [a-z], rotate it by k1 places//
    
    if((int)c>122)
    c=((c-122)%26+96);
    printf("%c",c);
        
    }
    else
    if(c>='A' && c<='Z')//Checking the conditions//
    {c=c+k2;//If the character is an uppercase alphabet [A-Z], rotate it by k2 places If the character is a digit [0-9], rotate it by k3 places//
    
    z=c;
    if(z>90)
    z=((z-90)%26)+64;
    printf("%c", (char)z);}
    
    else
    if(c>='0' && c<='9')//Checking the conditions//
    {
        c=c+k3;//If the character is a digit [0-9], rotate it by k3 places//
        
        z=c-'0';
        if(z>=10)
        z=z%10;
        printf("%d",z);
        
    }
    else
    printf("Invalid Entry");//If the input is not according to the standards//
    }
    else
    printf("The input exceeds the specified range");


    return 0;
}
