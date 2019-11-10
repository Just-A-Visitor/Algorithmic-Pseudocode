# Intuition
* Since the number of words is quite less (14), we can just generate all the subsets. Let's call a subset valid if all the words in that subset can be formed by using the given letters. It is clear that we need to maximize the score of valid subsets. To do this, we generate all subsets, and check if it is valid. If it is, we find its score and update the global maxima.

* To generate the subsets, we create a function call `generate_subset(words, n)`  which generate all the subsets of the vector `words`.  To quickly recap, we have 2 choices for the last element, either to take it or to leave it. We store this choice in an array called `taken` where `taken[i]` represent that the `i-th` element was taken in our journey. We then recurse for the remaining elements.

* When `n` becomes zero, it means we cannot make any more choices. So now, we traverse our `taken` array to find out the elements in this subset. Then we count the frequency of each letter in this subset. If the frequency of each letter is under the provided limit, it means it is a valid subet. Hence, we find the score of this subset and update the maxima.


# Blog
[Link](https://leetcode.com/problems/maximum-score-words-formed-by-letters/discuss/425104/Detailed-Explanation-using-Recursion)
