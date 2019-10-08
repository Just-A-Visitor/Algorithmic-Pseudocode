#include<stdio.h>
int main(){
    float l;
    scanf("%f",&l);
    float z=1.73205;
    float h=(z*l)/2;
    float a=(z*l*l)/4;
    printf("%.2f %.2f",h,a);
    return 0;
}
