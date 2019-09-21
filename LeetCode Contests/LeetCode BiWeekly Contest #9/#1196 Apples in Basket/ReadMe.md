# Intuition
The idea is very simple. Keep taking the elements in a greedily manner, that is, take the lightest elements first. This requires sorting the array. After that, I converted it into a **Prefix_Sum** array, and hence each entry would indicate the accumulated sum of the elements to the left. We just need to find the point where it reaches the maximum weight (or stays below it). Of course, a simple approach using `count` and `sum` suffices, I used iterator manipulation and library functions, specifically `auto`, `lower_bound` and `distance`. They can be quite handy at times.

# Complexity
**O(n log (n) )**



[Blog](https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/discuss/386991/Same-Idea-Different-Implementation-C%2B%2B)
