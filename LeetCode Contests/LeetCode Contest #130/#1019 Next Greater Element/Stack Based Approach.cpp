
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode* head);
};

/* Returns the next greater element in the linked list */
vector<int> Solution :: nextLargerNodes(ListNode* head)
{
    // Create a vector and copy the list
    vector<int> a;
    while(head)
    {
        a.push_back(head->val);
        head = head->next;
    }
    
    // Create the vector to store the answer;
    int n = a.size();
    vector<int> answer(n);
    
    // Create the monotonic stack
    stack<int> myStack;
    for(int i=n-1; i>=0; i--)
    {
        // Pop all smaller/equal elements from the stack
        while(!myStack.empty() && a[i]>=myStack.top())
            myStack.pop();
        
        // The remaining element is the next greater element
        answer[i] = myStack.empty()? 0 : myStack.top();
        
        // Push this element onto the stack
        myStack.push(a[i]);
    }
    
    // Return the answer
    return answer;
}
