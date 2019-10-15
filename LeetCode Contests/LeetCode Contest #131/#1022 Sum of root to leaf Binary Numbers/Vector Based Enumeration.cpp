class Solution
{
    vector<int> bits;
public:
    int sumRootToLeaf(TreeNode* root);
};

/* Returns the sum of all paths from root to leaf */
int Solution :: sumRootToLeaf(TreeNode* root)
{
    // If the tree doesn't exist, the number formed is 0
    if(!root) return 0;
    
    // Take this element on our path
    bits.push_back(root->val);
    
    // If it is a leaf node, we have enumerated a path
    if(!root->left and !root->right)
    {
        // We have the binary representation, Convert to decimal
        int sum=0;
        int power_of_2 = 1;
        for(int i=bits.size()-1; i>=0; i--)
        {
            sum += power_of_2*bits[i];
            power_of_2 *= 2;
        }
        
        // Remove the element from the path and back track
        bits.pop_back();
        return sum;
    }
    
    // If it is not a leaf node, enumerate paths in both directions
    int leftAnswer = sumRootToLeaf(root->left);
    int rightAnswer = sumRootToLeaf(root->right);
    
    // Remove this element from the path to backtrack
    bits.pop_back();
    
    // Return the sum of all numbers in both the halfs
    return leftAnswer+rightAnswer;
}
