# Min_Max Approach
    This solution works if atleast 1 positive element is present in the array

* The idea is to maintain 2 counters, `max_ending_here`, and `min_ending_here` to record the maximum and minimum possible running product. We are also considering the signs and not just the magnitude. We assume that the final answer is atleast 1, and hence the requirement that atleast 1 positive element be present.
* Intialize both the variables to 1 and iterate the entire array
* If you encounter a positive element
   * `max_ending_here` can be extended forward, regardless of whether it is 1 or a positive number. Hence, multiply `a[i]` to `max_ending_here`.
   * `min_ending_here` can also be extended forward (to make even smaller value considering signs). However, if `min_ending_here` is 1, there's no point in making it positive. So, update `min_ending_here` to `min_ending_here*a[i]` and if the result goes above 1, set it to 1. 

* If you encounter zero
    * The running product cannot be continued further. Reset both the counters to 1.

* If you encounter a negative element
    * The basic idea is : The absolute value of `max_ending_here` and `min_ending_here` would be swapped.
    * First, make a copy of `max_ending_here` in a variable `temp`. 
    * Update `max_ending_here` to `min_ending_here*a[i]`. However, the result can be negative as well (if `min_ending_here` is 1). Remember to take the maximum with 1.
    * Update `min_ending_here` to `max_ending_here*a[i]`. Even if `max_ending_here` is 1, the answer is valid. Use the `temp` variable for the old value of `max_ending_here`.

* Remember to update the `max_so_far` in each iteration.

[Credits](https://www.geeksforgeeks.org/maximum-product-subarray/)

# Count of Negatives (Incomplete)

* This was the initial thought that crossed my mind. If the count of negative elements is even, it's clear that the entire array would be the answer. 
* However, if the count is odd, we have to leave out one terminal element. The terminal element can be from both sides. We iterate the array in both directions, neglecting the first negative element we encounter, and accumulate the product and take the maximum of both.

### Problem

* While thinking of this approach, I did not take into account the fact that there can be zeros in the array as well. This **completely** messes up my analysis. Let's see if anyone has extended this approach forward.


# Optimized Min_Max

    This solution works for all inputs.

The basic problem in the initial Min_Max approach was the fact that `min_ending_here` and `max_ending_here` were always initialised/reset to 1. If the actual answer was less than, we could've never gotten the true result.

Come to think of it, it's not entirely correct. Consider the array `-1 -2`. In both the iterations, `max_ending_here` is 1, whereas in reality, the maximum value ending at the first position should be -1 instead of 1. This is the same issue which occurred during **Kadane's Algorihtm** if we initialised the sum as 0 instead of `a[0]`.
The approach can be corrected by setting the true initial/reset value. Let use define `min_ending_here` as the minimum product that **ends** at that position. Ending at that position is a strict condition, even if it becomes positive. Similarly, we can define our `max_ending_here`.

    This algorithm mimicks Kadane's Algorithm

* Intialize `max_ending_here`, `min_ending_here`, `max_so_far` as `a[0]`.

* For the remaining n-1 elements

    * If the element is positive, we know that it would make `max_ending_here` more positive and `min_ending_here` more negative. However, `max_ending_here` can already be negative, Hence we need to update `max_ending_here` as `max(a[i], max_ending_here*a[i])`. Similarly, we need to update `min_ending_here` as `min(a[i], min_ending_here*a[i])`. This is similar to **Kadane's Algorithm**

    * Even if the current element is 0, the same formula would reset both to zero (which is correct).

    * If the element is negative, we just swap `max_ending_here` and `min_ending_here`. This is because, upon multiplying a negative number, the largest number becomes the smallest and vice versa. Upon swapping, the first formula would work as it is.

    * In a nutshell, if element is negative, perform the swap. Then update 
        * `max_ending_here` as `max(a[i], max_ending_here*a[i])`
        * `min_ending_here` as `min(a[i], min_ending_here*a[i])`

* Keep updating the global results in each iterations.

Notice that this takes care of everthing, be it all negatives, or presence of zeroes. [The counter is reset at the first number after zero]

### Credits   

This amazing idea was borrowed from [here](https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity).   
I'm still amazed at how simple the solution is, yet I couldn't come up with this approach. (Even after reading the GFG approach). Hats off to the poster. One of the best solutions I've seen in a while.
