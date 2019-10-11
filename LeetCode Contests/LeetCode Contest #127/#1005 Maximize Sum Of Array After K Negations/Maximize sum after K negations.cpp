class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& a, int k);
};

/* Returns the maximum sum possible after k negations */
int Solution :: largestSumAfterKNegations(vector<int>& a, int k)
{
    // Calculate the initial sum of the array
    int sum = accumulate(a.begin(), a.end(), 0);
    
    // Create a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Push all the elements onto the min heap
    for(auto element : a)
        minHeap.push(element);
    
    // Repeat the operation k times
    for(int i=0; i<k; i++)
    {
        // Extract the minimum element
        int minElement = minHeap.top();
        minHeap.pop();
        
        // Remove the initial contribution and add the negated contribution
        sum = sum - minElement + (-minElement);
        
        // Push the negated element back
        minHeap.push(-minElement);
    }
    
    return sum;
}
