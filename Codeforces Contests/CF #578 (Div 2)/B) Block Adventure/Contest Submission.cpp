#include <bits/stdc++.h>
using namespace std;
 
/* Scans the contents of a vector of any data type*/
/* Assumes that the vector has been resized */
template <typename universal_type>
void scanVector(vector<universal_type> &myVector)
{
    for(auto &ele : myVector)
        cin >> ele;
}
 
bool solve(vector<int> &height, int blocksLeft, int k)
{
    int n = height.size();
    int i = 0;
    
    while(i<n-1)
    {
        // Collect boxes
        if(height[i] >= height[i+1])
        {
            // Come to the same height and then go down a bit more
            blocksLeft += height[i] - height[i+1];
            
            int equalHeight = height[i+1];
            
            int newHeight = equalHeight - k;
            
            if(newHeight <=0 )
            {
                blocksLeft += equalHeight;
            }
            else
            {
                blocksLeft += equalHeight - newHeight;
            }
        }
        
        else
        {
            // Get the minimum height to jump to next building
            int minHeightRequired = max(0, height[i+1] - k);
            
            int blocksRequired = minHeightRequired - height[i];
            if(blocksRequired<=0)
            {
                blocksLeft += abs(blocksRequired);
            }
            else
            {
                blocksLeft -= blocksRequired;
                if(blocksLeft < 0)
                    return false;
            }
        }
        i++;
    }
    
    return true;
}
 
signed main()
{
    int t; 
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int n, m, k;
        cin >> n >> m >> k ;
        
        vector<int> height(n);
        scanVector(height);
        
        bool result = solve(height, m, k);
        
        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
	return 0;
}
