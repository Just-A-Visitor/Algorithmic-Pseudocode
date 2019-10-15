void populateMap(TreeNode* root, map<int, int> &count)
{
    if(!root)
        return;
    
    count[root->val]++;
    populateMap(root->left, count);
    populateMap(root->right, count);
}

class Solution
{
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target);
};



bool Solution :: twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
{
    map<int, int> count1, count2;
    populateMap(root1, count1);
    populateMap(root2, count2);
    
    for(auto ele : count1)
        if(ele.first == target or count2[target - ele.first] != 0)
            return true;
    
    return false;
    
}
