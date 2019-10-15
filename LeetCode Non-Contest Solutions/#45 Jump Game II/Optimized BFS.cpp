class Solution
{
public:
    int jump(vector<int>& nums);
};

int Solution :: jump(vector<int>& a)
{
    int n = a.size();
    
    // This also functions as the visited array
    vector<int> level(n,-1);
    
    // Queue contains the indexes
    queue<int> bfs;
    bfs.push(0);
    level[0] = 0;
    int maxReach = 0;
    
    /* maxReach denotes the maximum element reached */
    
    // Perform the bfs
    while(!bfs.empty())
    {
        int ind = bfs.front();
        bfs.pop();
        
        // Check if you can reach the next element
        while(maxReach + 1 < n and maxReach + 1 <= ind + a[ind])
        {
            maxReach++;
            level[maxReach] = level[ind] + 1;
            bfs.push(maxReach);
        }
    }
    
    return level.back();
}
