#include<stdio.h>
int main(){
    int m;
    scanf("%d",&m);
    int c=100*m + 10*m +m;
    int d=10000*m + 1000*m +100*m + 10*m + m;
    printf("%3d\n%4d\n%d\n%4d\n%3d\n",m,c,d,c,m);
    
    return 0;
}
