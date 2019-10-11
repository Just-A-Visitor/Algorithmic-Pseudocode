[Blog](https://leetcode.com/problems/binary-prefix-divisible-by-5/discuss/265601/Detailed-Explanation-using-Modular-Arithmetic-O(n))
[Alternate Solution](https://leetcode.com/problems/binary-prefix-divisible-by-5/discuss/265636/C-divisible-by-5-is-determined-by-right-most-digit-only)

**Intuition**
* First, let us see how to append an extra bit at the end of a binary number
* Any binary number **a<sub>k</sub>a<sub>k-1</sub>...a<sub>0</sub>**  has the form a<sub>0</sub>*2<sup>0</sup> + a<sub>1</sub>*2<sup>1</sup> + ........ a<sub>0</sub>*2<sup>k</sup>


* To free up an extra slot at the end, we can just multiply the original number by 2.
* Initially, the contribution of each **a<sub>i</sub>** is 2<sup>i</sup>. If the number is multiplied by 2, the contribution of each a<sup>i</sup> become 2<sup>i+1</sup>.
* The resulting number is 0*2<sup>0</sup> + a<sub>0</sub>*2<sup>1</sup> + a<sub>1</sub>*2<sup>2</sup> + ........ a<sub>0</sub>*2<sup>k+1</sup>
* Consider the number **a<sub>k</sub>a<sub>k-1</sub>...a<sub>0</sub>0**. As per the above definition, it is clear that the resulting number is just the decimal representation of this number
----

* We've seen how to append an extra bit at the end of a binary number. 
* The extra bit appended by the above method is unset (0).
* How do we append a set bit? Well, we can just free up a slot at the end (by appending 0) and then add 1 to the resulting number.
* Since the current rightmost bit is zero, therefore there won't be any carry-effects. Hence the new number would be **a<sub>k</sub>a<sub>k-1</sub>...a<sub>0</sub>1**
---
**Conclusion**
* For appending a digit **d** at the end of a binary number **old_number** = **a<sub>k</sub>a<sub>k-1</sub>...a<sub>0</sub>**, we can just do **new_number** = old_number*2 + **d**. 
* This gives us the number with binary representation  **a<sub>k</sub>a<sub>k-1</sub>...a<sub>0</sub>d**
---
**Modular Arithemtic**
* A number is divisible by 5 **iff** the number is equivalent to **0** in the modular arithemtic of 5.
---
**Naive_Algorithm**
* Since we know how to append any digit at the end, we start with 0 and keep appending digits. We can get all the numbers in this manner.
* At each step we can take the modulo with respect to 5. If the modulo is zero, we append **true** to our answer.
---
**Problems**
* The problem with the above approach is that the number can overflow easily. (As the largest integer that can be accomodated is of 31 bits in C++).
---
**Optimizations**
* Observe that we only care about the remainder, not the actual number.
* Use the fact that (a*b + c)%d is same as ((a%d)*(b%d) + c%d)%d.
* We now have the relation **new_number**%5 = ((old_number%5)*2 + d)%5;
*  This tells us the if we provide the modulo of the old_number instead of the original number, we'll get the modulo of the new number.
* This would prevent overflows, since **new_number** is the equivalent representation of the original number in the modular arithemtic of 5.
---
**Optimized Algorithm**
* Start with **num**=0.
* For each valid **i** update **num** as **num** = (num*2 + a[i])%5
* At each stage, if **num** is zero, the substring ending at **i** is divisible by 5.
---
**Time Complexity**
* We pass each element exactly once. Hence *O(n)*.
