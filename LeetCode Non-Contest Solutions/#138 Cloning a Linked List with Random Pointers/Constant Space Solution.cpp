class Solution
{
public:
    Node* copyRandomList(Node* originalHead);
};

/* Returns a deep copy of the list using constant space */
Node* Solution :: copyRandomList(Node* originalHead)
{
    // Handle the base case
    if(!originalHead) return originalHead;
    
    // The iterator for the list and the backup.
    Node* weavedHead;
    Node* backup;
    weavedHead = originalHead;
    
    /* Never declare variables inside for loop if you need O(1) space solution */
    
    /* Interleave the nodes (Make copies to the right) */
    
    // Create the copies and put them to the right
    while(weavedHead)
    {
        // Make a backup of the next (original) node
        backup = weavedHead->next;
        
        // Attach a copy. The next field of the new node is the original right node
        weavedHead->next = new Node(weavedHead->val, backup, nullptr);
        
        // Move to the original right node.(Don't create copies of copies)
        weavedHead = backup;
    }
    
    // Store a permanent reference to the cloned head
    Node* clonedHead = originalHead->next;
    
    // Iterator for the list
    weavedHead = originalHead;
    
    // Start filling the random pointers
    while(weavedHead)
    {
        /* We are standing at a node from the original list
         * The next node is its clone. 
         * Get the random pointer of the original list and traverse there.
         * The corresponding counterpart of the random node would be to its right
         * Fill the random pointers of the cloned part (right) using this
         */
        (weavedHead->next)->random = weavedHead->random ? (weavedHead->random)->next : nullptr;
        
        /* Make sure to go 2 steps to the right.
         * We always stand at the original node and correct the clone node
         * It is guaranteed that weavedHead->next is not null. How? Check the first assumption
         */
        weavedHead = weavedHead->next->next;
    }
    
    // Remove the interlacing and correct the original list
    weavedHead = originalHead;
    while(weavedHead)
    {
        // We can stand on both types of nodes. Get a backup of the next element
        backup = weavedHead->next;
        
        // The correct neighbour is shifted to the right by 1 place
        weavedHead->next = weavedHead->next ? weavedHead->next->next : nullptr;
        
        // Remember to go one step at a time to correct both the lists
        weavedHead = backup;
    }
    
    // Return the stored permananent reference
    return clonedHead;
}
