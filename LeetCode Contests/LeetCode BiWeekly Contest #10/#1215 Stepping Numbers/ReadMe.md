# Intuition
The idea is to create all the valid numbers in advance. Start out with a single number. There can be at most 2 possibility for the number containing one extra digit at the end. 

* If the last number is not 9, then the next end digit can be `current_end_digit + 1`. We call this the left child.
* If the last number is not 0, then the next end digit can be `current_end_digit - 1`. We call this the right child.

We keep on creating the tree in a post order traversal and terminate the recursion as soon as we see a number bigger than the limit. In the meanwhile, we keep storing the created numbers in a set. Finally, we traverse the set in a sorted order and extract the numbers within the given range into a vector.


# Blog
[Link](https://leetcode.com/problems/stepping-numbers/discuss/397610/Detailed-Explanation-using-Post-Order-Traversal)
