#include<stdio.h>
int main(){
    int r,h;/*(Radius and Height)*/
    scanf("%d%d",&r,&h);
    float pi=3.14159;
    float CSA=2*pi*r*h;/*(Curved Surface Area)*/
    float TSA=2*pi*r*h+2*pi*r*r;/*(Total Surfce Area)*/
    float VOL=pi*r*r*h;/*(Volume)*/
    printf("Curved Surface Area : %.2f\n",CSA);
    printf("Total Surface Area : %.2f\n",TSA);
    printf("Volume : %.2f\n",VOL);
    
    

return 0;
}
