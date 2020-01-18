### Review
* The approach is simple. The first 4 cases would be the base case. Now, suppose `n > 4`. Let us observe the first block that we insert. If we decide to insert it vertically, we are interested in the number of ways of inserting the remaining blocks to the right of it according to the rules of the game.
* On the other hand, if we decide to place it horizontally, we would have to supply 3 more blocks to fill the gap. With the remaining `n-4` blocks, we are interested in the number of ways of arranging them. 
* The total ways would be the sum of them.
* After that, it is just standard Sieve Implementation. (Implement Sieve properly, don't run the outer loop from `1`).
