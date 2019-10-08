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
    
    int nextIndex;
    
    // Perform the bfs
    while(!bfs.empty())
    {
        int currentIndex = bfs.front();
        bfs.pop();
        
        // Notice the equality
        for(int steps = 1; steps <= a[currentIndex]; steps++)
        {
            // Go Left
            nextIndex = currentIndex + steps;
            if(nextIndex < n and level[nextIndex] == -1)
            {
                bfs.push(nextIndex);
                level[nextIndex] = level[currentIndex] + 1;
            }
            
            // Go Right
            nextIndex = currentIndex - steps;
            if(nextIndex >= 0 and level[nextIndex] == -1)
            {
                bfs.push(nextIndex);
                level[nextIndex] = level[currentIndex] + 1;
            }
        }
    }
    
    return level.back();
}
