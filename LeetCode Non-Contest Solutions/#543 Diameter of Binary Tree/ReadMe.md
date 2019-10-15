
[Blog](https://leetcode.com/problems/diameter-of-binary-tree/discuss/285647/Detailed-Explanation-using-Recursion)

# Height of a Binary Tree

Let us see how to calculate the height of a binary tree using post order traversal.
* Suppose we know the height of the left and right subtree. What is the height of the root? Clearly, it is **max(leftHeight,rightHeight) + 1**.
* This gives us the algorithm. Recursively calculate the height of the subtrees and update the height of the root. All that is left is to handle the corner cases.
* If both the subtrees are non empty, we are done, as the formula is correct. 
* Suppose, exactly one subtree is empty. Then the result would be **nonEmptyTreeHeight + 1**. This is also valid.
* What happens if both the subtree is empty? This means that the root is a leaf node. According to the formula, the height of the root is 1.
* Conclusion ===> **We are assuming the height of a leaf node as 1**.

# Calculating the diameter
* The final diameter has the following form. It goes up certain nodes and after a specific node, say **head**, it comes down. 
* Recall that while calculating the height of the tree, the height was computed for each and every node due to recursion. 
* As soon as the height of the node **head** is computed, we can get the diameter as **leftHeight + rightHeight**. Observe that we didn't account for the fact that there are 2 extra edges to reach the left and right subtree. However, this is taken care of by the assumption that leaf nodes have height 1. There is 1 leaf node in each tree which compensates the lost edges. Moreover, this also gives us that the diameter of a leaf node is 0, while its height is 1.

# Algorithm
* Calculate the height of each node and in the meanwhile, update the diameter at each node.
* This ensures that the correct diameter is captured at some stage.

# Credits
The idea was borrowed from [here](https://leetcode.com/problems/diameter-of-binary-tree/discuss/101130/C%2B%2B-Java-Clean-Code)

# Alternate Approach
* Run BFS from the root and get the farthest node (a leaf node). Run BFS from that node and get the farthest node (a leaf node). These two nodes are the end points of the diameter path.
* **I don't know how the above method works. I need to understand the BFS approach more clearly.**

# Alternate Characterization
* The question on LeetCode assumes that the diameter of a tree is the number of edges in the longest path, however **GFG** assumes that it is equal to the number of nodes in the longest path (including terminal nodes).

## Pseuodocode for Alternate Characterization


```
* Assume the height of leaf nodes as 1.
* The diameter will be 1 + leftHeight + rightHeight.
* This assumes that the diameter of a leaf node is 1.
```
