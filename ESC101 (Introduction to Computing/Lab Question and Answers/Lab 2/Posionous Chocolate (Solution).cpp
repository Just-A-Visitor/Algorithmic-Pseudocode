#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    
    if(m==n)
    {
        printf("1");
    }
    else
    
        printf("0");
    /*The main concept behind this is the formation of a square(or a symmetrical figure which could finally be cut down into a square).
    If Amlan starts with a square, he would definitely lose.(Anyone starting with a symmetrical figure will lose.)This gives the output as 1.
    
    But, if he starts with an unsymmetrical figure ,his main purpose would be to turn the figure into a symmetrical one in his move so that once Nirbhay begins with it, he loses, giving the output "0." */
    return 0;
}
