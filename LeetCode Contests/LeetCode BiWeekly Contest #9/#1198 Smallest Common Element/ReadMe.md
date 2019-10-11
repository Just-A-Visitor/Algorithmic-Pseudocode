# Intuition
First of all, remove the duplicate elements from each row. This can be easily done via the `erase` and `unique` function. Now, we build a hashmap to maintain the frequency of each element. Finally, we traverse the first row fo the matrix in a sorted order and return the first value which has frequency equal to the number of rows in the matrix. If there is no such element present, we return -1.


[Blog](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/discuss/386997/A-Concise-Implementation-C%2B%2B)
