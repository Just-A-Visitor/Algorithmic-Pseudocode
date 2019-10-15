class Solution
{
public:
    TreeNode* construct(vector<int>& preorder, int low, int high);
    
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        return construct(preorder, 0, preorder.size()-1);
    }
};

/* Constructs the binary search tree whose preorder is a[low,...,high] */
TreeNode* Solution :: construct(vector<int>& preorder, int low, int high)
{
    // If low and high cross, or if they are out of bound, the tree does not exist
    if(low<0 || high<0) return nullptr;
    if(low>high) return nullptr;
    
    // The first element of the traversal is the root
    TreeNode* root = new TreeNode(preorder[low]);
    
    // greaterIndex stores the index of the first element greater than root's val
    int greaterIndex = high+1;
    for(int i=low+1; i<=high; i++)
    {
        if(preorder[i]>root->val)
        {
            greaterIndex=i;
            break;
        }
    }
    
    // Construct the left and right subtree recursively
    root->left  = construct(preorder, low+1, greaterIndex-1);
    root->right = construct(preorder, greaterIndex, high);
    
    // Return the filled tree
    return root;
}
