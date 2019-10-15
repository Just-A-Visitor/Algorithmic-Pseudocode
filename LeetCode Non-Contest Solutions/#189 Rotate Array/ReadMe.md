# Intuition

First of all, convince yourself that normalizing `k` does not affect the output. That is, if `k>n` , normalizing `k` to `k%n` will produce the same result.

So now, **WLOG**, we can assume that `k` is less than `n`. Let us call the first `n-k` elements as **Branch_1** and the last `k` elements as **Branch_2**. Now, what does rotation mean in terms of branches? Let us consider an example. 

Take 10 elements, indexed from 0 to 9. 

`0  1 2 3 4 5 6 7 8 9`. Let `k` be 14.

* Normalize it to get `k` as 4.
* **Branch_1** is `0 1 2 3 4 5`.  
* **Branch_2** is `6 7 8 9`.
* The result is `6 7 8 9 0 1 2 3 4 5`.
* As you can clearly see, the result is **Branch_2 Branch_1** (while the original array was **Branch_1 Branch_2**). 
 
---

So, it is clear that if you pick up the last `k` elemnts (in the same order) and append it to the front, you'll get the answer. Now, how do we accomplish the concatenation in O(n) time O(1) space?

* First, let us reverse the entire array. (This can be done in [O(n) | O(1)].
* This ensures that we have the new ordering as **Branch_2 Branch_1**.
* Are we done? No. As the elements of **Branch_1** and **Branch_2** is internally reversed. All we need to do is correct them. 
* we know that **Branch_2** has `k` elements. So, we will reverse the first `k` elements again.
* Similarly, we know that **Branch_1** has `n-k` elements. So, we will reverse the last `n-k` elements again.
* Done!

# Credits
This amazing solution was borrowed from [here](https://leetcode.com/problems/rotate-array/discuss/304476/O(n)-time-O(1)-space-Iterative-Solution)
