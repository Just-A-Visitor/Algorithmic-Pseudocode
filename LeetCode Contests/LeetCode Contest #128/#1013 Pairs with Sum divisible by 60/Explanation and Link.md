[Blog](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/256782/Detailed-Explanation-using-Modular-Arithmetic-C%2B%2BJavaScript-O(n))

**Intuition**
* The problem can be reduced to modular arithmetic by doing every operation `mod 60`. Since every number divisible by 60 becomes `0` in the modular arithemtic of 60, the equivalent characterization of the problem is, **How many pairs sum upto 0 (in modular arithmetic of 60)**.
* Notice that there are only 60 different numbers in the modular arithmetic. i.e `[0,1,2,...59]`.
* We traverse the array and update the count of each of the 60 numbers. (How?). Any number `num` contributes to `num%60` in the modular version. So we increase the count of `num%60` each time we encounter an element.
* Now that we only have numbers from `0...59`, let us see which numbers can sum up to zero.
* Clearly each `0` can be paired with another zero to sum up to zero. How many such pairs are there? Suppose the count of zeros is `n`. Then selecting any 2 elements out of this would result in an answer. How many ways are there to select? Clearly, `nC2` = `n*(n-1)/2`.
* Similarly, `30` can be paired with `30` to give `0` (since `30+30` equals to `0` mod `60`). How many pairs can we form from 30? As argued above, `nC2` = `n*(n-1)/2`, where `n` is the frequency of `30` in the map.
* Now, for the remaining elements, how many ways are there to sum upto `0`? Let's pick a number `a`. The complement of this number is `b` = `60-a`. Suppose the frequency of `a` is `m` and the frequency of `b` is `n`. Now, picking any one `a` and any one `b` would sum upto 0. How many ways are possible to pick one element from each set ? Clearly `m*n`.
* Care has to be taken to avoid recounting the pairs `(a,b)` and `(b,a)`

**Algorithm**
* After updating the count of each of the 60 numbers in the map, we traverse the numbers `[1,2,3...29]`. For each element `a` we find the frequency of `a` and the frequency of its complement and increment the answer by their product.
* As discussed above, we deal with `0` and `30` separately as they are their own complements.

**Miscellaneous**
* We only loop upto 29 so as to avoid recounting. (Beacause every number greater than 30 has a complement less than 30, which has already been counted in the `for` loop). 

