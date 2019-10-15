/* Idea ---- Store the length of the longest valid parenthesis ending at i for each i */

class Solution
{
public:
    int longestValidParentheses(string str);
};

/* Returns the length of the longest valid parenthesis */
int Solution :: longestValidParentheses(string str)
{
    // Store the length of the string
    int n = str.length();
    
    // Get rid of the corner cases, since we are going to be accessing dp[i-2] a lot
    if(n==1 || n==0) return 0;
    
    /* So now assume that the string contains atleast 2 characters */
    
    /* dp[i] represents the longest valid parenthesis ending at i */
    
    
    // Create the dp  matrix and initialise
    int dp[n];
    memset (dp,0,sizeof(dp));
    
    // Fill the first 2 elements manually
    
    // No valid substring can end at 0, no matter what the character at zero is
    dp[0] = 0;
    
    // Check if the substring at zero is valid or not
    if(str[0]=='(' && str[1]==')') dp[1] = 2;
    else dp[1] = 0;
    
    // Start filling all the other entries
    for(int i=2; i<n; i++)
    {
        // Case 1--- str[i] == '('. No string can end here
        if(str[i] == '(') dp[i]=0;
        
        // Case 2 ---- str[i] == ')'.
        else if(str[i] == ')')
        {
            //We need to look back 
            // Sub Case 1 ---- str[i-1] == '('. Clealry [i-1,i] is valid. Concatenate it.
            // Note that both are accessible according to loop initiation
            if(str[i-1] == '(') dp[i] = 2 + dp[i-2];
            
            // sub Case 2 --- str[i-1] == ')'
            else if(str[i-1] == ')')
            {
                // First check whether the closing is a valid one or not
                if(dp[i-1] == 0) dp[i]=0;
                
                // Else we know that it is valid. Check if it can be extended further
                else
                {
                    // Length of the longest subString ending at i-1.
                    int len = dp[i-1];
                    
                    int endIndex = i-1;
                    int startIndex = endIndex - len + 1;
                    // Since the number of elements in [startIndex, endIndex] = endIndex - startIndex + 1 = len
                    
                    // So, get the index of the element to the left of the start index
                    int startLeft = startIndex - 1;
                    
                    // It might happen the startIndex is 0, hence startLeft is -1. Invalid extra bracket
                    if(startLeft == -1) dp[i] = 0;
                    
                    else
                    {
                        // Just confirm whether everything is all right
                        assert(startLeft >=0);
                        
                        // Invalid nesting
                        if(str[startLeft] == ')') dp[i]=0;
                        
                        // Include the element at the startleft and current element to make it nested
                        else
                        {
                            // First check if startLeftLeft is accesible or not
                            int startLeftLeft = startLeft - 1;
                            
                            // Nest the string and concatenate it
                            if(startLeftLeft >=0)
                                dp[i] = len + 2 + dp[startLeftLeft];
                            else
                                dp[i] = len + 2;
                        }
                    }
                }
            }
        }
    }
    
    
    // Traverse and get the max Length
    int maxLen = INT_MIN;
    for(int i=0; i<n; i++)
        maxLen = max(maxLen, dp[i]);
    
    return maxLen;
    
}
