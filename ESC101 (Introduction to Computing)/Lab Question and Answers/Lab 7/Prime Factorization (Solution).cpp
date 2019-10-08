#include<stdio.h>
#include<math.h>

void primeFactors(int n)
{
    int k=n;
    int sum=0, sin=0, sun=0;// n : The input number
    while(k%2==0)//Checking the conditions
    {
        k=k/2;
        sum=sum+1;
    }
    if(sum>0)
    {
        printf("2\n");
    }
    for(int j=3; j<=sqrt(n); j++)
    {
        while(k%j==0)
        {
            k=k/j;
            sin=sin+1;
        }
            if(sin>0)
            {
                printf("%d\n",j);
            }
            sin=0;//Initialising again
    }
    for(int z=2; z<k; z++)
    {
        if(k%z!=0)
        {
            sun=sun+1;
        }
    }
    if(sun==k-2)
    {
        printf("%d",k);
    }
    // Since the return type of this function is void, the function should itself compute the prime factors and print them
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    primeFactors(n);
    return 0;
}
