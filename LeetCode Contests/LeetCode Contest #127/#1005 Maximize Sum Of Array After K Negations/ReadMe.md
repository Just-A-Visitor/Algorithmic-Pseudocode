**Intuition**

**Claim** We need to negate the minimum element in the array at each step

**Proof** Observe that negating a positive element make us lose twice the contribution. 
So if the minimum element is positive,we would lose the least possible contribution by negating it.
Also, observe that negating a negative element results in twice the contribution gain in magnitude. 
So the larger the magnitude of the negative element, the larger the gain.


[Blog](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/discuss/252317/detailed-explanation-using-min-heap-without-any-messy-indices)

[Alternate Solution](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/discuss/252254/C%2B%2BPython-Sort)
