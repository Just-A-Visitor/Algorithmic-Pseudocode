The traditional approach is to get the bit representation and count the number of set bits.

### Bit Magic Approach
* Realize that `n % 2` is same as `n & 1`.
  * We know that `0 & x` is `0`. Also `1 & x` is `x`. 
  * So, `x & 1` can either be 0 or 1. In short `x & 1` gives us the last bit of x.
  * The remainder modulo 2 is the last bit of x.
  
  * Realize that `n / 2` is same as `n >>= 2`.
    * Dividing by 2 cuts off the last bit, Hence, it right shifts the bits of 2 by amount 1.
    
    
 # Take Aways
 1) `n % 2` = `n & 1`
 2) `n / 2` = `n >> 1`
