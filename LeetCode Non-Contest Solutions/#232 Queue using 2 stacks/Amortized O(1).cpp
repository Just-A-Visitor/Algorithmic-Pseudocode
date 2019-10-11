/* Intuition for the solution */
/***

1) We maintain 2 stacks, entryStack and exitStack
2) Whenever we need to push an element , we simply push it onto the entry stack
3) Now, supoose we have 6 elements in the entryStack
   1 ,2, 3, 4, 5, 6 (with 6 being the latest element pushed into the stack)
4) Suposse we ask 6 queries of the form queue.front, whose answer is 
   1, 2, 3, 4, 5, 6
5) Well, since 1 is buried at the bottom, we cannot extract it. So another option is to 
   flip the stack and answer the queries in O(1)
6) How do we flip a stack so that it becomes a queue ? Simply put it in the entryStack 
   one by one thus reversing their ordere and making it a queue
7) Now, as long as the entryStack is not empty, we can answer the queries of pop, empty and 
   top in O(1)
8) Meanwhile, If push queries come, just store them in the entry stack.
9) If the exitStack finishes off, fill it via flipping the entry stack.

***/

   






class MyQueue
{
public:
    
    stack<int> entryStack;
    stack<int> exitStack;
    
public:
    /** Push element x to the back of queue. */
    void push(int x);
    
    /** Removes the element from in front of queue and returns that element. */
    int pop();

    /** Get the front element. */
    int peek();
    
    /** Returns whether the queue is empty. */
    bool empty();
};

/* Pushes the element in the queue */
void MyQueue :: push(int x) 
{
    // Just push it in the entry stack
    entryStack.push(x);
}

/* Return the front element of the queue*/
int MyQueue :: peek()
{
    // If the exit stack is not empty, then it is first in the queue 
    if(!exitStack.empty()) return exitStack.top();
        
    // Else the exit stack is empty, so we need to flip the contents of the entryStack
    // and put it in the exitStack for future use
    while(!entryStack.empty())
    {
        exitStack.push(entryStack.top());
        entryStack.pop();
    }
        
    return exitStack.top();
}
    
/* Checks if the stack is empty or not */
bool MyQueue :: empty()
{
    // Since the elements are distributed in 2 stacks, check if both of them are empty or not 
    return (entryStack.empty() && exitStack.empty());
}

/* Returns the top element of the queue */
int MyQueue :: pop()
{
    // First peek the element (which obviously flips the elements and fills it into the exitStack)
    int top = peek();
    
    // Since the element to be popped is already adjusted to the top of the exitStack
    // (Via the peek function), simply pop it now
    exitStack.pop();
    
    // Return the saved element
    return top;
}
