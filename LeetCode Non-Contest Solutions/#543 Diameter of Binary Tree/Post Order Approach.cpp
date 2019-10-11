class Solution
{
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root);
    int height(TreeNode* root);
};

/* Returns the height of the tree */
int Solution :: height(TreeNode* root)
{
    // If the tree is empty, diameter is 0
    if(!root) return 0;
    
    // Recursively calculate the height of left and right subtree
    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);

    // Update the longest path
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the tree
    return max(leftHeight,rightHeight) + 1;
}

/* Returns the diameter of the binary tree */
int Solution :: diameterOfBinaryTree(TreeNode* root)
{
    // Calculate the height and update the diameter
    height(root);

    // Return the updated diameter
    return diameter;
}
