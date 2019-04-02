[Blog](https://leetcode.com/problems/number-of-enclaves/discuss/265699/Detailed-Explanation-using-Connected-Components-O(n))

**Abstraction**
* We can consider the input as a graph. Every cell in the matrix with the value 1 is a node in the graph.
  There is an edge from one node to another if both the nodes are cardinal neighbours (with value 1). Clearly, the graph is undirected.

---
  
**Connected Components**
* Notice that the graph might not be connected (resulting in a number of islands). Let us call a collection of nodes to lie in the same connected component if every vertex in that collection is reachable from one another and the size of the set is the maximal possible, i.e no-other vertex not included in the set can be accessed from the inside (and vice-versa).
---
**Reducing the Problem**
* Observe that if we can find the component component of all the elements lying on the 4 boundaries, we can easily derive our answer.
* The vertices included in the connected component can always fall off the boundary (by reaching the boundary first and then falling off).
* The vertices not included in the connected component can never be reached from the boundary (and vice-versa). Hence, we can never fall off the boundary if we start at those vertices.
---
**Finding the connected components**
* One obvious way to find the connected components is using **DFS** (Depth First Search). It explores the vertices methodologically untill all the vertices in the connected component have been explored.
* Maintain a boolean 2D vector **visited**. For each of the element on the 4 boundaries, start dfs and consequently visit the neighbours via recursion.
* At the end, unvisited vertices with value 1 are the excluded vertices. Find and return their count.
---
**Improving the space complexity**
* We are already using implicit stack space for recursion (via the dfs calls). It's hard to improve upon that.
* However, we can define the **visited** vector implicitly. Whenever we want to visit a vertex, we update the value of that vertex to -1.
---
**DFS**
* We first check if the cell passed is valid or not (as boundary elements do not have all neighbours). If it is not, we terminate the process.
* If the value of the cell is zero, it means it is not even a node, so we terminate the process.
* If the value is -1, it means that this node has already been visited, so we terminate.
* Else, we visit the this vertex (by setting the value to -1).
* Then, we visit all the cardinal neighbours. Before the the final function is returned, all nodes reachable from this node is visited.
---
**Algorithm**
* Extract the *ROW* size and *COL* size.
* Extract the row index of the boundaries, i.e 0 (top boundary) and **ROW-1**(bottom boundary).
* Extract the col index of the boundaries, i.e 0 (left boundary) and **COL-1**(right boundary).
* For the top and bottom boundaries, fix the row number and vary the columns while performing dfs on all the cells of those boundaries.
* Similarly, start dfs from the left and right boundaries.
* At the end, traverse the matrix and return the count of remaining ones.
---
**Time Complexity**
* Notice that we can encounter each cell atmost 4 times (by the 4 neighbours). Once the cell is visited, it won't be considered again. Hence, the net effect is 3-4 traversals of the matrix.
* At the end, we traverse the matrix once.
* Hence, the time complexity is **O(m*n)**.
  
---
