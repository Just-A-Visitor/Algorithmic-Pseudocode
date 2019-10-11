/* Please note that this solution works for all types of trees, whether complete or not*/

/* Idea---- Before going to any level, make sure that all next of that level is set */
/* Maintain this invariant and then solve level by level */

class Solution
{
public:
    TreeLinkNode* firstNodeJustBelow(TreeLinkNode* root);
    void connect(TreeLinkNode *root);
};


/* Returns the firstNodeJustBelow root */
TreeLinkNode* Solution :: firstNodeJustBelow(TreeLinkNode* root)
{
    // If root is not present, return nullptr
    if(!root) return root;
    
    // Keep Moving right till you find the answer
    while(root)
    {
        // If the left child is present, it is the answer
        if(root->left) return root->left;
        
        // Else if the right child is present, it is the answer
        else if(root->right) return root->right;
    
        // If none of them are present, move to the right of root and then go down
        else root = root->next;
    }
    
    return root;
}

/* Populates the next Pointers */
void Solution :: connect(TreeLinkNode *root)
{
    // If no root, nothing to Populate
    if(!root) return;
    
    // Declare it outside to prevent memory wastage. It stores the node whose child is being corrected
    TreeLinkNode* current;
    
    while(root)
    {
        // Store the address of the first node in the level to get down to the first node in the next level
        current = root;
        
        // Correct all the nodes in the next level before getting down
        while(current)
        {
            // If the left child exits, connect it to the right child, if it exists, else connect it further
            if(current->left)
                (current->left)->next = (current->right) ? current->right : firstNodeJustBelow(current->next);
            
            // If the right child exists, connect it to the next node
            if(current->right)
                (current->right)->next = firstNodeJustBelow(current->next);
            
            // Correct the children of the next nodes in this level    
            current = current->next;    
        }
        
        // Move down to the first node in the next level
        root = firstNodeJustBelow(root);
    }
}

