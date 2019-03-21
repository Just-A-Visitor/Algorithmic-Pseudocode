**Intuition**
* First, how do we clone a **Normal** linked list? (i.e, a linked list with no **Random** field). One easy way is to iterate the list and create the nodes on the fly. 
* This is exactly **Step 1** of the algorithm. We clone the linked list while not caring about the random pointers (setting it to **Null**).
* Now, suppose that you have a rope that takes you from any node in the original list to its counterpart in the cloned list. (This is demonstrated by the vertical lines in the picture). How do we actually correct the **random** pointers using this rope? Well, one easy way is to traverse both the lists simultaneously, get the **random** field of the top node, use it reach the location of the **random pointer** (in the top node) and then use the rope to get down vertically, This would be the **random node** for the cloned counterpart.
* All that remains is to create the ropes. This can be easily done via **HashMap**. The key is the *address* of the top nodes while the value is the *address* of its copy. The map can be populated while creating the list. 
* **Remark** ---- *Node* to *Node* hashing is necessary to deal with duplicates. (As can be seen with **2** in the picture).

---

**Example**

![image](https://assets.leetcode.com/users/just__a__visitor/image_1553084036.png)

* First, the nodes are cloned with randome pointers set to **Null**. Meanwhile, the virtual ropes are created via hashmap.
* Let us say we want to poulate the random field of **1**. We first traverse to **3** (top) and then go down to **3** (bot) and set the random field for the bottom 1.

**Miscellaneous**
The above method handles duplicates but does not handle *Loops* in the linked list. (As it would lead to infinite loop while cloning the lined list). However, this can be easily remedied by using a map and checking whether we have reached the same node twice or not (instead of checking for **null**) which would ensure that the cloning process terminates.


Sorry, I didn't mean to extend it so long, but I hope you understand the concept and its working.
