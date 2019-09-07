# Intuition
Consider all `nC2` pairs. For each pair, extract the individual strings in a vector. If the last element of one vector is equal to the first element of the second vector, then merge the 2 vectors and store it in a set. Finally, return the elements from the set. Of course, it can be done without streaming the string but this is another way to look at the problem.


[Blog](https://leetcode.com/problems/before-and-after-puzzle/discuss/376910/A-Novel-Method-using-StringStream-C%2B%2B-Explained)
