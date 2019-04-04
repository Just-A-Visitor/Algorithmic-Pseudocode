class Solution
{
    public:
    unordered_map<int, int> indexMap;
    
    public:
    TreeNode* buildTree(vector<int>& In, vector<int>& Post);
    TreeNode* construct(vector<int>& In, vector<int>& Post, int lowIn, 
                        int highIn, int lowPost, int highPost);
};


/* Returns the tree from the inorder and postorder traversals */
TreeNode* Solution :: buildTree(vector<int>& In, vector<int>& Post)
{
    int n = In.size();

    /* Fill the map with indices for faster searching*/
    for(int i=0; i<n; i++)
        indexMap[In[i]] = i;
    
    return construct(In,Post, 0, n-1, 0, n-1);
}



/* The tricky part is low and high of Inorder and PostOrder would be different as
   root is being removed from middle in one and from the end in another */
TreeNode* Solution :: construct(vector<int>& In, vector<int>& Post, int lowIn, int highIn, 
                                int lowPost, int highPost)
{
    // This means that there is no subtree
    if(lowIn > highIn) return nullptr;
    
    // Create the tree
    // The last element of postOrder is the root
    int rootVal = Post[highPost];
    TreeNode *root = new TreeNode(rootVal);
    
    // Only one element
    if(lowIn == highIn) return root;
 
    /* Let's use unordered_map to find the element's index */
    int index = indexMap[rootVal];
    
    // So, now, in[i] contains the root. This means the left subtree lies in low to i-1, and right
    // subtree lies in i+1 to high
    
    
    // No of elements in [l,r] is r-l+1;
    int length = (index-1) - lowIn + 1;
    
    // Call recursively
    // Remove root from both traversals
    root->left =  construct(In, Post, lowIn, index-1, lowPost, lowPost + length-1);
    root->right = construct(In, Post, index+1, highIn, lowPost+length, highPost-1);
    
    return root;
}
