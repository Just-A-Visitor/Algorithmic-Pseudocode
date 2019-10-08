/* Driver function for modified inorder tree conversion */
void convert(Node* root, Node **prev_ref)
{
    // Empty tree, Nothing to convert
    if(!root) return;

    // Recursively flatten the left subtree
    // Record the inorder predeccessor of root
    convert(root->left, prev_ref);

    // Connect the last seen node to root
    if((*prev_ref)) 
    {
        (*prev_ref)->right = root;
        root->left = (*prev_ref);
    }

    /* The if condition is for checking that the head of the list is set */

    // Update the last seen node
    *prev_ref = root;

    // Recursively flatten the right subtree
    convert(root->right, prev_ref);
}



/* Converts the binary tree to doubly linked list inplace*/
void BToDLL(Node *root, Node **head_ref)
{
    // Previous records the last visited node
    Node* previous = nullptr;

    // Pass the address of previous to reflect changes
    convert(root, &previous);

    /* Previous points to the tail. Obtain the head */
    while(previous && previous->left)
        previous = previous->left;

    // Update the head of the list
    (*head_ref) = previous;
}

