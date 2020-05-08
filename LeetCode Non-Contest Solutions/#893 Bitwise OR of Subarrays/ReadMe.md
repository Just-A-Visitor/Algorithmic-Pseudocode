### Review
* A bruteforce approach which works in **O(n^3)** is to generate all subarrays, and collect the answer in a set.

* This can be optimized to **O(n^2)**. Can we find all the distinct OR of the subarrays which start at a specific index in **O(n)**? Well, yes we can do that. Recall that `or(a[i,....k]) = or(a[i...k-1]) or a[k]`. So, at each step we keep appending one new element to our subarray, and calculate the resulting `or` in **O(1)** and store them in a set. Since the subarray can start at any index, hence the total complexity is **O(n^2)**. [Ignoring the effects of the storage set for the answers].

* Can we improve this even more? One thing's apparent by the constraints that an **O(n^2)** solution is not gonna pass. However, here's a hint. You are actually allowed to **generate** all the answers and then print the count. But won't this lead to TLE as the total answers can be of the order **O(n^2)**? Actually, NO. The final answer can be atmost **32N**. Why is that so? 

* Consider all the subarrays starting at a fixed index `i`. How many different values can it contribute? Well, by the property of `or`, we know that once an unset bit is set in the number, it is impossible to unset it again simply by taking `or` with other numbers. So, `a[i]` can contain atmost 32 unset bits, and it would get atmost 32 chances to set them. Once they are set, we cannot alter them. Hence, we can have only 32 different answers for all the subarrays starting at the index `i`. The same can be argued for all the subarrays ending at `i`. Hence, the total distinct answers can be **32N**.

* Okay, but how do we calculate all the answers efficiently? Well, we can define a `dp` state, where `dp[i]` represents a set which contains all the distinct bitwise `or` of subarrays **ending** at `i`. (Of course, `dp[i].size < 32`). The transition is easy. `dp[i] = a[i] union (a[i] | dp[i-1])`.

* Notice that we can fill the DP table in a bottom up fashion, spending **O(32)** at each node. Finally, we can combine all the `dp[i]` sets into a single set and extract its size. The total complexity is **O(32N)**. **Brilliant**.

* The time limit is too strict. Use `unordered_set` instead of `set`.

### Credits
[Leetcode's Discuss](https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165933/Python-Dynamic-programming-solution-with-indepth-explanation-of-intuition.) : An in depth explanation of the reasoning.
