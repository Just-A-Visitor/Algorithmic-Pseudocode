class Solution {
public:
    Node* copyRandomList(Node* head) ;
};

Node * Solution :: copyRandomList(Node * origHead)
{
    unordered_map<Node * , Node *>hash ;
    Node *cloneHead = nullptr ;
    Node *clonePrev = nullptr ;
    
    while(origHead)
    {
        Node* cloneNode;
        
        // Only create the node if it has not been created
        if(hash.find(origHead)==hash.end())
            cloneNode = new Node(origHead->val, nullptr, nullptr);
        else
            cloneNode = hash[origHead];

        // Hash this present node and original node
        
        /* The reason why we are doing this is because after traversing some 
         * nodes,we may get a node whose let's say "Node-x" arbitrary pointer 
         * points to the present head and since we have already cloned the current
         * node , so we can use the already cloned node for initialising "node-x"
         * arbitrary location , instead of allocating new memeory for the already
         * cloned node .
         */
        
        // If it is already hashed, then we are just overwriting it. So, everything's fine
        hash[origHead] = cloneNode ;
        
        // Connect the last node if exists with present node of cloned LL .
        if(clonePrev)
        {
            clonePrev->next = cloneNode ;
            clonePrev = cloneNode ;
        }
        
        // Connect the first node to cloneHead
        if(cloneHead == nullptr)
        {
            cloneHead = cloneNode;
            clonePrev = cloneNode ;
        }
        
        // If present node's arbitrary points to some other node , then -->
        if(origHead->random)
        {
            
            // Find whether we have already cloned this node or not .
            // If not , then -->
            if(hash.find(origHead->random) == hash.end())
            {
                // Allocate memory for the arbitrary node .
                
                /* Don't use reserved keywords */
                
                Node * _random = new Node(origHead->random->val, nullptr, nullptr);
                cloneNode->random = _random ;
                
                // Hash this arbitrary node .
                hash[origHead->random] = _random ;
            }
            else
            {
                cloneNode->random = hash[origHead->random] ;
            }
        }
        else cloneNode->random = nullptr;
        
        /* The above line is not needed, but I've included it just for brevity */
        
        // Traverse ahead in original linked list .
        origHead = origHead->next ;
        
        /* It's already set to null */
    }
    return cloneHead ;
}
