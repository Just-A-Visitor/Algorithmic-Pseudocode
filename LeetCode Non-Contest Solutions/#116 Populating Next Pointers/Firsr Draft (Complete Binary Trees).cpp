/*Idea borrowed from  */
/* https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37473/My-recursive-solution(Java) */

/* Please note that this solution only works for complete binary trees */

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
    
    /* Correct the next and right pointers of the root of the left subtree and right subtree */
    // This is necessary as we require this to correct the next pointer of the right child of the left subtree
    if(root->left)
        root->left->next = root->right;
    
    /* The left child corrected */
    
    // If the right child exists, move to the right of root. Now, if right neighbour of root exists,
    // Connect the right child of root to the left child of root->next
    if(root->right)
        root->right->next = (root->next) ? (root->next)->left : nullptr;
    
    /* The above part is very tricky and powerful at the same time */
    
    /* Recursively correct both trees */
    connect(root->left);
    connect(root->right);
}

/* Further ideas */
/* We assume that whenever we reach a node, it's next pointer is already set */
/* To maintain this invariant, we need to set the next pointers of left and right child before moving down */
