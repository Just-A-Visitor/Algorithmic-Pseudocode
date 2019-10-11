# Intuition
Find the longest common subsequence of the string and its reverse. Now, `n - lcs_length` is the smallest number of characters that needs to be deleted from the string to make it a palindrome. Hence, we just check whether this value is less than or equal to `k` or not.

# To Do
It can also be done using **Edit Distance**. (Why is `edit_distance <= 2*k` and not `k`?)

# Review
Excellent question to see the application of standard problems. It's like a new paradigm for **Palindromes**

# Blog
[Link](https://leetcode.com/problems/valid-palindrome-iii/discuss/397602/Detailed-Explanation-using-Longest-Common-Subsequence)
