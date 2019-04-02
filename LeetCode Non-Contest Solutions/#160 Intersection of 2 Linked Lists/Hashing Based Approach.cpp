class Solution
{
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);
};

/* Returns the intersection point of 2 linked lists */
ListNode* Solution :: getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // Create the map to store the address of the first list
    unordered_map<ListNode*, int> address;
    
    // Populate the first list in the map
    while(headA)
    {
        address[headA] = 1;
        headA = headA->next;
    }
    
    // Traverse the second list and find the first repeating address
    while(headB)
    {
        // If the node is hashed, it is the start of the intersection
        if(address.find(headB)!=address.end())
            return headB;
        headB = headB->next;
    }
    
    // If it reaches here, it means no intersection
    return nullptr;
}
