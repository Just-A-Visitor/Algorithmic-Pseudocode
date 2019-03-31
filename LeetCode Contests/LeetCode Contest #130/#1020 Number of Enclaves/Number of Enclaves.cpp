class Solution
{
    int ROW, COL;
public:
    int numEnclaves(vector<vector<int>>& a);
    void dfs(vector<vector<int>>& a, int i, int j);
};

void Solution :: dfs(vector<vector<int>>& a, int i, int j)
{
    if(i<0 || i>=ROW || j<0 || j>=COL) return;
    if(a[i][j]==0 || a[i][j]==-1) return;
	
    a[i][j] = -1;
    
    dfs(a,i-1,j); dfs(a,i+1,j);
    dfs(a,i,j-1); dfs(a,i,j+1);
}

int Solution :: numEnclaves(vector<vector<int>>& a)
{
    ROW = a.size();
    COL = a[0].size();
    
    vector<int> rowBorders = {0,ROW-1};
    vector<int> colBorders = {0,COL-1};
    
    for(int i : rowBorders)
        for(int j=0; j<COL; j++)
            dfs(a,i,j);
    
    for(int j : colBorders)
        for(int i=0; i<ROW; i++)
            dfs(a,i,j);
    
    int count=0;
    for(auto &row_vec:a)
        for(auto &ele : row_vec)
            if(ele==1) count++;
    
    return count;
    
}
