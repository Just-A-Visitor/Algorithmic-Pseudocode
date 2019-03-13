class Solution
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder);
};

/* Constructs the binary search tree whose preorder is preorder[] */
TreeNode* Solution :: bstFromPreorder(vector<int>& preorder)
{
    // Base case ---- The tree must exist
    if(preorder.size()==0) return nullptr;
    
    // Create the stack to hold nodes, not values
    stack<TreeNode*> myStack;
    TreeNode* root;
    
    // Traverse each element of the array and add it to the correct place
    for(auto ele : preorder)
    {
        // Create the new node to be attached
        TreeNode* current = new TreeNode(ele);
        
        // If the stack is empty, it means it is the root
        if(myStack.empty()) root = current;
        else
        {
            // See the top node (as stack is not empty)
            auto topNode = myStack.top();
            
            // If the current value is less than the top, it means it is left child
            if(ele < topNode->val) 
            {
                topNode->left = current;
            }
            
            // Else it is the right child of the parent 
            else
            {
                TreeNode* lastPopped;
                
                /* Search the parent
                 * Remember to check for empty stack. This caused a lot of error
                 * Remember to keep track of the last popped element
                 * The last popped element will be the parent
                 */
                while(!myStack.empty() && ele > (myStack.top())->val )
                {
                    lastPopped = myStack.top();
                    myStack.pop();
                }
                
                // Make it the right child of the parent
                lastPopped->right = current;
            }
        }
        
        // Remember to push the new node back. This is necessary
        myStack.push(current);
    }
    return root;

}
