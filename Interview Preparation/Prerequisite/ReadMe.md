# Foreword
* This list contains around 60 questions. Try to solve each question without looking at the solution. 
* Every question is a collapsible link. Upon expanding it, you can find the link to the online judge where you can submit it. I've also included the links to the solution, editorial (and hints at times).
* Try to solve each question using the paradigms of C++. It is but natural that you get stuck during the initial phase of problem solving. So, should you get stuck, don't hesitate to ask your doubts on Slack/Mail. In the meanwhile, move on to the next question. (The topics need not be attempted linearly).
* To study DP, you can go through the DP chapter from CLRS.
* However, a better alternative would be to lookup online videos for each problem. Some good channels are **BackToBackSWE**, **Tushar Roy** and **Abdul Bari**. 
* Once you've solved a particular question, go through all the top voted solutions on **Leetcode's Discuss**. This is the most crucial part of problem solving. Not only should you know the solution, but also various approaches for the same problem.
* If you feel confident enough, try participating in **Leetcode's Weekly and BiWeekly** Contests. This would give you a rough understanding of your current level of preparation.
* If and when you manage to complete this list, let me know and I'll update the next set of questions.

<br></br>

### Phase  : Linked List

<details>
	<summary>Reverse a Linked List</summary>

* [Question Link](https://leetcode.com/problems/reverse-linked-list/)   
* First try to solve the recursive version, then attempt the iterative version.   
* Make sure that the time complexity of the recursive version is **O(n)** rather than **O(n^2)**. This is very crucial
* [Analysis](https://leetcode.com/problems/reverse-linked-list/discuss/254618/C%2B%2BJavaScript-Detailed-Explanation-Recursive-and-Iterative)   

</details>


<details>
	<summary>Intersection of 2 Linked List</summary>

* [Question Link](https://leetcode.com/problems/intersection-of-two-linked-lists/)   
* One approach is to calculate the length, and then traverse the bigger list until the lengths becomes equal. Then traverse them parallelly until you find the intersection point.   
* The other solution uses a HashMap. (Should you hash pointers or the data?)   
* [Length Based Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23160%20Intersection%20of%202%20Linked%20Lists/Difference%20in%20Length%20Approach.cpp) 
* [HashMap Based Solution](
  https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23160%20Intersection%20of%202%20Linked%20Lists/Hashing%20Based%20Approach.cpp)
* [Analysis 1](https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!) (Tricky)   
* [Analysis 2](https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49800/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination) (Detailed)   

</details> 


<details>
    <summary>Loop Detection in Linked List</summary>

* [Question Link](https://leetcode.com/problems/linked-list-cycle/)
* One approach is to use **Slow and Fast Pointers**
* The second approach is to use **Hashing** (Should you Hash Pointers or Data?)
* [Slow and Fast Pointers Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23141%20Loop%20Detection%20in%20Linked%20List/Walker%20%26%20Runner%20Approach.cpp)
* Try to code the Hashing based approach by yourself. (It's very trivial)
* There's a more elegant approach to this question (which destroys the original list). It uses the concept of iterative reversal of a linked list. Can you come up with that approach.
* [Iterative Reversal Approach](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23141%20Loop%20Detection%20in%20Linked%20List/Reversal%20Approach.cpp)

</details>   


<details>
	<summary>Merge 2 Sorted Linked Lists</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1)  
* Start out with the recursive approach and build the iterative approach on top of it.
* A great use case of Recursion. The recursive code is very concise.
* Recall that we discussed **Tail Recursion** in one of the lectures. Use the fact that the above recursive code is a Tail Recursion to easily convert it into an iterative procedure.
* [Analysis and Solution](https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/)

</details>


<details>
	<summary>Find Middle Element of Linked List</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1)
* [Analysis and Solution](https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/)

</details>


<details>
	<summary>Reorder a List in a Certain Fashion</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/reorder-list/1)
* An excellent question to test several concepts of Linked Lists. 
* **Hint** :: Find the middle element, split the list, reverse the second half, and then perform alternate merging,
* [Analysis and Solution](https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/)

</details>

<details>
	<summary>Clone a List with Random Pointers (Advanced)</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1)
* [Analysis and Solution 1](https://leetcode.com/problems/copy-list-with-random-pointer/discuss/258935/Detailed-Explanation-with-Pictures-C%2B%2BJavaScript)
* [Analysis and Solution 2](https://leetcode.com/problems/copy-list-with-random-pointer/discuss/259563/Detailed-Explanation-Constant-Space-C%2B%2BJavaScript)  

</details>   

<br></br>

### Phase  : Trees

<details>
	<summary>Level Order Traversal</summary>

* Probably the most import concept in Trees. 
* There are a couple of versions : 
  * **Basic Level Order Traversal**
  * **Level Order Traversal in a Line by Line Fashion** (Using 2 Queues)
  * **Level Order Traversal in a Line by Line Fashion** (Using 1 Queue and 1 Marker)
  * **Level Order Traversal in a Line by Line Fashion** (Using 1 Queue and No Marker

* [Pseudocodes for all 4 Cases](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/tree/master/Pseudocode/Trees/Level%20Order%20Traversal)
* [Question Link 1](https://practice.geeksforgeeks.org/problems/level-order-traversal/1)
* [Analysis 1](https://www.geeksforgeeks.org/level-order-tree-traversal/)
* [Question Link 2](https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1)
* [Analysis 2](https://www.geeksforgeeks.org/print-level-order-traversal-line-line/)

</details>


<details>
	<summary>Connect Nodes at Same Level</summary>

* This is a classic example of how **Recursion** and **Level Order Traversal** are useful.
* **Code**
  * [Recursive Version for Complete Binary Trees](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23116%20Populating%20Next%20Pointers/Firsr%20Draft%20(Complete%20Binary%20Trees).cpp)
  * [Recursive Version for All Kinds of Binary Trees](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23116%20Populating%20Next%20Pointers/First%20Draft%20(All%20Trees).cpp)
  * [Level Order Traversal with Marker for all Binary Trees](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23116%20Populating%20Next%20Pointers/Level%20Order%20Traversal%20(With%20Markers).cpp)
  * [A Bit of Recursion +  A Bit of Iteration - All Trees](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23116%20Populating%20Next%20Pointers/Second%20Draft%20(All%20Trees)%20(Less%20Recursion).cpp)
  * [Iterative O(1) space for all Binary Trees](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23116%20Populating%20Next%20Pointers/O(1)%20Space%20Complexity%20(All%20Trees).cpp)

* [Analysis](https://www.geeksforgeeks.org/connect-nodes-at-same-level/)

</details>


<details>
	<summary>Left and Right View of a Tree</summary>

* [Question Link for Left View](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)   
* [Question Link for Right View](https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1)
* [Analysis for Left View](https://www.geeksforgeeks.org/print-left-view-binary-tree/)
* [Analysis for Right View](https://www.geeksforgeeks.org/print-right-view-binary-tree-2/)

</details>


<details>
	<summary>Vertical Order Traversal</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1)   
* [Pseudocode](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/Pseudocode/Trees/Vertical%20Order%20Traversal/Vertical%20Order%20Traversal.pdf)
* [Analysis and Solution](https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/)

</details>


<details>
	<summary>Top and Bottom View</summary>

* [Question Link for Top View](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)
* [Question Link for Bottom View](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)
* It's trivial if you've already solved **Vertical Order Traversal**. 
* **Hint** : During Vertical Order Traversal, the first element of each level would be visible in the Top View. (Similarly, the last element of each element would be visible in the bottom view).
* [Analysis for Top View](https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/)
* [Analysis for Bottom View](https://www.geeksforgeeks.org/bottom-view-binary-tree/)

</details>


<details>
	<summary>Zig Zag Tree Traversal</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1)   
* A perfect application of Data Structures.
* [Pseudocode](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/Pseudocode/Trees/Zig%20Zag%20Tree%20Traversal/Zig%20Zag%20Traversal.pdf)
* [Analysis](https://www.geeksforgeeks.org/zigzag-tree-traversal/)

</details>


<details>
	<summary>Diameter of Binary Tree</summary>

* [Question Link](https://leetcode.com/problems/diameter-of-binary-tree/)
* A different dimension of Recursion. Ensure that the time complexity is **O(n)**
* [Analysis and Solution]

</details>


<details>
	<summary>Binary Tree to Doubly Linked List</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1)
* A great use case of Recursion
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/GeekForGeeks/Binary%20Tree%20to%20DLL/Modified%20InOrder.cpp)
* [Analysis](https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/)

</details>   

<br></br>

### Phase  : Stacks

<details>
	<summary>Valid Parentheses</summary>

* [Question Link](https://leetcode.com/problems/valid-parentheses/) 
* A classical question which involves the use of stack. Just follow the steps that we discussed. It's simple to code
* [Analysis and Solution](https://leetcode.com/problems/valid-parentheses/discuss/9222/My-0ms-c%2B%2B-solution-using-stack)

</details>


<details>
    	<summary>Longest Valid Parentheses</summary>
*  [Question Link](https://leetcode.com/problems/longest-valid-parentheses/)
* The core concept is the same as **Valid Parentheses**
* [DP Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%2332%20Longest%20Valid%20Parentheses/DP%20Approach.cpp) (Messy)
* [Stack Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%2332%20Longest%20Valid%20Parentheses/Stack%20Based%20Approach.cpp) (Clever but prone to mistakes)
* [Stack Solution and Analysis](https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/) (Concise and Clear)

</details>

<details>
	<summary>Min Stack</summary>
* [Question Link](https://leetcode.com/problems/min-stack/)
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23155%20Stack%20to%20Implement%20getMin/Auxillary%20Stack.cpp)

</details>


<details>
	<summary>Merge Overlapping Intervals</summary>

* [Question Link](https://leetcode.com/problems/merge-intervals/)
* [Solution](https://leetcode.com/problems/merge-intervals/discuss/21242/C%2B%2B-10-line-solution.-easing-understanding)
* This question has a couple of different approaches, including **stacks**, **vectors**, etc. Make sure to go through the top voted solutions on **Discuss** for understanding the various approaches.

</details>


<details>
	<summary>Next Greater Element (with Duplicates)</summary>

* [Question Link](https://leetcode.com/problems/next-greater-element-i/)
* [Solution](https://leetcode.com/problems/next-greater-element-i/discuss/97613/C%2B%2B-stack-%2B-unordered_map)
* **Analysis** --- Go through Top Voted Solutions on Discuss.

</details>


<details>
	<summary>Stock Span</summary>

* [Question Link](https://leetcode.com/problems/online-stock-span/)
* [Analysis and Solution]()https://leetcode.com/problems/online-stock-span/discuss/168366/Simple-C%2B%2B-solution-with-stack-O(n)-with-explanation

</details>


<details>
	<summary>Largest Rectangle under Histogram (Tricky)</summary>

* [Question Link]()
* [Analysis](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/tree/master/LeetCode%20Non-Contest%20Solutions/%2384%20Largest%20Rectangle%20Under%20the%20Skyline)
* [Modified Stock Span Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%2384%20Largest%20Rectangle%20Under%20the%20Skyline/Modified%20Stock%20Span.cpp)
* [Naive DP Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%2384%20Largest%20Rectangle%20Under%20the%20Skyline/Naive_dp.cpp)
* [The Optimal and Clean Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%2384%20Largest%20Rectangle%20Under%20the%20Skyline/Single%20Traversal%20and%201%20Stack.cpp)

</details>


<details>
	<summary>Infix to Postfix Conversion (Advanced)</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/infix-to-postfix/0)
* [Analysis and Solution](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/)

</details>

<br></br>

### Phase  : Queue

<details>
	<summary>First Non Repeating Character in a Stream</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0)   
* [Analysis and Solution](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0)

</details>


<details>
	<summary>Circular Tour of Petrol Pumps</summary>

* [Question Link](https://leetcode.com/problems/gas-station/)
* [Analysis](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/tree/master/LeetCode%20Non-Contest%20Solutions/%23134%20Circular%20Tour%20of%20Petrol%20Pumps)
* [Queue Based Solution with Extra Space](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23134%20Circular%20Tour%20of%20Petrol%20Pumps/Queue%20%5BO(n)%20Space%5D.cpp)
* [Queue Based Solution with Constant Space](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23134%20Circular%20Tour%20of%20Petrol%20Pumps/Queue%20%5BO(1)%20Space%5D.cpp)
* [A Clever Approach using Queues](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23134%20Circular%20Tour%20of%20Petrol%20Pumps/Concatenation%20Approach%20%5BClean%5D.cpp)
* The Discuss Section has pretty good alternatives. Please go through them once.

</details>


<details>
	<summary>Queue using 2 Stacks</summary>

* [Question Link](https://leetcode.com/problems/implement-queue-using-stacks/)
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23232%20Queue%20using%202%20stacks/Amortized%20O(1).cpp)
* [Analysis](https://leetcode.com/problems/implement-queue-using-stacks/discuss/?currentPage=1&orderBy=most_votes&query=)

</details>


<details>
	<summary>LRU Cache (Tricky)</summary>

* [Question Link]()(https://leetcode.com/problems/lru-cache/)
* [List and Map Based Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23146%20LRU%20Cache/List%20and%20Map.cpp)
* [Analysis](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/tree/master/LeetCode%20Non-Contest%20Solutions/%23146%20LRU%20Cache)

</details>

<br></br>

### Phase  : Hashing

<details>
	<summary>All Pairs with Given Sum</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum/0)
* [Analysis and Solution](https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/)

</details>

<br></br>


### Phase  : Heaps

<details>
	<summary>Minimum cost to connect Ropes</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0)   
* [Min Heap Solution](https://ide.geeksforgeeks.org/i0gzdVnMIW)

</details>


<details>
	<summary>Median in a Stream of Integers</summary>

* [Question Link](https://leetcode.com/problems/find-median-from-data-stream/)   
* [Analysis and Pseudocode](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/Pseudocode/Heaps/Median%20in%20a%20Stream%20of%20Integers/Median%20in%20Stream.pdf)
* [Solution](https://leetcode.com/problems/find-median-from-data-stream/discuss/74049/Share-my-java-solution-logn-to-insert-O(1)-to-query)

</details>


<details>
	<summary>Sort a Nearly Sorted Array</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0)   
* [Analysis](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/tree/master/GeekForGeeks/Sort%20A%20Nearly%20Sorted%20Array)
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/GeekForGeeks/Sort%20A%20Nearly%20Sorted%20Array/Heap%20Based%20Approach.cpp)

</details>

<details>
	<summary>Merge K Sorted Arrays</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)   
* [Pseudocode](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/Pseudocode/Heaps/Merge%20K%20Sorted%20Vectors/Merge_K_Sorted.pdf)
* The editorial on GFG implements *MinHeap* from scratch. Don't go that route. Use STL's implementation to solve the question.

</details>

<br></br>


### Phase  : Greedy Algorithms

<details>
	<summary>Minimum Number of Platforms</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/minimum-platforms/0)
* [Solution and Editorial](https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/)

</details>


<details>
	<summary>Activity Selection</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0)
* [Analysis and Solution](https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/)

</details>

<br></br>

### Phase  : 1D Dynamic Programming

<details>
	<summary>House Robber</summary>

* [Question Link](https://leetcode.com/problems/house-robber/)   
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%23198%20House%20Robber/DP%20Approach.cpp)
* **Analysis** ::: Top Voted Solutions on Discuss

</details>


<details>
	<summary>Trapping Rainwater</summary>

* [Question Link](https://practice.geeksforgeeks.org/problem-page.php?pid=281)   
* [Analysis](https://www.geeksforgeeks.org/trapping-rain-water/) (The 2nd solution in the above link is well written)
* [Solution](https://ide.geeksforgeeks.org/ep4EIvmjVO)

</details>


<details>
	<summary>Maximum Sum Subarray</summary>

* [Question Link](https://leetcode.com/problems/maximum-subarray/)
* [Solution and Analysis](https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts) (Extremely Well-written)

</details>


<details>
	<summary>Buying and Selling Stocks (2 Versions)</summary>

* [Version 1](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Solution](https://ide.geeksforgeeks.org/HQHWbSFpoE)
* **Analysis** ::: The Top Voted Solution with the heading **Kadane's Algorithm**. (Due to markdown issues, I'm unable to link it).

</details>


<details>
	<summary>Minimum Length Subarray sorting which sorts entire array</summary>

* [Question Link](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)
* [Solution](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/231437/C%2B%2B-Well-Commented-Solution-(Using-DP)-100)

</details>


<details>
	<summary>Longest Increasing Subsequence</summary>

* [Question Link](https://leetcode.com/problems/longest-increasing-subsequence/)  
* [Solution and Analysis](https://leetcode.com/problems/longest-increasing-subsequence/discuss/74836/My-easy-to-understand-O(n2)-solution-using-DP-with-video-explanation)
* There's also an **O( n log(n))** solution, but don't worry about it for the time being.

</details>

<br></br>

### Phase  : 2D Dynamic Programming

<details>
	<summary>Longest Common Subsequence</summary>

* [Question Link](https://leetcode.com/problems/longest-common-subsequence/)  
* [Solution](https://ide.geeksforgeeks.org/ff02b5aH5V) (Probably Outdated)
* [Analysis](https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)) (The guy's a genius)
* You can go through some Youtube videos for each question on 2D DP. The famous ones are **Tushar Roy** and **BackToBackSWE**

</details>


<details>
	<summary>Longest Palindromic Subsequence</summary>

* [Question Link](https://leetcode.com/problems/longest-palindromic-subsequence/)  
* [Solution](https://ide.geeksforgeeks.org/wLTGB8APLn)
* [Analysis](https://leetcode.com/problems/longest-palindromic-subsequence/discuss/222605/DP-Problem-Classifications-Helpful-Notes) (Good Writeup and Pattern Detection)

</details>


<details>
	<summary>Longest Palindromic Substring</summary>

* [Question Link](https://leetcode.com/problems/longest-palindromic-substring/)  
* [Solution](https://ide.geeksforgeeks.org/yKCMbixsGV)
* **Analysis** ::: Youtube

</details>


<details>
	<summary>Knapsack</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0)  
* [Analysis and Solution](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

</details>


<details>
	<summary>Subset Sum</summary>

* [Question Link](https://leetcode.com/problems/partition-equal-subset-sum/)  
* The above link isn't exactly subset sum, but the 2nd variation that we discussed, namely **Equal Partition**
* [The original Subset Sum](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)
* [Analysis and Solution](https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation)

</details>


<details>
	<summary>Coin Change</summary>

* [Question Link](https://leetcode.com/problems/coin-change/)  
* Realize how and why **Greedy** doesn't work for this question. Come up with counter examples for the same.
* [Solution](https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution)
* [Analysis](https://leetcode.com/problems/coin-change/discuss/77378/Easy-To-Understand-Recursive-DP-solution-using-Java-(with-explanations))

</details>


<details>
	<summary>K Palindromes</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not/0)  
* [Solution and Analysis](https://www.geeksforgeeks.org/find-if-string-is-k-palindrome-or-not/)

</details>


<details>
	<summary>Edit Distance</summary>

* [Question Link](https://leetcode.com/problems/edit-distance/)  
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/LeetCode%20Non-Contest%20Solutions/%2372%20Edit%20Distance/DP%20Approach.cpp)
* [Analysis](https://leetcode.com/problems/edit-distance/discuss/25846/C%2B%2B-O(n)-space-DP) (Also - Youtube)

</details>

<br></br>

### Phase  : Sliding Window

<details>
	<summary>Maximum of Every window of size `k`</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0)  
* In class, we discussed the solution with **multisets**. There also exists a solution with **Deque** container in **STL**.
* [Solution with Deque](https://ide.geeksforgeeks.org/D1Eeq2OuEE)
* [Analysis with Deque](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/)

</details>

<details>
	<summary>Distinct Elements in Every window of size `k`</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1)  
* [Solution and Analysis](https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/)

</details>


<details>
	<summary>Subarray with given sum</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0)   
* [Analysis and Solution](https://www.geeksforgeeks.org/find-subarray-with-given-sum/)
* Read carefully into the **Time Complexity Analysis**a

</details>


<details>
	<summary>Longest Substsring with Distinct Characters</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0)  
* [Solution and Analysis](https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/)

</details>


<details>
	<summary>Minimum Window Substring containing Every Character of Other String</summary>

* [Question Link 1](https://leetcode.com/problems/minimum-window-substring/)
* [Question Link 2](https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0)   
* [Solution](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/GeekForGeeks/Smallest%20Window%20with%20all%20characters%20of%20other%20string/First%20Submission%20(Correct).cpp)
* [Analysis 1](https://leetcode.com/problems/minimum-window-substring/discuss/26840/Sharing-my-straightforward-O(n)-solution-with-explanation)
* [Analysis 2](https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/)

</details>

<br></br>


### Phase  : Divide and Conquer

<details>
	<summary>Merge Sort</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/merge-sort/1)   
* [Analysis and Solution](https://www.geeksforgeeks.org/merge-sort/)

</details>


<details>
	<summary>Inversion Count</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/inversion-of-array/0)
* [Analysis and Solution](https://www.geeksforgeeks.org/counting-inversions/)

</details>

<br></br>

### Phase : Binary Search

<details>
	<summary>Painters' Partition Problem</summary>

* [Question Link](https://www.interviewbit.com/problems/allocate-books/)   
* The alternate name of this question is **Allocate Books**.
* [Solution](https://ide.geeksforgeeks.org/1S7sZlWUPp)
* [Analysis] --- **Interviewbit Solution**

</details>


<br></br>


### Phase : Matrix

<details>
	<summary>Search in a Row wise and Column wise Sorted Matrix</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0)   
* [Analysis and Solution](https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/)

</details>

<details>
	<summary>Spiral Order Printing of a Matrix</summary>

* [Question Link](https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0)   
* [Analysis and Solution](https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/)

</details>

<br></br>

# What Next?

* Comparators and their use-cases
* Prime Number Detection and Integer Factorization using Sieve
* DFS
* BFS
* Connected Components
* Union Find
* Backtracking
* Cycle Detection in a Graph
* Topological Sorting
* Flood Fill Algorithm

