#include<stdio.h>
int flag[100][100],n;//flag= global array to check if position is blocked or not (1 for blocked, 0 for unblocked)
void verify(int x,int y)
{
    for(int i=0; i<n; i++)
    {
        flag[i][y]=1; flag[x][i]=1;//fix the rows and cols..
    }
    for(int z=1; (x+z<n && y+z<n); z++)
    {
        flag[x+z][y+z]=1;//fix the main diag. lower part
    }
    for(int z=1; (x-z>=0 && y-z>=0); z++)
    {
        flag[x-z][y-z]=1;//fix the main diag.. upper part..
    }
    for(int z=1; (x-z>=0 && y+z<n); z++)
    {
        flag[x-z][y+z]=1;//fix the other diag. upper part
    }
    for(int z=1; (x+z<n && y-z>=0); z++)
    {
        flag[x+z][y-z]=1;//fix the other diag. lower part
    }
}
int main(){
    int k,x,y,i;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            flag[i][j]=0;//since, initially, all are unblocked.
        }
    }
    for(i=0; i<k; i++)
    {
        scanf("%d %d",&x,&y);
        if(flag[x][y]==1)//check if placed on blocked or not.
        {
            printf("INVALID"); i=20; break;
        }
        verify(x,y);//block further
    }
    if(i!=20)
    {
       printf("VALID");
    }
    return 0;
}


