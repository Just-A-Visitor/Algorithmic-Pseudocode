# Intuition
The algorithm is straightforward. The first intuition, as the name **Least Recently Used** suggests, is to use a queue. For each new page, we append it to the back to the queue. If the cache becomes full, we pop an element from the front of the queue (FIFO order). The only problem arises is when an element is being refreshed (i.e, we are accessing an element which is somewhere at the middle). Clearly this element needs to go at the back of the queue now. Since we can't access any random element in a queue, we'll use **STL's** `list` and `map` to mimick the process.

# Miscellaneous
* Getting an iterator to the last element of an STL container is a very tricky task. (`container.end()` does not return an iterator to the last element of the container). On the other hand, `container.begin()` returns an iterator to the front element of the container. Hence, avoid dealing with iterators of the last element.

* Ideally, in a queue, new elements enter at the back and leave from the front. However, on a new entry, it would be difficult to update the iterator of the new element if we place it at the back. But, if we mirror the process and assume that new elements will only enter from the front and old elements will only leave from the back, the updation would be quite easy.

* To remove the least recently used element, we can simply use `myMap.erase(dq.back().key)` followed by `dq.pop_back()`.

* To insert a new element, we can simply do `dq.push_front(Node(key, value))` followed by `myMap[key] = dq.begin()` . (Inserting at front has saved us the hassle of finding the iterator to the last element).

* Make sure that you understand the difference between `container.front()`, `container.begin()`, `container.back()`, `container.end()`, `container.push_front()`, `container.pop_front()`, `container.push_back()`, `container.pop_back()`.


# Algorithm
* Create a `Node` class to store the (key,value) pairs. Make sure to create the constructor. You can also use `pair<int,int>` if you wish, but remember to do `typedef` or else your code will look messy.

* For the instance variables, create the `capacity` variable, an unordered map which maps keys to `list<Node> :: iterator` and an STL list which stores the nodes. Create the constructor initializing the capacity.

* We'll create 3 functions to facilitate our task
    * **Evict**
        * This function takes a key and deletes it if it is present in the cache.
        * To delete the key, search its iterator in the map, and delete it from the cache. After that, erase the key from the map. 
        * Do not mess the order or you'll lose the location of the iterator.

    * **Put**
        * This function inserts the key value pair (and overwrites if necessary).
        * First, evict the existing key (if present).
        * Check if the cache is full or not. If it is, first remove the last element's key from the map and then pop the last element from the cache. Do not mess the order. 
        * Now, we just need to insert the new element. Use `dq.push_front()` and update the map using `myMap[key] = dq.begin()`

    * **Get**
        * This function tries to refresh the key if it is present. It returns the value of the key
        * If the key is not present in the map, return -1
        * Find the iterator of the key, extract the value and save it.
        * To refresh the element, evict it and use the **put** function to re-insert the value.
        * Return the saved value

# Working
See this [link](https://www.geeksforgeeks.org/lru-cache-implementation/) to visualize how the algorithm works.

# Credits 
[GeeksForGeeks](https://www.geeksforgeeks.org/lru-cache-implementation/)
