/* Constructs the binary search tree whose preorder is given */
var bstFromPreorder = function(preorder)
{
    // Base case ---- The tree must exist
    if(preorder.length==0) return null;
    
    // Create the stack to hold nodes, not values
    stack = [];
    var root = new TreeNode(preorder[0]);
    
    /* An amazing trick to handle empty cases. The Marker technique */
    /* The stack can never be empty now */
    stack.push(new TreeNode(Math.MAX_SAFE_INTEGER));
    stack.push(root);
    
    // Traverse each element of the array and add it to the correct place
    for(let i=1; i<preorder.length; i++)
    {
        ele = preorder[i];
        
        // Create the new node to be attached
        let current = new TreeNode(ele);
        
        // Pointer to record the last element popped
        let lastPopped = null;
            
        // As long as the current value is greater, keep popping
        while(ele > stack[stack.length-1].val)
            lastPopped = stack.pop();
            
        // If nothing was popped, it means it was smaller, hence left child
        if(!lastPopped)
            stack[stack.length-1].left = current;
        else 
            lastPopped.right = current;
        
        // Remember to push the new node . This is necessary to keep going
        stack.push(current);
    }
    
    return root;
}

/* An important point to note that we are modifying the value without popping. How? */
/* This is possible because of pointers. Making a copy can still modify elements. */
