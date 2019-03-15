# include<stdio.h>
int n; char ans[50];
void par(int i, int j, int x)
{
    if(i>j)
    {
        if(i<n)
        {
            ans[x]='}';
            par(i,j+1,x+1);
            ans[x]='{';
            par(i+1,j,x+1);
           
        }
        else
        {
            ans[x]='}'; par(i,j+1,x+1);
        }
    }
    if(i==j)
    {
        if(i+j==2*n)
        {
            printf("%s \n",ans); return;
        }
        else
        {
            ans[x]='{'; par(i+1,j,x+1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    ans[0]='{';
    par(1,0,1);
    return 0;
}

