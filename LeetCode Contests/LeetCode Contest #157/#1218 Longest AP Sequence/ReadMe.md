# Intuition
Let us define `dp[i]` as the longest arithmetic subsequence which starts at `i`.

If the subsequence starts at `i`, then it means that to fill the `i-th` entry we do not need to look on the left. Hence, this gives us a hint that we should start filling the `dp` matrix from the right. 

Suppose, at any stage we are at the `i-th` element. By definition, this is the first term of our subsequence. Hence, we need to find whether the second term `a[i] + diff` exists in the right half or not. This suggests us to keep a hash map to store the running `dp` values. If it exists, we also need to find what is the maximum dp value associated with it.

So, after checking the maximum dp value from hashmap, we can update the maximum dp value in the hashmap. Hence, `dp[i] = 1 + max_dp_value[next_term]` , where `next_term = a[i] + diff`. 


# Blog
[Link](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/discuss/398201/Detailed-Explanation-using-DP-O(n))
