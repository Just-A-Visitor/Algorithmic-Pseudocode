# Review
* I coded the Brute Force BFS in 10 minutes. It is correct but it TLEs. The reason is that although each node would be inserted atmost once in the queue, we still need to go through all of them. For example, consider a complete graph. BFS would still run the same, but the adjacency list of each vertex would contain `n-1` elements. Hence, to just traverse the adjacency list, you take up **O(n^2)** time. The equivalent situation in this problem is that if all the array entries are set to infinity, then you'll visit **O(n^2)** elements. 

* Of course, the BFS solution is correct. (It passed all the test cases on GFG).

# To Do
* Optimize the bruteforce BFS
