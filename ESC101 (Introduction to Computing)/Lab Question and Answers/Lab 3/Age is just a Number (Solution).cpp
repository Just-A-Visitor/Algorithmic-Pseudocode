#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<0){
        printf("How are you here?");
    }else
    if(n>=0 && n<30){
        printf("Youth");
    }else
    if(n>=30 && n<40){
        printf("Getting Old");
    }else
    if(n>=40 && n<60){
        printf("Almost Old");
    }else
    if(n>=60 && n<100){
        printf("Old");
    }else
    if(n>=100 && n<150){
        printf("Very Old");
    }
    else
    printf("Die Already");
    
    return 0;
}

