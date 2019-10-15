# Intuition
Define 2 DP matrix, `left` and `right`. The DP definition is `left[color][index]` represents the minimum distance of the color `color` to the left of the index `index`. Similarly, `right[color][index]` represents the minimum distance of the color `color` to the right of the index `index`. Note that we also include the current element in the DP definition.

For each of the 3 colours, we can fill both the `dp` matrix in linear time. Let us fix any color, say 1, and fix a dp matrix, say `left`. Now, the minimum distance of red from the `i-th` index to the left will be zero if the `i-th` index is of red color. If the `i-th` color is not zero, we can look at the minimum distance of the `i-1 th` index. If the index is -1, it means that no red exists in left half. Hence, the current distance would be -1. If not, the current distance would be `oldDistance + 1`.  A similar argument can be made for `right`.

At the end, for each index, we can find the minimum distance to the left and right and return the minimum of both of them.


## Getting the Result from the pre-computed values
For any query, we are given the value of the color and the index. We find out the minimum distance of that color in the left as well as right part. If either of them is -1, the answer is the other one. If none of them is -1, then the answer is the minimum of the two. 

# Time Complexity 
O(n);


[Blog](https://leetcode.com/problems/shortest-distance-to-target-color/discuss/376925/A-Novel-Method-using-DP-O(n)-or-O(n)-Explained)
