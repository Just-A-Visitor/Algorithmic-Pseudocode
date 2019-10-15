/* Terminology ------------
 * 1) originalHead represents the head of the original_head. It is never modified.
 * 2) clonedHead represents the head of the cloned linked list. It is never altered once set.
 * 3) oldHead represents a reference to the the head of the original linked list.
 *    It is used for traversing the original list (and hence mutable).
 * 4) newHead represents a reference to the head of the cloned linked list.
 *    It is used for traversing the cloned linked list (and hence mutable).
 */

/* Deep copies the linked list (along with random pointers) */
var copyRandomList = function(originalHead)
{
    // Handle the corner case
    if(!originalHead) return originalHead;
    
    // Create the head of the cloned linked list and store its reference permanently
    var clonedHead = new Node(originalHead.val, null, null);
    
    // Create iterators for both the linked lists
    var newHead = clonedHead;
    var oldHead = originalHead;
    
    // Create a map which facilitates going vertically down from the original to cloned node
    var nodeJustBelow = new Map();
    
    /* Node to Node mapping is compulsory to deal with duplicates in the linked list */
    
    // Link the nodes vertically
    nodeJustBelow.set(oldHead,newHead);
    
    // Check whether the next node exists or not
    while(oldHead.next)
    {
        // First, create the next node in the cloned list.
        newHead.next = new Node(oldHead.next.val, null, null);
        
        // After the node has been created, step on it by the new thread
        newHead = newHead.next;
        oldHead = oldHead.next;
        
        // After you've moved to the newly created node, connect it vertically
        nodeJustBelow.set(oldHead,newHead);
    }
    
    /* The linked list has been cloned correctly (except the random pointers) */

    // Traverse both the lists together and fill the random pointers
    oldHead = originalHead;
    newHead = clonedHead;
    
    // As long as both the lists exist, correct the random pointers
    while(oldHead && newHead)
    {
        // Traverse the random pointer of the original list and go down vertically and connect it
        newHead.random = oldHead.random? nodeJustBelow.get(oldHead.random) : null;
        
        // Move forward in both the lists
        oldHead = oldHead.next;
        newHead = newHead.next;
    }
    
    // Return the stored reference of the cloned list
    return clonedHead;
}
