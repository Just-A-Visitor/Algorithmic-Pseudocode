class Solution
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder);
};

/* Constructs the binary search tree whose preorder is given */
TreeNode* Solution :: bstFromPreorder(vector<int>& preorder)
{
    // Base case ---- The tree must exist
    if(preorder.size()==0) return nullptr;
    
    // Create the stack to hold nodes, not values
    stack<TreeNode*> myStack;
    TreeNode* root = new TreeNode(preorder.front());
    
    /* An amazing trick to handle empty cases. The Marker technique */
    /* The stack can never be empty now */
    myStack.push(new TreeNode(INT_MAX));
    myStack.push(root);
    
    // Traverse each element of the array and add it to the correct place
    for(auto ele : preorder)
    {
        // Skip the first element, i.e, root, as it has been pushed
        if(ele == preorder.front()) continue;
        
        // Create the new node to be attached
        TreeNode* current = new TreeNode(ele);
        
        // Pointer to record the last element popped
        TreeNode* lastPopped = nullptr;
            
        // As long as the current value is greater, keep popping
        while(ele > myStack.top()->val)
            lastPopped = myStack.top(), myStack.pop();
            
        // If nothing was popped, it means it was smaller, hence left child
        if(!lastPopped)
            myStack.top()->left = current;
        else 
            lastPopped->right = current;
        
        // Remember to push the new node . This is necessary to keep going
        myStack.push(current);
    }
    
    return root;
}

/* An important point to note is that we are modifying the value without popping. How? */
/* This is possible because of pointers. Making a copy can still modify elements. */
/* The technique is called monotonic stack */


