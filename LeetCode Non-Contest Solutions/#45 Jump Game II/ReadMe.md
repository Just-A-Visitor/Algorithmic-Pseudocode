# Review
* I had solved this question a year ago. This was a nightmare at that time, as I wasn't able to grasp the logic. Today, I stumbled upon this question again and someone in the comment section mentioned BFS. I coded the BFS version (and optimized it) and the logic became crystal clear. Loved working on this problem.    
* I coded the Brute Force BFS in 10 minutes. It is correct but it TLEs. The reason is that although each node would be inserted atmost once in the queue, we still need to go through all of them. For example, consider a complete graph. BFS would still run the same, but the adjacency list of each vertex would contain `n-1` elements. Hence, to just traverse the adjacency list, you take up **O(n^2)** time. The equivalent situation in this problem is that if all the array entries are set to infinity, then you'll visit **O(n^2)** elements. 

* Of course, the BFS solution is correct. (It passed all the test cases on GFG).

* Finally, optimized the BFS solution in 10 minutes.

* The solution on GFG makes the problem look more complicated than it already is.

# Optimizing BruteForce BFS
* Notice that once an element is in the queue, all the elements to the left would also be in the queue.
* Let us maintain a variable called `maxReach` which indicates **the largest index which was pushed into the queue**. 
* Whenever we pop an element from the queue, we just need to check whether we can insert `maxReach + 1` into the queue or not. This is because by definition, everything to the left of `maxReach` (including it) is already in the queue. 
* To do this, we first check whether `maxReach + 1` goes out of bound or not. If not, we then check if we can reach it. How? We know that the largest index that can be reached from current index is `curr_index + a[curr_index]`. So, if `maxReach + 1` is less than or equal to this index, we increment `maxReach` and push it into the queue. We keep doing this for the current element untill we cannot go any further.
* Lastly, notice that the complextiy would be **O(n)** because we are only pushing `maxReach` into the queue (which can only grow to the right and terminates at the end. Hence, we would cross every element at most twice).


# To Do
* Optimize the bruteforce BFS (Done!) 
* Try to do it in O(1) space.

## Round 2
Came back to this question after 7 months. Indeed, the `maxReach` is a bit risky for off-by one errors. Hence, I made the code more concise by using the variable `min_un_reach` which denotes the minimum element not yet reached. Now, the code is more compact.
