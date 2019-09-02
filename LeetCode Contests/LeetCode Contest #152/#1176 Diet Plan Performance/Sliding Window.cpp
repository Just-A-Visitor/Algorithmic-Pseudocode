class Solution
{
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper);
};

int Solution :: dietPlanPerformance(vector<int>& a, int k, int lower, int upper)
{
    int n = a.size();
    int res = 0;
    int sum = 0;
    
    for(int i = 0; i < k; i++)
        sum += a[i];
    
    if(sum < lower)
            res--;
    if(sum > upper)
            res++;
    
    for(int i = k; i < n; i++)
    {
        sum -= a[i-k];
        sum += a[i];
        
        if(sum < lower)
            res--;
        if(sum > upper)
            res++;
    }
    
    
    return res;
}
