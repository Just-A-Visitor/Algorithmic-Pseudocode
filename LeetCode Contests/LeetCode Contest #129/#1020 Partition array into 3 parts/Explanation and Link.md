**Test Cases**
* Here are the test cases that messes up the entire algorithm

1) [1,-1,1,-1,1,-1]
2) [0,1,-1]


[Blog](https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/discuss/260873/detailed-explanation-c-on-time-o1-space)

https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/discuss/260873/detailed-explanation-c-on-time-o1-space


**Intuition**
* Suppose the array was indeed breakable into 3 parts with equal sum. Then the array would look like `S S S`, where `S` represents the sum 
of each segment of the array. Hence, the entire sum would be `S+S+S`=`3S`. 
* Assume that the array is breakable into such segments. Let us compute the prefix sum of the array. Since the array resembles `S S S`, 
therefore the prefix sum would resemble `S 2S 3S`. 
* So we just  need to check if the prefix sum contains `S` `2S` & `3S` (in the same order). Since the sum is already `3S`, we do not need to 
worry about `3S`. All that remains is to check whether the prefix sum contains `S` and `2S` such that `2S` is to the right of `S`. 
[**Update** ---- We do have to check for `3S`.]
---
**Observation** 
* If the accumulated sum is not a multiple of 3, then the array cannot be partitioned in such a way. This is fairly obvious from the above remark.
---
**Algorithm**
* First, calculate the entire sum. If it is not a multiple of 3, return false.
* Intialise 3 variable, `firstFound`, `secondFound`  and `thirdFound` which capture if `S`, `2S` and `3S` have appeared in the desired order or not.
* Start calculating the prefix sum. As soon as you see `S`, set `firstFound` to true and start searching for `2S`. As soon as you see `2S`, set `secondFound` to true and start searching for `3S`.
* In the end, if all are true, it means that `S` was found before `2S` (and `2S` was found before `3S`). Therefore, we can cut our array at the point `S` and `2S` to give us 3 parts with equal sum.
---

**Update**

* Looks like I was wrong. You do have to check the for `3S` as the subarrays may overlap if `S==2S==3S` which happens if `S==0`. So, we need to check if there exists 3 disjoint sets or not. Thanks [rock](https://leetcode.com/rock/) for pointing this out.
---
