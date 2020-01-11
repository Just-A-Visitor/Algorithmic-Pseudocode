class Solution
{
public:
	int sumEvenGrandparent(TreeNode* root, bool parentsEven, bool grandParentsEven);
};

int Solution :: sumEvenGrandparent(TreeNode* root, bool parentsEven = false, bool grandParentsEven = false)
{
	if(!root)
		return 0;
	
	int sum = 0;
	if(grandParentsEven)
		sum += root->val;
	
	sum += sumEvenGrandparent(root->left, root->val%2 == 0, parentsEven);
	sum += sumEvenGrandparent(root->right, root->val%2 == 0, parentsEven);
	
	return sum;
}
