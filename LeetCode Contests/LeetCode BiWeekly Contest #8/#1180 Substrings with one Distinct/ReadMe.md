# Intuition
Call a substring good if it only contains a single distinct character. Now, define a dp state, where `dp[i]` represents the number of good substrings starting at `i`. 
Now, if `str[i] == str[i+1]` , it means that `str[i]` can be appended to each good substring formed by the index `i+1`. Moreover, it  can also create a single substring consisting of just `str[i]`. 

Hence, the final DP relation is `dp[i] = (str[i] == str[i+1]) ? dp[i+1] + 1 : 1`.

# Reducing the space Complexity
Notice that to compute `dp[i]`, we only need the information of `i+1`. Hence, we can use a single counter, without having to create a vector. Hence, the space complexity would be O(1).



[Blog](https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/discuss/376879/A-Novel-Method-with-DP-O(n)-or-O(1)-With-Explanation)
