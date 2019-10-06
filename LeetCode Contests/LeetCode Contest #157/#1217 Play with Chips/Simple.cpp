class Solution
{
public:
    int minCostToMoveChips(vector<int>& chips);
};

int Solution :: minCostToMoveChips(vector<int>& chips)
{
    int odd = 0, even = 0;
    for(auto ele : chips)
    {
        if(ele % 2 != 0)
            odd++;
        else
            even++;
    }
    
    return min(odd, even);
}
