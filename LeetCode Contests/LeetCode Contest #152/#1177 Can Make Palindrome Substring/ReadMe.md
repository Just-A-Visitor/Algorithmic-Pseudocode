# Intuition

* * Let us create a **DP** matrix, where `dp[i][j]` represents the count of `i-th` character in the substring `str[0...j]`. 

* Let us fix an `i` and see the recursive structure. 
	* Suppose, the `j - th` character is `i`, then `dp[i][j] = dp[i][j-1] + 1`.
	* If the `j-th` character is not `i`, then `dp[i][j] = dp[i][j-1]`
	* If `j == 0`, `dp[i][j]` would be one if the first character is equal to the `i-th` character or else zero.

* For each query, we find out the count of the each character in the substring `str[left,...right]` by the simple relation, `dp[i][right] - dp[i][left] + (str[left] == i + 'a')`.

* Get the count of unmatched pairs. It can be atmost 26.

* We need to convert half unmatched to the remaining unmatched. If the count is `odd`, we can leave one element unmatched. Hence, we take the floor value of `unMatched / 2` , and check whether it is possible to convert this many values or not.


[Blog Link](https://leetcode.com/problems/can-make-palindrome-from-substring/discuss/372153/Detailed-Explanation-using-DP)
