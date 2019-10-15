/* Converting it into an iterative version is easy.*/
/* Enclose the swapping procedure in a while loop */

/* Swaps the nodes pairwise */
var swapPairs = function(head)
{
    // If less than 2 elements exist, No need to do anything
    if(!head || !(head.next)) return head;
    
    // Swap 2 nodes manually and let recursion do the rest
    var firstNode = head;
    var secondNode = head.next;
    
    // Connect first node to third node
    firstNode.next = secondNode.next;
    
    // Connect second node to the first node
    secondNode.next = firstNode;
    
    // Update head
    head = secondNode;
    
    // Recursively swap the remainging nodes. 
    // There are atleast 2 nodes, hence no null pointer exception happen
    head.next.next = swapPairs(head.next.next);
    
    // Return the updated head to be overwritten
    return head;
}
