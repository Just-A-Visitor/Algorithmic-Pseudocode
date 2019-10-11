/* Idea borrowed fom */
/* https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/ */

/* Please note that this solution works for all types of trees, whether complete or not*/

class Solution
{
public:
    void connect(TreeLinkNode *root);
};

/* Connects the nodes at the same level */
void Solution :: connect(TreeLinkNode* root)
{
    // If root is empty, nothing to connect
    if(!root) return;
    
    // Create the queue and the marker
    queue<TreeLinkNode*> myQueue;
    TreeLinkNode* marker = nullptr;
    
    // Push the root and the marker to indicate the finishing of one level
    myQueue.push(root);
    myQueue.push(marker);
    
    // Perform level order traversal
    while(!myQueue.empty())
    {
        auto current = myQueue.front();
        myQueue.pop();
        
        // If current is not null, it means that its next nighbour to the right is in front of the queue
        if(current)
        {
            // Note that myQueue.front() can be nullptr, but the queue cannot be empty
            current -> next = myQueue.front();
            
            // Push the left and the righ tchild to actually do the level oerder traversal
            if(current->left)  myQueue.push(current->left);
            if(current->right) myQueue.push(current->right);
        }
        
        // If you have reached the marker
        else if(!current)
        {
            // Check if the traversal is finished or not to avoid infinite loop
            if(!myQueue.empty()) myQueue.push(marker);
            
            // Push maker after the current set of elements to indicate finishing of a level
        }
    }
}
