#include<stdio.h>
int main(){
    int m,n;
    char input=0;
    scanf("%d %d\n",&m,&n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++){
            scanf(" %c",&input);
        if(input=='B')
        {
            printf("%d %d", i,j);
        }
        }
    }
    return 0;
}

