class Solution
{
public:
    int largestRectangleArea(vector<int>& a);
};

/* Modified Stock Span */
/* The number of elements to the left with more/equal height than current */
vector<int> stockSpan(vector<int>& a)
{
    int n = a.size();
    vector<int> span(n);
    stack<int> myStack;
    
    for(int i=0; i<n; i++)
    {
        while(!myStack.empty() and a[myStack.top()]>=a[i])
            myStack.pop();
        
        if(myStack.empty())
            span[i] = i+1;
        else
            span[i] = i-myStack.top();
            
        myStack.push(i);
    }
    
    return span;
}

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
    
    vector<int> leftSpan = stockSpan(a);
    
    /* Tricky Part */
    reverse(a.begin(), a.end());
    vector<int> rightSpan = stockSpan(a);
    reverse(a.begin(), a.end());
    
    // We need to reverse the span to get index matching
    reverse(rightSpan.begin(), rightSpan.end());
    
    // Compute the dp matrix
    for(int i=0; i<n; i++)
        dp[i] = a[i]*(leftSpan[i] + rightSpan[i] - 1);
        
        
    // In the optimal solution, atleast one triangle would be fully covered
    return *max_element(dp.begin(), dp.end());
}
