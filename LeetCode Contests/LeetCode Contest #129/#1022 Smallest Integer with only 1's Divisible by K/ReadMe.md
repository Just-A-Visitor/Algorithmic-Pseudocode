[Blog](https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260936/detailed-explanation-using-modular-arithmetic)

**Modular Arithmetic**
* First, let us see how to compute powers of 10 modulo `m`, where `m` is any given number.
---
* Use the fact that `a*b % m = ( a%m * b%m ) % m`
* 10<sup>n</sup> = 10<sup>n-1</sup> * 10. This implies that 10<sup>n</sup> % m = ( 10<sup>n-1</sup>%m * 10%m )%m.
---
**Conclusion**
* If we denote the remainder of 10<sup>n-1</sup> as `prevRem`, then the remainder of 10<sup>n</sup> is nothing but `(prevRem * 10%m )%m`
In this manner, we can calculate all powers of 10 in the modular arithmetic of `m`.
---
**Intuition**
* Recall that a number with digits `abc` can be represented as `100a + 10b + c`.
*  Similarly, a number with digits `abcdef` can be represented as `10000a + 1000b + 100c + 10d + e`. 
* This leads us to the fact that a number containing only the digit 1 can be represented as 1 + 10 + 100 + 1000 + ...  10<sup>maxPower</sup>
* What would the length of such a number be? As can be clearly observed, `1` = 10<sup>0</sup>, `11` = 1 + 10<sup>1</sup>, 
  `111` = 1 + 10<sup>1</sup> + 10<sup>2</sup>, `1111` = 1 + 10<sup>1</sup> + 10<sup>2</sup> + 10<sup>3</sup>.
  Therefore, for a general setting, the length is `maxPower + 1`.
---
**Computing 1111.....111 modulo `m`**
* As we've seen above 111...11 = 1 + 10 + 100 + 1000 + ...  10<sup>maxPower</sup>.
* Use the fact that `(a + b)%m = (a%m + b%m) %m `
* Therefore, in the modular arithemtic, the number 111...11 can be derived by taking the modulo of powers of 10 (by the previous technique) and then summing it up by the above rule.
---

So far, we have seen how to generate the powers of 10 modulo `m` and how to determine the length of the number in the particular representation.
Using the above technique, we can generate all the numbers which contain only the digits 1 in the modular arithemetic of `m`. Now, since the desired number
is divisible by `m`, therefore we need to see if we can generate `0` in the modular arithmetic of `m`.
---
---

**Algorithm**
* If `k` is a multiple of `2` or `5`, the answer would be `-1`, since the remainder can never be zero. (Why?). This happens because every multiple of a number
 which is multiple of 2 or 5 is divisible by 2 or 5, hence they can't end in a stream of ones.
 * Initialize `prevRem` to 1. Start the iterations. In each iteration, generate 10<sup>power</sup> in the modular arithmetic and accumulate the sum (also in modular arithemetic) and check if you've reached zero or not.
 * Use the previously derived formula to obtain the next remainder and add it to the sum. If the sum becomes `0`, we have found the answer.
 * As soon as sum becomes zero, determine the length of the number (as described above) and return the length.
 
 ---
 **Upper Bound**
 * The upper bound on the length can be derived in an elegant manner using Pigeon hole principle. Refer to this [post](https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260916/proof-we-only-need-to-consider-the-first-k-candidates-in-1-11-111-1111/253036)
---
