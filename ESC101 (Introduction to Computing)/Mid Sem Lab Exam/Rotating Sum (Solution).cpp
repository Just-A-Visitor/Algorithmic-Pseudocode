#include<stdio.h>
int main()
{
    int l,n,k;
    scanf("%d %d %d",&l,&n,&k);
    int old[1000]; int j=0, r=0, t=0;
    int ch=getchar();
    while((ch=='\n' || ch==' ') || (ch=='\0'|| ch=='\t'))
    {
        ch=getchar();
    }
    while((ch!='\n' && ch!=' ') && (ch!='\0' && ch!=EOF))
    {
        old[t]=ch-'0'; t++;
        ch=getchar();
    }
for(int g=0; g<n; g++)
{
    int new[1000], result[1000];
    for(int i=0; i<l; i++)
    {
        int z=i+k;
        if(z>=l)
        {
            z=z%l;
        }
        new[i]=old[z];
    }
        
    for(int i=0; i<l; i++)
    {
        int s=new[l-i-1]+old[l-i-1]+r;
        if(s>9)
        {
            result[j]=s%10; j++;
            r=s/10;
            if(i==l-1)
            {
                result[j]=r; j++;
            }
        }
        else
        {
            result[j]=s; j++; r=0;
        }
    }
    l=j; j=0; r=0; int x=0;
    for(int i=0; i<l; i++)
    {
        old[i]=result[l-i-1];
    }
    
}
for(int i=0; i<l; i++)
{
   printf("%d",old[i]);
}
    return 0;
}
