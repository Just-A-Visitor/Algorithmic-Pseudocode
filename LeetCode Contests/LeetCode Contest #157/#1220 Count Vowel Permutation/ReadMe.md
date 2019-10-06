# Intuition
Let us visualize this as a graph problem. From the above rules, we can create a directed graph where an edge between characters `first` and `second` imply that it is permissible to write `second` immediately after first. Hence, the question converts to, **Given a directed graph, how many paths of length `n` are there?** 

![image](https://assets.leetcode.com/users/just__a__visitor/image_1570334589.png)

Now, Let us say that `dp[n][char]` denotes the number of directed paths of length `n` which end at a particular vertex `char`. Then, we know that the last vertex in our path was `char`. However, let's focus on the last second vertex. It could have been any of the vertex which has a direct edge to `char`. Hence, if we can find the number of paths of length `n-1` ending at these vertices, then we can append `char` at the end of every path and we would have exhausted all possibilites.

Hence, `dp[n+1][x] = sum of all dp[n][y]` such that there is a directed edge from `y` to `x`. 

# Blog   
[Link](https://leetcode.com/problems/count-vowels-permutation/discuss/398222/Detailed-Explanation-using-Graphs-With-Pictures-O(n))

