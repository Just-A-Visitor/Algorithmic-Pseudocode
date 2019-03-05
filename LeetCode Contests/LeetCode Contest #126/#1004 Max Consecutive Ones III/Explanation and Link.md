Intuition
* Let the total number of zeroes be countZeroes.

Case 1 k is greater than or equal to countZeroes

* In this case, we apply the greedy approach, and convert all the zeroes to ones, eventually converting the entire array to 1s, (Why is this the best choice?), Because if we indeed left out any zero, we can still improve upon the count of ones by converting it to 1, becuase it is permissible.

Case 2 k is less than countZeros

* Claim We should convert k consecutive zeroes to ones.
* Proof Suppose we do not convert k consecutive zeroes to ones. This implies that in an optimal selection, there would be at least 2         disjoint clusters , separated by atleast one zero. These clusters can convert all of its zeroes to ones. Now, since we are only allowed   to  take contigous subarray, we can only take the best possible outcome of the two, WLOG, say cluster 1 gives you a larger number of       ones  (after all operations). Now, is this really optimal? Clearly no, since we can always improve by converting the zeroes to ones       which  separates the 2 clusters instead of wasting the move on the 2nd cluster. Hence, we have a contradiction. Therefore, in the         optimal      strategy, we need to convert k consecutive zeroes to ones.
 windowSize We define the window size as the number of zeroes contained in that window

* Clearly we need to find the window which contains the maximum number of ones and has size atmost k. We can then convert all the zeroes     in the window to get an amount equal to windowSize+ amountOfPreviousOnes.

 Algorithm

* Create a deque to hold the array elements (values). Create variables to store the count of zeroes, count of ones, and the best answer so far.
* Iterate over each element of the array. If the element is one, just push it in the back(as it cannot contribute to window size) and update the count. If the element is zero, update the window size and then push it to the back.
* If the length of the window exceeds k, start contracting the window from the front. Since 1's did not contribute to the size, keep popping them till you see a zero. As soon as you see a zero, pop it and the window size decreases by 1.
* Update the maxPossibleResult so far in each iteration. All elements in the current window can be converted to 1.

Miscellaneous

* Updation of the result should be dones after confirming that the window size does not exceed k.
* The return type of dq.size() is size_t and hence, we need to typecast it before calling max.
Time Complexity

* O(n)

Link

https://leetcode.com/problems/max-consecutive-ones-iii/discuss/249472/detailed-explanation-without-any-messy-indices-on
