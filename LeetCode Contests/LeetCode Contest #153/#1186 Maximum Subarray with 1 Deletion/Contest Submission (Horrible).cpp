class Solution
{
public:
    int maximumSum(vector<int>& arr);
};

int Solution :: maximumSum(vector<int>& a)
{
    int n = a.size();
    vector<int> maxStarting(n), maxEnding(n);
    
    if(n == 1)
        return a.front();
    
    maxStarting[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--)
        maxStarting[i] = max(a[i], a[i] + maxStarting[i+1]);
    
    maxEnding[0] = a[0];
    for(int i = 1; i < n ; i++)
        maxEnding[i] = max(a[i], a[i] + maxEnding[i-1]);
    
    
    // Now try deleting every element
    vector<int> dp(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            dp[i] = maxStarting[i+1];
        }
        else if(i == n-1)
        {
            dp[i] = maxEnding[n-2];
        }
        else
        {
            int x = maxEnding[i-1];
            int y = maxStarting[i+1];
            int z = x+y;
            
            int big;
            
            if(x>y)
                big = x;
            else
                big = y;
            
            if(big > z)
                dp[i] = big;
            else
                dp[i] = z;
        }
        
    }
    //return 0;
    int res_1 = *max_element(dp.begin(), dp.end());
    int res_2 = *max_element(maxStarting.begin(), maxStarting.end());
    
    return max(res_1, res_2);
}
