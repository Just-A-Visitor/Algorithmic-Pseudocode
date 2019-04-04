class Solution 
{
public:
    int rob(vector<int>& a);
};

int Solution :: rob(vector<int>& a)
{
    int n = a.size();
    
    if(n==0) return 0;
    
    int dp[n];
    
    /* dp[i] represents the maximum value stolen after the thief has reached the ith house*/
    /* Note that it does not mean that he has to rob this house compulsorily */
    /* He has the option of robbing it or leaving it, depending upon his choices */
    
    memset(dp,0,sizeof(dp));
    
    int takeIt = 0;
    int leaveIt = 0;
    
    /* The thief comes to the first house */
    takeIt = a[0];
    leaveIt = 0;
    dp[0] = max(takeIt,leaveIt);
    
    // If there is only one house to rob, the you're done */
    // Tricky corner case
    if(n==1) return dp[0];
    
    /* So now assume that the second house exists*/
    
    /* The thief goes to the 2nd house */
    // If he takes it, he has to give back the contents of house 1, if stolen */
    takeIt = a[1]; 
    // If he leaves it, he'll be just where he started off 
    leaveIt = dp[0];
    dp[1] = max(takeIt,leaveIt);
    
    /* Now, apply the definition */
    for(int i=2; i<n; i++)
    {
        // If you take this, you are not eligible for the left house
        // Note that the i-2th house  need not be robbed compulsorily as per dp definition
        takeIt = a[i] + dp[i-2];
        
        // If you leave it, you'll only get the benefits earned till  the last house
        leaveIt = dp[i-1];
        
        // Take the best of the two outcomes
        dp[i] = max(takeIt, leaveIt);
    }
    
    return dp[n-1];
}
