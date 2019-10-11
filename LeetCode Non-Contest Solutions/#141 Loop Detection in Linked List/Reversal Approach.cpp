class Solution
{
public:
    bool hasCycle(ListNode *head);
};

/* Detects cycle in a linked list */
bool Solution :: hasCycle(ListNode *head)
{
    // Declare the auxillary pointers
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* temp = nullptr;

    // Perform the exact same steps a s reversal
    while(current)
    {
        // The usual stuff
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;

        // Check if you encounter head again
        if(current==head) return true;

    }

    // The list was successfully reversed. No Cycle
    return false;
}
