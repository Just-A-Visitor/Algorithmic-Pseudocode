class Solution
{
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target);
};


bool binary_search(TreeNode* root, int key)
{
    if(!root)
        return false;
   
    if(root->val == key)
        return true;
    
    if(root->val > key)
        return binary_search(root->left, key);
    else
        return binary_search(root->right, key);
}


bool Solution :: twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
{
    if(!root1 || !root2)
        return false;
    
    if(root1->val == target)
        return true;
    
    // Check if this is the answer
    if(binary_search(root2, target - root1->val))
        return true;
    
    // Check in the left subtree
    if(twoSumBSTs(root1->left, root2, target))
        return true;
    
    // Check in the right subtree
    if(twoSumBSTs(root1->right, root2, target))
        return true;
    
    return false;
}
