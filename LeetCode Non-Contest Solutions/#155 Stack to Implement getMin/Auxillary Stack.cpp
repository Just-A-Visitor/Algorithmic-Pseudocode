class MinStack
{
public:
    stack<int> centralStack;
    stack<int> minStack;
    
    void push(int x);
    void pop();
    int top();
    int getMin();
};

/* Pushes the element to the central stack and updates min value */
void MinStack :: push(int x)
{
    centralStack.push(x);
    
    // If it is the current first element, set it to min
    if(minStack.empty()) minStack.push(x);
    
    // Else compare it with curr_min
    else
    {
        int curr_min = minStack.top();
        
        // Update the minStack if it replaces the curr_min
        // Push duplicates of curr_min also to reserve min while popping
        if(x<=curr_min) minStack.push(x);
    }
}

/* Pops the last element from the stack */
void MinStack :: pop()
{
    int toBeRemoved = centralStack.top();
    centralStack.pop();
    
    // Remove one copy if it is the minimum
    if(toBeRemoved == minStack.top()) minStack.pop();
}

/* Returns the top element */
int MinStack :: top()
{
    // Same as a normal stack
    return centralStack.top();
}

/* Returns a copy of the minimum element */
int MinStack :: getMin()
{
    // Just return the element at the top of the minStack
    return minStack.top();
}
