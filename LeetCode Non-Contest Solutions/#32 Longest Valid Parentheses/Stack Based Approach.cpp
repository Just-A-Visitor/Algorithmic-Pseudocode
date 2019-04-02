/* Idea borrowed from https://leetcode.com/problems/longest-valid-parentheses/discuss/14126/My-O(n)-solution-using-a-stack  */



class Solution
{
public:
    int longestValidParentheses(string s);
};

/* Returns the length of teh longest valid parenthesis */
int Solution :: longestValidParentheses(string str)
{
    // Idea ---- Traverse the stack and store the indices which are not matched
    // Get the largest length b/w consecutive indices
    
    // string length
    int n = str.length();
    stack<int> indexStack;
    
    
    // Traverse and remove all the valid indices
    for(int i=0; i<n; i++)
    {
        // if it opening bracket,just push it
        if(str[i]=='(') indexStack.push(i);
        
        // Else it is a closing bracket
        else if(str[i]==')')
        {
             // If Stack is empty, then it is unmatched index
            if(indexStack.empty()) indexStack.push(i);
            
            // Else If stack is not empty, check if it contains the matching bracket on top or not
            else 
            {
                // If the bracket is valid pop it
                if( str[indexStack.top()] == '(') indexStack.pop();
            
                // else We have another invalid parenthesis
                else indexStack.push(i);
            }
        }
    }
    
    // If the stack is empty, the whole string is balanced
    if(indexStack.empty()) return n;
    
    // Assume that the string consisted of one extra character, which is of course mismatched
    int rightIndex = n;
    int leftIndex = 0;
    int maxLength = 0;
    
    
    /* A tricky test case. What if in a long string only the last index is inavlid? */
    /* ()) Stack would become empty in one go, if you do it naively without updating */
    
    // Find the largest gap in between
    while(!indexStack.empty())
    {
        // Store the left index
        int leftIndex = indexStack.top();
        indexStack.pop();
        
        // The number of elements in [l,r] is r-l+1
        // The number of elements strictly b/w l and r is r-l+1-2 = r-l-1
        int midLength = rightIndex - leftIndex - 1;
        
        //update the max length
        maxLength = max(maxLength, midLength);
        
        // update the right index
        rightIndex = leftIndex;
        
        // Check if it was the last element. If it is, it is never coming back to the loop again
        // Set the lower index as -1 (Invalid) and update the max now 
        if(indexStack.empty())
        {
            leftIndex = -1;
            midLength = rightIndex - leftIndex - 1;
            maxLength = max(maxLength, midLength);
        }
    }
    
    
    return maxLength;
}
