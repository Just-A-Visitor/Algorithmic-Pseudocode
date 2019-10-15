class Solution
{
public:
    int maxProduct(vector<int>& a);
};

int Solution ::  maxProduct(vector<int>& a)
{
    int n = a.size();
    
    int max_ending_here = a[0];
    int min_ending_here = a[0];
    int max_so_far = a[0];
    
    for(int i=1; i<n; i++)
    {
        if(a[i]<0)
            swap(max_ending_here, min_ending_here);
        
        max_ending_here = max(max_ending_here*a[i], a[i]);
        min_ending_here = min(min_ending_here*a[i], a[i]);
        
        max_so_far = max(max_so_far, max_ending_here);
    }
        
    return max_so_far;
}
