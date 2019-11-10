# Intuition
The idea is simple. We want to perform a DFS on the matrix to find the connected component of `0s`.  Call a connnected component valid if none of its element lies on the border of the matrix. It is clear that we need to find all the valid connected component.

*  We consider a cell with value `1` as a blocked cell and a cell with value `0` an empty cell. We also need to maintain a `visited` matrix, but we can just modify the input matrix, and convert each visited cell to a unique value, say `2`. 

* Now, all that remains is to start a DFS from the first unvisited `0`. This DFS call would cover all the elements of this connected component (As per the property of DFS). Now, we just need to keep track whether any element in this connected component touches the boundary of the matrix or not. If it does, this connected component becomes invalid. If none of the elements touch the boundary, it means that it is surrounded by`1s` on all the sides. Hence, we increment the counter for answer.

* To check whether any element in the connected componenet is a terminal node, we can just maintain a boolean variable called `terminal` and set it to true whenver we see a terminal node during the DFS call. After the DFS, we only increment the counter if `terminal` is set to false. 

# Blog
[Link](https://leetcode.com/problems/number-of-closed-islands/discuss/425120/Detailed-Explanation-using-Terminal-Nodes)
