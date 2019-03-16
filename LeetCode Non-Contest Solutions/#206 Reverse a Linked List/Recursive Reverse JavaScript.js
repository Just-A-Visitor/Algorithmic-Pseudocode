/* Reverses the linked list recursively */
var reverseList = function(head)
{
    // If the list is empty or has one element, nothing to reverse
    if(!head || !(head.next)) return head;
    
    /* Dealing the one element case as base case is necessary */
    
    // Reverse the list except the first element
    reversedHead = reverseList(head.next);
    
    /* Observe that reversedHead would be the last element in the original list */ 
    /* The tricky part is that you still have access to the last element in the reversed list */
    /* This makes it O(n) instead of O(n^2) */
    
    newLastElement = head.next;
    
    // If the last element exists, connect it to the first element
    if(newLastElement) newLastElement.next = head;
    
    // Block the unnecessary access of the previous head
    head.next = null;
    
    // Remember to return the new head
    return reversedHead;
};
