#include <iostream>
using namespace std;

/* Idea---- Before going to any level, make sure that all nextRight of that level is set */
/* Maintain this invariant and then solve recursively */

struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; 

/* Iterative Approach */

/* Returns the firstNodeJustBelow root */
Node* firstNodeJustBelow(Node* root)
{
    // If root is not present, return nullptr
    if(!root) return root;
    
    // Keep Moving right till you find the answer
    while(root)
    {
        // If the left child is present, it is the answer
        if(root->left) return root->left;
    
        // Else if the right child is present, it is the answer
        else if(root->right) return root->right;
    
        // If none of them are present, move to the right of root and then go down
        else root = root->nextRight;
    }
}

/* Populates the next Pointers */
void connect(Node *root)
{
    // If no root, nothing to Populate
    if(!root) return;
   
    // Populate the root's left child, if it exists
    if(root->left)
    {
        // If the right child exist, connect it
        if(root->right) (root->left)->nextRight = root->right;
        
        // If the right child does not exist, move right and go down to the first element
        else (root->left)->nextRight = firstNodeJustBelow(root->nextRight);
    }
    
    // Now Populate the right the child, if it exist
    if(root->right)
    {
        // Just move to the right and then go dwon on the first element
        (root->right)->nextRight = firstNodeJustBelow(root->nextRight);
    }
    
    /* Now, recursively connect the left and the right subtree */
    connect(root->left);
    connect(root->right);
}

int main() {
	cout<<"GfG!";
	return 0;
}
