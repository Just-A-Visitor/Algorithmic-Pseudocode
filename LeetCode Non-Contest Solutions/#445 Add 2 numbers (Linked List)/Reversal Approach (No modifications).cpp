class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* firstList, ListNode* secondList);
    ListNode* reverseList(ListNode* head);
};

/* The below function has already been tested */

/* Reverses the linked list iteratively */
ListNode* Solution :: reverseList(ListNode* head)
{
    // Pointers to keep track of 3 consecutive nodes
    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode* temp;
    
    // Traverse the list and keep reversing the elements as you encounter them
    while(current)
    {
        // Store the location of the next element
        temp = current->next;
        
        // Link the current element to the previous one
        current->next = previous;
        
        // Update the previous to current
        previous = current;
        
        // Update current to the original next element
        current = temp;
    }
    
    // Remember to return previous as current would be null
    return previous;
}

/* Adds 2 numbers into a linked list */
ListNode* Solution :: addTwoNumbers(ListNode* firstList, ListNode* secondList)
{
    // Reverse both the lists
    firstList = reverseList(firstList);
    secondList = reverseList(secondList);
    
    // Create a sentinel to avoid corner cases
    ListNode* finalList = new ListNode(INT_MAX);
    ListNode* sentinel = finalList;
    
    // Create the variables
    int firstDigit, secondDigit;
    int carry = 0;
    
    // As long as some numbers exist, keep adding
    while(firstList || secondList || carry)
    {
        /* Initialize the digits to zero
         * This ensures that they remain zero, even if the list doesn't exist
         */
        
        firstDigit = 0;
        secondDigit = 0;
        
        // Update the first number if it exist
        if(firstList) 
        {
            firstDigit = firstList->val;
            firstList = firstList->next;
        }
        
        // Update the second number if it exists
        if(secondList) 
        {
            secondDigit = secondList->val;
            secondList = secondList->next;
        }
        
        // Take the sum and extract and remove the carry
        int sum = firstDigit + secondDigit + carry;
        carry = sum/10;
        sum = sum%10;
        
        // Append it at the end. Remember to move forward
        finalList->next = new ListNode(sum);
        finalList = finalList->next;
        
    }
    
    /* You can restore both the lists if you want */
    
    // Reverse and return the answer. Remove the sentinel
    finalList = reverseList(sentinel->next);
    return finalList;
}
