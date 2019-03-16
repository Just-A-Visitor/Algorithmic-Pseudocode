/* Warning ---- Implementation of shift depends on JavaScript implementation. */
/* It might not be O(1) */

/* Returns the largest sum possible by flipping zeroes */
var longestOnes = function(a,k)
{
    // Dequeue to hold the array elements 
    var dq = [];
    var countOfOnes=0, windowSize=0, maxLength=0;
    
    /* windowSize is the number of zeroes in the deque */
    
    // Traverse the array and insert each element in the dequeue
    for(var i=0; i<a.length; i++)
    {
        // If the element is one, insert it and increase the count of ones
        // If the element is zero, insert it and increase windowSize (by Definition)
        if(a[i]==1) dq.push(a[i]), countOfOnes++;
        else        dq.push(a[i]), windowSize++;
        
        // If windowSize exceeds the maximum permissible, contract the window from the left
        if(windowSize > k)
        {   
            // Keep contracting till you get zero, as 1 has no contribution to size
            while(dq[0]==1)
                dq.shift(), countOfOnes--;
            
            // Now you have reached a zero, pop it to actually reduce the windowSize
            dq.shift();
            windowSize --;
        }
        
        // All elements in the deque can be converted to ones, since windwoSize<=k */
        maxLength = Math.max(maxLength, dq.length);
    }
    
    // Return the maximum sum possible after flipping
    return maxLength;
}
