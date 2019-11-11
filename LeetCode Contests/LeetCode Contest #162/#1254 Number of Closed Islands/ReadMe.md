# Intuition
The idea is simple. We want to perform a DFS on the matrix to find the connected component of `0s`.  Call a connnected component valid if none of its element lies on the border of the matrix. It is clear that we need to find all the valid connected component.

*  We consider a cell with value `1` as a blocked cell and a cell with value `0` an empty cell. We also need to maintain a `visited` matrix, but we can just modify the input matrix, setting each `0` to `1` after we have visited it.

* Now, all that remains is to start a DFS from the first unvisited `0`. This DFS call would cover all the elements of this connected component (As per the property of DFS). Now, we just need to keep track whether any element in this connected component touches the boundary of the matrix or not. If it does, this connected component becomes invalid. If none of the elements touch the boundary, it means that it is surrounded by`1s` on all the sides. Hence, we increment the counter for answer.

* To check whether any element in the connected componenet is a terminal node, we can just maintain a boolean variable called `terminal` and set it to true whenver we see a terminal node during the DFS call. After the DFS, we only increment the counter if `terminal` is set to false. 

* How do we look out for terminal nodes? Note that if we hit a terminal node, we are also going to hit an out of bound neighbour. Hence, if we see an out of bounds index, we update the `terminal` to `True`

# To Do 
`votrubac's` approach is more suitable for this question. The flood fill approach makes it very easy. After flooding all the lands in the connected components of the terminal nodes, we just need to find the remaining connected componenets. See solution [here](https://leetcode.com/problems/number-of-closed-islands/discuss/425150/JavaC%2B%2B-with-picture-flood-fill)


# Blog
[Link](https://leetcode.com/problems/number-of-closed-islands/discuss/425120/Detailed-Explanation-using-Terminal-Nodes)
