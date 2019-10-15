class Solution
{
public:
    int largestRectangleArea(vector<int>& a);
};

/* Computes the largest rectangle under the Skyline */
int Solution :: largestRectangleArea(vector<int>& a)
{
    // Push the sentinel. It ensures that all elements are popped
    a.push_back(0);
    
    // Declare the stack to hold indices
    stack<int> myStack;
    int maxArea = 0;
    
    // Push each element on the stack
    for(int i=0; i<a.size(); i++)
    {
        // Keep removing the buildings which are being blocked
        while(!myStack.empty() and a[i]<=a[myStack.top()])
        {
            // Update the contribution of the leaving building
            int height = a[myStack.top()];
            myStack.pop();
            
            // See the ReadMe for proof
            int width = myStack.empty()? i : i - myStack.top() - 1;
            
            // Update the overall result
            maxArea = max(maxArea, height*width);
        }
        
        // Push this element as invariant will now be maintained
        myStack.push(i);
    }
    
    return maxArea;
}
