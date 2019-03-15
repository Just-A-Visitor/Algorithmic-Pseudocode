#include<stdio.h>
int main(){
    float x1,y1,x2,y2,x3,y3;//co-ordinates//
    scanf("%f%f",&x1,&y1);
    scanf("%f%f",&x2,&y2);
    scanf("%f%f",&x3,&y3);
    float z=(x3-x1)*(x3-x2)+(y3-y1)*(y3-y2);//Since, the equation of the circle g(c) is (x-x1)(x-x2) + (y-y1)(y-y2)//
    if(z>0)
    printf("Outside");//Since, g(c)>0//
    else
    if(z<0)
    printf("Inside");//Since, g(c)<0//
    else
    printf("On the boundary");//Since, g(c)=0//
    return 0;
}
