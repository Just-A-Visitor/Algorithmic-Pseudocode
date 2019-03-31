[Blog](https://leetcode.com/problems/complement-of-base-10-integer/discuss/256734/Detailed-Explanation-using-XOR-C%2B%2BJavaScript)

**Claim** ------ The *XOR* operation evaluates the difference in the individual bits, i.e it gives information about whether the bits are identical or not.
**Proof** ------ It's easy once you know the definition of *XOR*. `0^0` = `1^1` = `0` (as the bits don't differ), whereas `0^1` = `1^0` = `1` (as the bits are different).

**Claim** ------- *XOR* of identical numbers is zero.
**Proof** ------- As argued above, the bits of identical numbers do not differ at any position. Hence, *XOR* is zero.

**Claim** ------- `0` *XOR* any number is the number itself.
**Proof** ------- *XOR* gives us the bit difference. Since all the bits in `0` are unset, therefore the difference in bits is the number itself.

**Claim** -------- *XOR* of a number with its complement results in a number with all set bits.
**Proof** --------  This is trivial, since bits of a number and its complement differ at every position(according to the definition of complement).

So,  `number` ^ `complement` = `all_set_bits`   ==>  `number` ^ `number` ^ `complement` = `number` ^ `all_set_bits` ===> `0` ^ `complement` = `number` ^ `all_set_bits`

So, `complement` = `number` ^ `all_set_bits`.

So, we find out the number containing all the set bits and *XOR* with the original number to get the answer.


**Miscellaneous**
* Remember to handle zero's complement is 1.
