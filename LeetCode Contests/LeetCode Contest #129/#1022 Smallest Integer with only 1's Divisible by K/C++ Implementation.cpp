class Solution 
{
public:
    int smallestRepunitDivByK(int k);
};

int Solution :: smallestRepunitDivByK(int k)
{
	if(k%2==0 || k%5==0) return -1;
    int prevRem=1, newRem, sum=0;
    int maxLength = 100000;
    for(int power=0; power<maxLength; power++)
    {
        newRem = (prevRem * 10%k)%k;
        sum = (sum + newRem)%k;
        prevRem = newRem;
        if(sum==0) return power+1;
    }
    return -1;
}
