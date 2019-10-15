
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

    // Recursively delete duplicates in the remaining list
    ListNode* nextDistinct = deleteDuplicates(head->next);

    // If values match, return the cleaned version, else original
    if(head->val == nextDistinct->val)
        return nextDistinct;
    else
        return head;
}



/* This approach is wrong. No pointers are modified (only the copies are returned).
   Consider [2,3,3]. The output is [2,3,3] instead of [2,3].
   This happens because you are never changing the next field of any pointer 
*/
