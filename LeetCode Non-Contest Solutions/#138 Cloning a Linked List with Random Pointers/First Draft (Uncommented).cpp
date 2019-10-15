
/* Warning ---> This code would fail for lists with cycles or duplicate node values */

class Solution
{
public:
    Node* copyRandomList(Node* orig_head);
};

/* Deep Copies the given linked list */
Node* Solution :: copyRandomList(Node* orig_head)
{
    // Handle the corner case
    if(!orig_head) return orig_head;
    
    Node* copyHead = new Node(orig_head->val, nullptr, nullptr);
    Node* newHead = copyHead;
    Node* oldHead = orig_head->next;
    
    while(oldHead)
    {
        newHead->next = new Node(oldHead->val, nullptr, nullptr);
        newHead = newHead->next;
        oldHead = oldHead->next;
    }
    
    // Map the address of the new copies
    unordered_map<int, Node*> address;
    
    newHead = copyHead;
    while(newHead)
    {
        address[newHead->val] = newHead;
        newHead = newHead->next;
    }
    
    // Traverse both the lists together and fill the random pointers
    oldHead = orig_head;
    newHead = copyHead;
    
    while(oldHead && newHead)
    {
        newHead->random = oldHead->random? address[(oldHead->random)->val] : nullptr;
        oldHead = oldHead->next;
        newHead = newHead->next;
    }
    
    return copyHead;
}
