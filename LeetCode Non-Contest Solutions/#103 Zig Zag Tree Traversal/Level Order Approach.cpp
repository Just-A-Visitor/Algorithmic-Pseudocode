class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);
};

vector<vector<int>> Solution :: zigzagLevelOrder(TreeNode* root)
{
    stack<struct TreeNode *> currentLevel, nextLevel;
    vector<vector<int>> answer;
    int level = 0;
    
    // If root is not null, push it on the stack
    if(root) currentLevel.push(root);
    
    // The root level associates left to right
    bool leftToRight=true;
    
    //  Loop through each level in the tree
    //  Note:- The loop terminates when there is no node in the level
    while(!currentLevel.empty())
    {
        // Reached a new level. Resize the vector
        ++level;
        answer.resize(level);
        
        // If the level associates left to right, it means that the left child of
        // the first popped will be the last element to be printed in the next level
        // so put it on the auxillary stack first
        // Loop through each node in the level
        while(!currentLevel.empty())
        {
            struct TreeNode *temp = currentLevel.top();
            currentLevel.pop();
            
            // Store the values
            answer[level-1].push_back(temp->val);
            
            // If the level associates from left to right
            if(leftToRight)
            {
                // Push the left child first, then the right child
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }
            
            // Else, the level associates right to left
            else if(!leftToRight)
            {
                // Push the right child first, then the left child
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }
        }
        
        // After you have printed the level, set grounds for the next level,
        // Change associativity and free the nextLevel, i.e, auxillary stack
        leftToRight = !leftToRight;
        
        // Notice the syntax of swap. std::swap is faster than stack.swap
        swap(currentLevel, nextLevel);
    }
    
    return answer;
}
