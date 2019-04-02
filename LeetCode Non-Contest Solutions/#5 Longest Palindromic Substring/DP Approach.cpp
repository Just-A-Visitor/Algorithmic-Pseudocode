class Solution
{
public:
    string longestPalindrome(string str);
};

string Solution :: longestPalindrome(string str)
{
    int n = str.length();
    if(n==0) return "";
    
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    
    /* dp[i][j] is true if str[i,....j] is a palindrome */
    
    // Clearly dp[i,i] is a palindrome (Consisting of 1 element)
    
    // dp[i][j] = dp[i+1][j-1] if str[i]==str[j]
    // For filling, we need the next row but the previous column
    
    /* It suggests that we fill the rows from bottom and columns from left to right */
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i; j<n; j++)
        {
            int length = j-i+1;
            if(i==n-1) dp[i][j] = false;
            else if(j==0) dp[i][j] = false;
            else if(str[i] == str[j] && length<=2) dp[i][j] = true;
            else if(str[i]==str[j] && length>2) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = false;
        }
    }
    
    int start = 0;
    int maxLength = 1;
    
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(dp[i][j] == false) continue;
            int length = j-i+1;
            if(length > maxLength)
                start = i, maxLength = length;
        }
    }
    
    return str.substr(start, maxLength);
}
