/* Node to store the structure of the page */
class Node
{
    public:
    int key, value;
    
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

/* Class to implement the LRU Cache algorithm */
class LRUCache
{
    private:
    int capacity;
    list<Node> dq;
    unordered_map<int, list<Node> :: iterator> myMap;
    
    // Constructor
    public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    
    int get(int key);
    void put(int key, int value);
    void evict(int key);
};

/* Removes the key if it is present in the cache */
void LRUCache :: evict(int key)
{
    // If it is not present, do nothing
    if(myMap.find(key) == myMap.end())
        return;
    
    // Delete the existing page from queue and map
    dq.erase(myMap[key]);
    myMap.erase(key);
}

/* Accessing the key in the cache */
int LRUCache :: get(int key)
{
    // If the key is not present, return -1
    if(myMap.find(key)==myMap.end())
        return -1;
    
    // Get the iterator of the key
    auto itr = myMap[key];
    
    // Extract the value corresponding to key
    int value = (*itr).value;
    
    /* We need to refresh the key now */
    
    // Delete the key and re-insert to refresh 
    evict(key);
    put(key,value);
    
    // Return the value extracted
    return value;
    
}

/* Inserts the key,value and overwrites if necessary */
void LRUCache :: put(int key, int value)
{
    // Remove the key if already present
    evict(key);
    
    // If cache is full, free up a space
    if(dq.size() == capacity)
    {
        // Remove the least recently used element
        myMap.erase(dq.back().key);
        dq.pop_back();
    }
    
    // Add the incoming element
    dq.push_front(Node(key,value));
    myMap[key] = dq.begin();
}
