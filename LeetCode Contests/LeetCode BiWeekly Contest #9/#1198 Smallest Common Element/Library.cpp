class Solution
{
public:
    int smallestCommonElement(vector<vector<int>>& mat);
};

int Solution :: smallestCommonElement(vector<vector<int>>& mat)
{
    for(auto &v : mat)
        v.erase(unique(v.begin(), v.end()), v.end());
    
    map<int, int> count;
    
    for(auto &row_vec : mat)
        for(auto &ele : row_vec)
            count[ele]++;
    
    int rowCount = mat.size();
    
    for(auto &ele : mat[0])
        if(count[ele] == rowCount)
            return ele;
    
    return -1;
    
}
