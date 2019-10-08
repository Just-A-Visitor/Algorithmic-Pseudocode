#include<stdio.h>
void intensity(int c)
{
    switch(c)
    {
        case 0:printf(" "); break;
        case 1:printf("."); break;
        case 2:printf(":"); break;
        case 3:printf("-"); break;
        case 4:printf("~"); break;
        case 5:printf("="); break;
        case 6:printf("+"); break;
        case 7:printf("?"); break;
        case 8:printf("|"); break;
        case 9:printf("7"); break;
        case 10:printf("S"); break;
        case 11:printf("0"); break;
        case 12:printf("K"); break;
        case 13:printf("8"); break;
        case 14:printf("Z"); break;
        case 15:printf("N"); break;
        case 16:printf("M"); break;
        case 17:printf("#"); break;
    }
}
int main(){
    int ht,wdth, temp;
    scanf("%d %d",&ht,&wdth);
    for(int i=0; i<ht; i++)
    {
        for(int j=0; j<wdth; j++)
        {
            scanf("%d",&temp);
            intensity(temp);
        }
        printf("\n");
    }
    
    return 0;
}


