class Solution
{
public:
    bool hasCycle(ListNode *head);
};

/* Detects cycle in a linked list */
bool Solution :: hasCycle(ListNode *head)
{
    // Start both the pointers at the head
    ListNode* walker = head;
    ListNode* runner = head;

    // Keep moving as long as both exist
    while(walker and runner)
    {
        // Take one/two step depending on the person
        walker = walker->next;
        runner = runner->next ? runner->next->next : nullptr;

        // The nullity check is imortant [Consider a single element]
        if(walker and runner and walker==runner) return true;
    }

    // If it has reached here, it means one pointer was null
    return false;
}
