class Solution
{
public:
    bool isValidPalindrome(string str, int k);
};

bool Solution :: isValidPalindrome(string str1, int k)
{
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    
    int n = str1.size();
    
    vector<vector<int>> dp(n + 1);
    for(auto &row_vec : dp)
        row_vec.resize(n + 1);
    
    int row = n+1;
    int col = n+1;
    
    for(int i = 0; i < n; i++)
        dp[i][0] = i;
    
    for(int j = 0; j < n; j++)
        dp[0][j] = j;
    
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if((str1[i-1] == str2[j-1]))
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int min_steps = dp[n][n];
    /* Why 2 * k ? */
    return min_steps <= 2*k;
}
