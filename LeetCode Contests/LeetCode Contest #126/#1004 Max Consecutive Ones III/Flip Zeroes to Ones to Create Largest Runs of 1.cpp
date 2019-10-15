#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int>& a, int k);
};

/* Returns the largest sum possible by flipping zeroes */
int Solution :: longestOnes(vector<int>& a, int k)
{
    // Dequeue to hold the array elements 
    deque<int> dq;
    int countOfOnes=0, windowSize=0, maxLength=0;
    
    /* windowSize is the number of zeroes in the deque */
    
    // Traverse the array and insert each element in the dequeue
    for(int i=0; i<a.size(); i++)
    {
        // If the element is one, insert it and increase the count of ones
        // If the element is zero, insert it and increase windowSize (by Definition)
        if(a[i]==1) dq.push_back(a[i]), countOfOnes++;
        else        dq.push_back(a[i]), windowSize++;
        
        // If windowSize exceeds the maximum permissible, contract the window from the left
        if(windowSize > k)
        {   
            // Keep contracting till you get zero, as 1 has no contribution to size
            while(dq.front()==1)
                dq.pop_front(), countOfOnes--;
            
            // Now you have reached a zero, pop it to actually reduce the windowSize
            dq.pop_front();
            windowSize --;
        }
        
        // All elements in the deque can be converted to ones, since windwoSize<=k */
        maxLength = max(maxLength, (int)dq.size());
    }
    
    // Return the maximum sum possible after flipping
    return maxLength;
}

int main() 
{
	return 0;
}
