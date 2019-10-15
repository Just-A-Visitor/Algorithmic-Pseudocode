class Solution
{
    set<long> collect;
    int limit;
public:
    void BuildTree(long root);
    vector<int> countSteppingNumbers(int low, int high);
};

void Solution :: BuildTree(long root)
{
    if(root > limit)
        return;
    collect.insert(root);
    
    int lastVal = root%10;
    
    if(lastVal != 9)
        BuildTree(root*10 + (lastVal + 1));
    
    if(lastVal != 0)
        BuildTree(root*10 + (lastVal - 1));
}

vector<int> Solution :: countSteppingNumbers(int low, int high)
{
    limit = high;
    for(int i = 0; i <= 9; i++) 
        BuildTree(i);
    
    vector<int> result;
    for(auto ele : collect)
        if(low <= ele and ele <= high)
            result.push_back(ele);
    
    return result;
}
