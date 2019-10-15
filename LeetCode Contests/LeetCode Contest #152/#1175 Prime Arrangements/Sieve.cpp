class Solution
{
public:
    int numPrimeArrangements(int n);
};

int Solution :: numPrimeArrangements(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(prime[i])
            for(int factor = 2; factor*i <= n; factor++)
                prime[factor*i] = false;
    }
    
    int primeIndices = 0;
    for(int i = 1; i <= n; i++)
        if(prime[i])
            primeIndices++;
    
    int mod = 1e9 + 7, res = 1;
	
    for(int i = 1; i <= primeIndices; i++)
        res = (1LL*res*i) % mod;
    for(int i = 1; i<= (n-primeIndices); i++)
        res = (1LL*res*i) % mod;
    
    return res;
    
}
