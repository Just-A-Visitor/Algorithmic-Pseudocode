class Solution
{
public:
    int longestSubsequence(vector<int>& arr, int difference);
};

int Solution :: longestSubsequence(vector<int>& a, int diff)
{
    int n = a.size();
    vector<int> dp(n);
    
    unordered_map<int,int> max_dp_value;
    dp[n-1] = 1;
    max_dp_value[a[n-1]] = 1;
    
    for(int i = n-2; i >= 0; i--)
    {
        int old_value = max_dp_value[a[i]];
        
        int new_value = 1 +  max_dp_value[a[i] + diff];
        
        dp[i] = max(old_value, new_value);
        max_dp_value[a[i]] =  dp[i];
    }
    
    return *max_element(dp.begin(), dp.end());
}

