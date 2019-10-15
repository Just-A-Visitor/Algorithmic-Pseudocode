
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head);
};

/* Removes duplicates (while storing a single copy) */
ListNode* Solution :: deleteDuplicates(ListNode* head)
{
    // Empty List / Single Element, Nothing to delete
    if(!head or !head->next) return head;

    /* Recursively delete duplicates in the remaining list */

    // Remember to connect the returned value
    head->next = deleteDuplicates(head->next);

    // If values match, return the cleaned version, else original
    if(head->val == head->next->val)
        return head->next;
    else
        return head;
}
