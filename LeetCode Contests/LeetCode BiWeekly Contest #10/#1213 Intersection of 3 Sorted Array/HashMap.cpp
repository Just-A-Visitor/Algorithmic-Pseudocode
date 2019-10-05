class Solution
{
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3);
};

vector<int> Solution :: arraysIntersection(vector<int>& a, vector<int>& b, vector<int>& c)
{
    map<int,int> count;
    
    for(auto ele : a)
        count[ele]++;
    
    for(auto ele : b)
        count[ele]++;
    
    for(auto ele : c)
        count[ele]++;
    
    vector<int> result;
    for(auto ele : count)
        if(ele.second == 3)
            result.push_back(ele.first);
    
    return result;
}
