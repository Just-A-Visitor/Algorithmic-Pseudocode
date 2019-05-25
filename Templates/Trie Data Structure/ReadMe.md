# Thoughts    
It's been a long time since I've learned something new related to coding. This was a great learning experience. So simple, yet so powerful!

---

# Important Links / Credits   

All credits goes to the evergreen [GeeksForGeeks](https://www.geeksforgeeks.org/trie-insert-and-search/). I've lost count of how many times **GFG** has helped me in the past. I am still amazed at the fact that this resource is completely free.

---

# Walkthrough

* **TrieNode**
    * This indicates the structure of each node in the collection.
    * Each node  has a **isEndOfWord** field to indicate whether a word ends there.
    * It also has 26 children. Presence of any children indicates that there is a word in the collection where the successor of the current letter is the children.

There are 3 main functions.

* **getNode**
    * This function creates a new trie node and returns the pointer.
    * It also intialises all children to **null** and marks **isEndOfWord** as false.

* **Insert**
    * This function inserts the given string into the existing collection of strings.
    * **Steps**
        * Create a crawling pointer **pCrawl**, initially pointing to the root.
        * For each character in the string, do
            * Extract the numberical indexing of the current character, i.e **index**. It will lie between 0 and 25 (both inclusive)
            * If the children of this index already exists, just go down to the children.
            * If the children does not exist, create the children of this index and then go down.
            * This ensures that all the characters in the string are stored in the collection.
        * At the end, **pCrawl** will be pointing to the equivalent position of the last character in the string. Mark the **isEndOfWord** field of **pCrawl** as **true** to indicate a new word.

* **Search**
    * This function returns **true** if the query string is present in the collection.
    * **Steps**
        * Create a crawling pointer **pCrawl**, initially pointing to the root.
        * For each character in the string, do
            * Extract the numberical indexing of the current character, i.e **index**. It will lie between 0 and 25 (both inclusive)
            * If the crawling pointer or the children at index **index** vanishes, return **false** as the word cannot be formed.
            * Move to the children at the index **index**.
        * At the end, if the crawling pointer is pointing to **null**, it indicates that the last letter of the string is not present.
        * If crawling pointer is not **null** and the **isEndOfWord** field of the crawling pointer is set to true, return **true** indicating that the string is present.
