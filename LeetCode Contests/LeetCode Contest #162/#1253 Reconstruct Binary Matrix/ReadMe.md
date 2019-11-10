# Intuition
* First, intialize both the rows as `0`. Now, fill the indices where the vertical column sum is `2` (as they don't have a choice). So, now we only need to make choices for the columns with sum `1`. Find out the current sum of the first row. Compare it with the required amount. If the difference becomes negative, it means that there is no solution. Else, greedily fill the required `1s` in the top row and the remaining `1s` in the bottom row. Finally, check if the sum of the bottom row equals `lower`


# Blog
[Link](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/discuss/425170/Detailed-Explanation-using-Greedy-Approach)
