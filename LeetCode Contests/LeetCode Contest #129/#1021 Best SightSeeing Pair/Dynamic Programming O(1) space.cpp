class Solution
{
public:
    int maxScoreSightseeingPair(vector<int>& a);
};

int Solution :: maxScoreSightseeingPair(vector<int>& a)
{
    int n = a.size();
    int maxOverallGain = INT_MIN;
    int maxEndRight = a[n-1] - (n-1);
    for(int i=n-2; i>=0; i--)
    {
        maxEndRight = max(maxEndRight, a[i+1] - (i+1));
        maxOverallGain = max(maxOverallGain, a[i] + i + maxEndRight);
    }
    return maxOverallGain;
    
}
