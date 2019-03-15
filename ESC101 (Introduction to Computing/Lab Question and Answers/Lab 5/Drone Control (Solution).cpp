#include <stdio.h>
int pos[1000],k;
void drone(int arr[3],int command)
{
    switch(command)
    {
    case 1:arr[2]++; break;
    case 2:arr[2]--; break;
    case 3:arr[0]++; break;
    case 4:arr[0]--; break;
    case 5:arr[1]++; break;
    case 6:arr[1]--; break;
    default:break;
    }
    for(int j=0; j<3; j++)
    {
        pos[k]=arr[j]; k++;
    }
    return;
}
int main()
{
    int arr[3]; k=0;
    for(int i=0; i<3; i++)
    {
        scanf("%d",&arr[i]);
        pos[k]=arr[i]; k++;
    }
    int c,q,command;
    scanf("%d %d",&c,&q);
    for(int i=0; i<c; i++)
    {
        scanf("%d",&command);
        drone(arr,command);
    }
    for(int i=0; i<q; i++)
    {
        int qry; int j;
        scanf("%d",&qry);
        for(j=3*qry; j<3*qry+2; j++)
        {
            printf("%d ",pos[j]);
        }
        printf("%d",pos[j]);
        printf("\n");
    }
    return 0;
}

