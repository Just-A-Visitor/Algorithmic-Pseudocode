class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* firstList, ListNode* secondList);
    ListNode* insertFront(ListNode* head, int val);
};

/* Inserts a node at the front and returns the new head*/
ListNode* Solution :: insertFront(ListNode* oldHead, int val)
{
    ListNode* newHead = new ListNode(val);
    newHead->next = oldHead;
    return newHead;
}

/* Adds 2 numbers to a single linked list */
ListNode* Solution :: addTwoNumbers(ListNode* firstList, ListNode* secondList)
{
    // Stacks to virtually reverse the lists
    stack<int> first;
    stack<int> second;
    
    // Push the first list onto the stack
    while(firstList)
    {
        first.push(firstList->val);
        firstList = firstList->next;
    }
    
    // Push the second list onto the stack
    while(secondList)
    {
        second.push(secondList->val);
        secondList = secondList->next;
    }
    
    int carry = 0;
    int sum = 0;
    ListNode* finalList = nullptr;
    
    // Keeping summing as long as at least one number exists
    while(!first.empty() || !second.empty() || carry)
    {
        // Extract the last digits, if they exist
        int firstDigit  = first.empty()  ? 0 : first.top();
        int secondDigit = second.empty() ? 0 : second.top();
        
        // Remove the last digits, if they exist
        if(!first.empty())  first.pop();
        if(!second.empty()) second.pop();
        
        // Sum it up, remove and store the carry
        sum = firstDigit + secondDigit + carry;
        carry = sum/10;
        sum = sum%10;
        
        // Append it to the front
        finalList = insertFront(finalList,sum);
    }
    
    // Return the sum
    return finalList;
}
