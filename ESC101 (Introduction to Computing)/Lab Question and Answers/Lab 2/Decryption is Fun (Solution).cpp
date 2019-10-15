#include<stdio.h>
int main(){
    char a,b;
    scanf("%c%c",&a,&b);
    char x=a-32;/*To convert it into A(ASCII Value)*/
    int y=(int)b-(int)a;
    char z=b-32;/*To convert it into A(ASCII Value)*/
    printf("%c%d%c",x,y,z);
    
    return 0;
}
