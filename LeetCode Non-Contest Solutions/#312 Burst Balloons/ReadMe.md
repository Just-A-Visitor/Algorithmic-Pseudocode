### Review
* One of the best questions that I've encountered on DP so far. The DP definition is so tricky, yet when you see it, you cannot  unsee it. Simple, yet elegant. I was skimming throught the top voted solutions, still unable to grasp the logic. Then I       stubled upon [this](https://leetcode.com/problems/burst-balloons/discuss/76228/Share-some-analysis-and-explanations/167308)     top voted comment in the top voted solution and things became crystal clear. I implemented the recursive solution using         memoization and it passed in the first try. (Not even a single compilation error, WOW!).

* This question made me realize the power of memoization. I always preferred iterative DP. However, recursive DP was the first thing that came to my mind for this queston.


### Editorial
* The most tricky part of this question is getting the DP definition correct. At first glance, it looks like we should choose which balloon to burst first and then recursively calculate the remaining answer by varying this choice over all the balloons present initially. We could use memoization if we are not sure about the DP states. However, here lies the problem. As soon as you burst the first balloon, the neighbours become adjacent. This leads to the creation of a new array which can't be simply defined by 2 boundaries in the original array. Hence, this approach won't work. The time complexity of this approach is `T(n) = n*T(n-1)` which is clearly `O(n!)`. 
* I was still unable to come up with an alternate  DP definition. Here's what I gathered from the top solution on `Discuss`.
* `dp[left][right]` denotes the maximum amount that you can collect by bursting **all** the balloons in that range **except** `left` and `right`. This means that endpoints are exclusive (This is the crux of the algorithm). Now, let's change our perception a bit. Let's focus on the last balloon which would be bursted instead of the first. Suppose such a balloon is indexed `k`, where `left < k < right`. This means that all the balloons betweeen in the range `(left, k)` and `(right, k)` were bursted without touching the `k-th` element. Hence, by definition, the profit is `dp[left][k] + dp[k][right] + a[left]*a[k]*a[right]`. Clearly, we need to maximize this value by varying this for all `k` in the given range.
* There you have it. Simple and sweet. Now, each state is described by only 2 parameters, leading to `O(n^2)` states. Inside a function call, we vary `k` linearly. So, after using memoization, the overall complexity becomes **O(N^3)** which is a huge improvement over the `n!`.
* Since we need to burst the entire balloons, we can just append two sentinels at the front and back with the value 1 to ensure the smooth DP defintion.
* I still haven't figured out how to write it iteratively, but that's for another day. This itself would take some time to settle in.

### To Do 
* Implement iterative DP
