[Blog](https://leetcode.com/problems/best-sightseeing-pair/discuss/261067/detailed-explanation-using-dp-on-time-o1-space)


**Intuition**
* Suppose we choose the site `[i,...j]`. The score can be broken up into 2 parts.
* The first part is the **startGain** which you gain while starting at a certain point `i`. Notice that `startGain[i] = a[i] + i`.
* The second part is the **endGain** which is the amount you gain while ending at a certain point `j`. Notice that `endGain[i] = a[j] - j`.
* Notice that endGain can be negative
* The overall gain for `[i,...j]` is nothing but `startGain[i] + endGain[j]`. (This can be easily verified by the definitions).
---
**Constraints**
* You cannot start at the last position
* You cannot go left at any stage, i.e if you started at `i`, you have to end your trip at a number **strictly** bigger than `i`.
---
**Reduction**
* We need to maximize the overall Gain.
---

* What are the possible positions for starting the trip? Clearly we can start at all except the last element. So, the optimal trip has to start at one of these elements.
* Suppose, we are only allowed to start a trip at `i`. What is the maximum amount we can gain in this case? Well, since the `startGain` is fixed, we need to maximize the
`endGain`. We can do it by stopping at an element which has the maximum `endGain` with the condition that it appears to the right of `i`.
---
**Setting up the DP definition**
* As discussed above, for each i, we need to find the maximum `endGain` to the right of it. 
* `maxEndRight[i] = max(maxEndRight[i+1], endGain[i+1])` = `max(maxEndRight[i+1], a[i+1] - (i+1))`
* `maxEndRight[i]` represent the highest `endGain` that you can get while stopping at any point **strictly** to the right of `i`. Since by definition, we already know `endGain[i+1]` (the highest gain possible by ending at any point to the right of `i+1`) we only need to check the possibility whether stopping at `i+1` would be beneficial or not. Hence, the DP definition.
* For each valid `i`, `overallGain[i] = startGain[i] + maxEndRight[i]` = `a[i] + i + maxEndRight[i]`
---
**Reducing the Space complexity**
* Notice that `maxEndRight[i]` only depends on `maxEndRight[i+1]`. Hence, we can use 2 variables to track the previous values.
---
**Miscellaneous**
* Since we need the value of `maxEndRight[i+1]` to compute the value of `maxEndRight[i]`, therefore we start the iterations at the back.
* As argued, trips cannot start at the last element, hence the `for` loop starts at `i=n-2`. For this value, `maxEndingRight` is initialized to `endGain[lastIndex]` because this is the only possible way to end the trip.
