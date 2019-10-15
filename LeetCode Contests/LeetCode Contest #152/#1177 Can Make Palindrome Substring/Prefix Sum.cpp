class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries);
};

vector<bool> Solution :: canMakePaliQueries(string str, vector<vector<int>>& queries)
{
    int n = str.length();
    vector<vector<int>> dp(26, vector<int>(n,0));
    
    /* dp[i][j] represents the count of the i-th character in the string str[0...i] */
    
    for(int i = 0; i < 26; i++)
    {
        char currentChar = i + 'a';
        for(int j = 0; j < n; j++)
        {
            if(j == 0)
                dp[i][j] = (str[j] == currentChar);
            else
                dp[i][j] = dp[i][j-1] + (str[j] == currentChar);
        }
    }
    
    vector<bool> ans;
    for(auto query : queries)
    {
        int left =  query[0];
        int right = query[1];
        int k = query[2];
        
        int unMatchedCount = 0;
        for(int i = 0; i < 26; i++)
        {
            int occurrence = dp[i][right] - dp[i][left] + (str[left] == (i + 'a'));
            
            if(occurrence & 1)
                unMatchedCount++;
        }
        
        int requiredConversions = unMatchedCount / 2;
        ans.push_back(requiredConversions <= k);
    }
    
    return ans;
}
