class Solution
{
    int sum=0;
public:
    int sumRootToLeaf(TreeNode* root, int oldNumber);
};

/* Returns the sum of all paths from root to leaf */
int Solution :: sumRootToLeaf(TreeNode* root, int oldNumber=0)
{
    // If the tree doesn't exist, the number formed is 0
    if(!root) return 0;
    
    int newNumber = oldNumber*2 + root->val;
    
    // If it is a leaf node, we have enumerated a path
    if(!root->left and !root->right)
    {
        sum += newNumber;
        return sum;
    }
    
    // If it is not a leaf node, enumerate paths in both directions
    sumRootToLeaf(root->left, newNumber);
    sumRootToLeaf(root->right, newNumber);
    
    // Return the sum of all numbers in both the halfs
    return sum;
}
