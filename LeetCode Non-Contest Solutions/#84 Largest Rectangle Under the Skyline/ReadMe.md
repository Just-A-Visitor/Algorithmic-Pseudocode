# Sub-Problem
Perhaps it's better to start with a simpler version of this question. Forget about finding the largest area in the entire histogram. 
The modified question is, **Given any index `i`, return the area of the largest rectangle (completely including the i-th bar)**.

# Solving the Sub-Problem
* We know that we have to include the i-th bar completely. Our goal should be to extend the rectangle to the left and right as much as possible.
* How far can we go to the right? If the rightmost elements have height **greater than or equal to** the height of the i-th bar, we can just include them in our journey.
* Once we encounter an element with height less than i-th bar's height, we have to stop our search. Why? Simply because we'll fall off when walking on the straight line from i-th bar. (Remember, the constraint was to include the i-th bar completely, no matter what).
* Similarly, we keep going left untill we find an element with smaller height.
* We know that the height of the resultant rectangle would be `a[i]` (Simply because we were just extending the rectangle). 
* Each bar encountered during our journey would contribute 1 to the width (including the i-th bar)
* The final result = `a[i] * (number_of_bar_met_on_left + 1 + number_of_bar_met_on_right)`


# The Main Problem
* Now that we have solved the sub-problem, let us solve the original problem. 
* A crucial observation ==> **In the optimal solution , atleast one bar will be included completely** (Prove it)
* We know the answer when each bar is included completely, just take the maximum value of them all.

# Pseudocode
```
for each index in the array
    Get the height of the i-th bar
    Intialize width as 1

    Travel left untill you find a smaller element
        Keep incrementing width
    
    Travel right untill you find a smaller element
        Keep incrementing width
    
    Update the Value for this index in the dp array

Return the maximum element in the dp array
```

# Time Complexity
The time complexity of this solution is **O(n^2)**

# Reducing the Time Complexity

                            Modified Stock Span Method

* Recall that the stock span of an element is defined as the number of elements to the left which are less than or equal to the current element.
* Let us modify this defintion to **The number of elements to the left which are greater or equal to the current element.**
* In our dp definition, `number_of_bar_met_on_left` is nothing but the stock span of that index (By New Definition)
* To find the `number_of_bar_met_on_right`, we can just reverse the array, find the stock span of each element and reverse it back. 
* After we've done this, for each index, we'd have the number of elements to the left and right which are greater/equal to the current element.
* By definition, the current element would be included in both the segments.
* The overall result, `dp[i] = height * (leftSpan[i] + rightSpan[i] - 1)` (to avoid the repetition of current element).

I know that this was an overkill, but that was the idea that first striked my mind and hence I decided to check it anyway. As you can see, the implementation is a bit dirty.


                                The Clean Approach
# Intuition

* **Blocking**
    * Suppose we have 2 buildings **A | B**. We say that building `B` blocks building `A` if we would fall off from building `A` while going towards building `B`. Essentially, `B` blocks `A` if height of `B` is less than or equal to `A`. (More on the equality part later)

* **Invariant**
    * In the stack, we will maintain an invariant that any building `i` would not block any building to the left of it. Essentially, all the buildings in the stack would be in increasing order of heights.

* **Right Span**
    * Suppose we keep getting buildings in increasing order of heights. At a certain point of time, we meet a building which blocks the building at the top of stack. Naturally we would have to pop it from the stack (due to the invaraint). However, we can also infer that since the current building has popped the top element, the right span of the top element would terminate at the current position (excluding it).
    * **Conclusion** ==> Whenever a building `current` pops a building `top` from the stack, the right span of `top` would terminate at current. In this way, we would know the right span of each element (when it is popped).
* **Left Span**
    * How do we find out the left span? 
    * We know that no building blocks any buiding to the left. All the elements which are a part of the left span of current would be blocked by current.
    * Therefore, every element in the left span would be popped before current enters.
    * When the stack becomes stable, the element to the left of current would decide the left span (excluding it).



## Finding the exact width 
* Let the current index be `i`, top of the stack is `top`. 
* We notice that `a[i] < a[top]`, i.e current building blocks the top building. What is the area of  the largest rectangle containing `top` building?
* Clearly, the height is `a[top]`.
* We know that `i-th` element is popping it from the stack. Hence right boundary ends at `i` (excluding it).
* We pop the stack.
    * If the stack becomes empty
        * it means everything to the left was part of left span. Therefore, we need the number of elements between `[0,i)`.
        * Clearly, it is `(i-0+1) - 1`
        * Therefore, `width = i`
    * Else
        * The left boundary ends at the current top element. (excluding it).
        * The number of elements between `(current_top, i) = (i - current_top + 1) - 2`
        * Therefore `width = i - current_top - 1`

## Handling Corner Cases
* As we've seen, whenever an element is popped, the `dp` value of that building is computed correctly. However at the end, not all the elements would be popped (think strictly increasing or decreasing sequences). To overcome this, we append an element with height 0 at the end of the array. Naturally it blocks all the elements and will pop them. Of course, it won't be popped , but who cares. Smart move, isn't it. It's called **Sentinel Subguarding**.
* If you are given an immutable array, just pretend that there exists an extra element at the end without really adding it.

## Dealing with Duplicates
* So far we haven't considered the case of duplicates. Do one duplicate building block the other?
* Naturally we have to remove one duplicate if they are side by side. This is to maintain the invariant that the left span boundary is the previous element in the stack. For this we would have to assume that one duplicate blocks the other
* Which one should we remove? The previous one or the new one?
* If we neglect the previous one, the left span of the incoming distinct element would be incorrect (as the new duplicate would be the one blocking it).
* Therefore, we place duplicates in the regular blocking category and everything is solved.

# Pseudocode
```cpp
Push the sentinel at the back
Initialize maxArea as 0

For each index, do
    While stack exists and current index blocks the top element, do
        Extract the height of the top element
        pop the stack
        get the width
        update maxArea

    Push current element on the stack
```

I know this was a very long explanation, but it's definitely worth it for the beauty of the question.

# Credits
* [EPI]() for the awesome explanation of the last Approach.
* This [link](https://anandabhisheksingh.me/stock-span-problem/) for the code of normal stock span
