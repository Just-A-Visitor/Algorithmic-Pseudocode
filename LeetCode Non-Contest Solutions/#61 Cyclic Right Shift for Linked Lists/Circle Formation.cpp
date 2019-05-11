class Solution
{
    public:
    ListNode* rotateRight(ListNode* head, int k);
};

/* Rotates a linked list to the right by k places */
ListNode* Solution :: rotateRight(ListNode* head, int k)
{
    // Handle the base case
    if(!head) return head;

    /* Find out the length along with the tail */

    // Length has to be intialized as 1 instead of 0
    int length = 1;

    // Traverse the list and find the tail
    ListNode* tail = head;
    while(tail->next)
    {
        tail = tail->next;
        length++;
    }

    // Normalize the shift 
    k = k%length;

    // Handle the corner case
    if(k==0) return head;

    // Form a circle
    tail->next = head;

    /* We are sure that the tail is not null and k>0*/

    // Go to the new tail node
    for(int i=0; i<(length-k); i++)
        tail = tail->next;

    // Store the location of the new head
    ListNode* newHead = tail->next;

    // Cut the list here
    tail->next = nullptr;

    // Return the new head
    return newHead;

}
