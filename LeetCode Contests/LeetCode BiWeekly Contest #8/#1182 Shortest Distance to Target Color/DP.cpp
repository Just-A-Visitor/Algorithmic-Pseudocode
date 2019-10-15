class Solution
{
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries);
};

vector<int> Solution :: shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
{
    int n = colors.size();
    
    vector<vector<int>> left (4, vector<int>(n,-1));
    vector<vector<int>> right(4, vector<int>(n,-1));
    
    for(int shade = 1; shade <= 3; shade++)
    {
        if(colors[0] == shade)
            left[shade][0] = 0;
        for(int i = 1; i < n; i++)
        {
            if(left[shade][i-1] != -1)
                left[shade][i] = left[shade][i-1] + 1;
            
            if(colors[i] == shade)
                left[shade][i] = 0;
        }
    }
    
    for(int shade = 1; shade <= 3; shade++)
    {
        if(colors[n-1] == shade)
            right[shade][n-1] = 0;
        
        for(int i = n-2; i >= 0; i--)
        {
           if(right[shade][i+1] != -1)
                right[shade][i] = right[shade][i+1] + 1;
            
            if(colors[i] == shade)
                right[shade][i] = 0;
        }
    }
    
    
    vector<int> result;
    
    for(auto query : queries)
    {
        int index = query[0];
        int req_color = query[1];
        
        int x = left[req_color][index];
        int y = right[req_color][index];
        
        int ans;
        if(x==-1 or y == -1)
            ans = max(x,y);
        else
            ans = min(x,y);
        
        result.push_back(ans);
    }
    
    
    return result;
}
