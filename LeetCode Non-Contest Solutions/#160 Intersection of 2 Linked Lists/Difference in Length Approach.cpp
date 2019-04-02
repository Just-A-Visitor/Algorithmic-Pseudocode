class Solution
{
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);
};

/* Returns the intersection point of 2 linked lists */
ListNode* Solution :: getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // Create the backup to access it later
    ListNode* backupA = headA;
    ListNode* backupB = headB;
    
    // Calculate the length of the first linked list
    int lengthA=0;
    while(headA)
    {
        lengthA++;
        headA = headA->next;
    }
    
    // Calculate the length of the second linked list
    int lengthB=0;
    while(headB)
    {
        lengthB++;
        headB=headB->next;
    }
    
    // Create 2 pointers to track smaller and larger list
    ListNode* smallList;
    ListNode* bigList;
    
    // Capture the smaller and larger list
    if(lengthA < lengthB)
    {
        smallList = backupA;
        bigList   = backupB;
    }
    else
    {
        smallList = backupB;
        bigList   = backupA;
    }
    
    // Get the difference in length
    int difference = abs(lengthA-lengthB);
    
    // Traverse the extra length in the big list
    while(difference)
    {
        bigList = bigList->next;
        difference--;
    }
    
    /* Now, both the lists are of equal length */
    
    // Traverse them simultaneously and compare
    while(smallList && bigList)
    {
        if(smallList==bigList)
            return smallList;
        
        smallList = smallList->next;
        bigList   = bigList->next;
    }
    
    // If it reaches here, it means it doesn't intersect
    return nullptr;
}
