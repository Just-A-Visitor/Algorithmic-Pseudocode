#include<stdio.h>
int main(){
    int m,n;
    float x1,x2,y1,y2;/*Co-ordinates*/
    scanf("%d %d", &m,&n);
    scanf("%f %f", &x1,&y1);
    scanf("%f %f", &x2,&y2);
    float x=(m*x2+n*x1)/(m+n);/*Co-ordinates of mysterious point*/
    float y=(m*y2+n*y1)/(m+n);
    printf("%.2f %.2f", x,y);
    return 0;;
    
}

