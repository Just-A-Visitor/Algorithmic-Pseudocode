
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head);
};

/* Removes duplicates (while storing a single copy) */
ListNode* Solution :: deleteDuplicates(ListNode* head)
{
    // Make a backup to return it later
    ListNode* backupHead = head;

    // Traverse to the first distinct element
    while(head)
    {
        // Start from the next node
        ListNode* nextDistinct = head->next;

        // Keep going forward if you see repeated values
        while(nextDistinct and nextDistinct->val == head->val)
            nextDistinct = nextDistinct->next;
        
        // Connect it so that all dupliactes vanish
        head->next = nextDistinct;

        // Move to the next node
        head = head->next;
    }

    // Return the original Head
    return backupHead;
}
