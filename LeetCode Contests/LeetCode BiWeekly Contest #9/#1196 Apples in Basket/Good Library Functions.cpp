class Solution
{
public:
    int maxNumberOfApples(vector<int>& arr);
};

int Solution :: maxNumberOfApples(vector<int>& a)
{
    sort(a.begin(), a.end());
    
    for(int i = 1; i < a.size(); i++)
        a[i] += a[i-1];
    
    auto itr = lower_bound(a.begin(), a.end(), 5000);
    return distance(a.begin(), itr);
    
}
