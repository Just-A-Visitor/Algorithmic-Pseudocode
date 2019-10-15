#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& a);
};

/* Computes the largest rectangle under the skyline */
int Solution :: largestRectangleArea(vector<int>& a)
{
    // Extract the size and create the dp matrix
    int n = a.size();
    vector<int> dp(n);
    
    if(n==0) return 0;
        
    /* dp[i] represents the maximum area obtained when we necessarily include the i-th bar (entirely) 
     * Keep going left and right untill you fall off
     * We already know the height, the width would be the number of rectangles encountered
     * Compute the area as height*width
     */
    
    for(int i=0; i<n; i++)
    {
        // Intitial width is 1 (The bar itself)
        int height = a[i];
        int width = 1;
        
        // Search for bars on the left
        int left = i-1;
        while(left>=0 and a[left]>=height)
            left--, width++;
        
        // Search for bars on the right
        int right = i+1;
        while(right<n and a[right]>=height)
            right++, width++;
        
        // Populate the dp Matrix
        dp[i] = height*width;
    }
    
    // In the optimal solution, atleast one rectangle would be fully covered
    return *max_element(dp.begin(), dp.end());
}
int main()
{
	return 0;
}
