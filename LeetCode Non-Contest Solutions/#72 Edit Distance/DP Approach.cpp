class Solution
{
public:
    int minDistance(string word1, string word2);
};

/* Returns the minimum edit distance between the 2 strings */
int Solution :: minDistance(string str_1, string str_2)
{
    // Store the length of the two strings
    int lenFirst = str_1.length();
    int lenSecond = str_2.length();
    
    // Make a 2d vector of (len_first+1)*(len_second+1), since we are going to access the [len_first][len_second] element
    vector<vector<int>> dp;
    
    // Resize the vector to appropriate dimensions and initialise it with zero
    dp.resize(lenFirst+1);
    for(auto &row_vec : dp)
        row_vec.resize(lenSecond+1);
    
    /* DP definitions */
    /* dp[i][j] returns the edit distance of the first i elements of str_1 and first j elements of str_2 */
    
    
    /* dp[0][0] = 0
     * dp[0][j] = j First string is empty,  only insertions can happen
     * dp[i][0] = i Second string is empty, only deletions can happen
     * Compactly, dp[i][j] = max(i,j) if one of them is zero
     */
    
    // Fill the rest of the matrix 
    for(int i=0; i<=(lenFirst); i++)
    {
        for(int j=0; j<=(lenSecond); j++)
        {
            // Base case, as discussed above
            if(i==0 || j==0)
                dp[i][j] = max(i,j);
                
            // If the last characters match, just remove them and calclulate for the left half
            else if(str_1[i-1] == str_2[j-1]) dp[i][j] = dp[i-1][j-1];
            
            // Else, the last character doesn't match
            else
            {
                // Insert a new matching character at the end of first string. The last character matches now. 
                int insert = 1 + dp[i][j-1];
                
                // Delete the last character of the first string
                int _delete = 1 + dp[i-1][j];
                
                // Replace the last character of the first string. Now, the last character matches. 
                int replace = 1 + dp[i-1][j-1];
                
                // Take the best possible of all outcomes
                dp[i][j] = min({insert, _delete, replace});
            }
        }
    }
    
    // Return the edit distance of str_1 and str_2
    return dp[lenFirst][lenSecond];
    
}
