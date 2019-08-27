## Description
The parity of a number is 1 if the number of set bits is 1, else it is zero.

## BruteForce
We can use the function **CountSetBits** to get the number of set bits. We can then return the result modulo 2.    
The complextiy is O(number_of_bits).


## Bit Magic
* **How do we unset the lowest set bit of a positive number**?   
  * Observe that `num & (num-1)` sets the lowest set bit to zero, while retaining everthing else.   
  * Ensure that this formula is only applied to positive (not zero) numbers.   
  
* **Algorithm**
  * As long as the number is not zero, repeat
    * Unset the lowest set bit.
    * Increase parity in each iteration.
  * Return (Parity % 2)


## Increments in Modular Arithemtic
* We see that we only need `parity % 2` in our final results. 
* This means that we do not need to calulate the entire value, just compute modulo at each step.
* One way is `parity = (parity + 1) & 1` (while incrementing parity).
* Another beautiful approach is `parity = parity xor 1` (whenever we want to increment a variable mod 2.
* If the number is 0, `0^1` is 1. Hence, the number is incremented.  
* If the number is 1, `1^1` is 0. Hence, the number is incremented.


## More on unsetting the lowest set bit
* How do we increment a binary number by one? 
  * We find the lowest unset bit. We set it to one and set everything to the right of it as zero.
  * `...011111` is converted to `...100000`
  
* How do we decrement a binary number by one?
  * We find the lowest set bit. We set it to zero and set everything to the right of it as one.
  * `...100000` is converted to `...011111`
  
* What happens when we compute `x & (x-1)`.
  * Everything till the dots remain same.
  * Concentrate on the lowest set bit. Toward the right of it, every zero is converted to 1. Hence, bitwise `and` retains zero.
  * Moreover, the lowest set bit is also flipped. Hence, bitwise `and` fills zero in that place.
  
* The net result is `x & (x-1)` unsets the lowest set bit.


## Time Complexity
* O(number_of_set_bits)
