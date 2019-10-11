class Solution 
{
    public:
    int trap(vector<int>& height);
};

int Solution :: trap(vector<int>& a)
{
    int n = a.size();
    
    if(n==0) return 0;
    
    // Stores the elevation of the highest block to the left (strictly left)
    int leftMax[n];
    
    // Fill the leftMax array 
    leftMax[0] = 0;
    for(int i=1; i<n; i++)
        leftMax[i] = max(leftMax[i-1],a[i-1]);
    
    // Stores the elevation of the highest block to the right (strictly right)
    int rightMax[n];
    
    // Fill the rightMax array from the end
    rightMax[n-1] = 0;
    for(int i=n-2; i>=0; i--)
        rightMax[i] = max(rightMax[i+1],a[i+1]);
    
    // Create the contributions array
    int contribution[n];
    
    // Calculate the contributions
    for(int i=0; i<n; i++)
    {
        // Calculate the min height of the highest blocks on each side
        int height = min(leftMax[i],rightMax[i]);
        
        // If height <= a[i], you cannot store water as it would fall off
        if(height <= a[i]) contribution[i]=0;
        else contribution[i] = height - a[i];
    }
    
    // Calculate the total water collected
    int totalWater = 0;
    for(int i=0; i<n; i++)
        totalWater += contribution[i];
    
    return totalWater;   
}
