**Link**
[Recursion](https://leetcode.com/problems/swap-nodes-in-pairs/discuss/259625/Detailed-Explanation-with-Pictures-C%2B%2BJavaScript)

[An iterative solution using sentinels](https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11046/My-simple-JAVA-solution-for-share)

**Intuition**
* The idea is simple. Just swap 2 nodes manually and let recursion do the rest.

**Algorithm**
1) Extract the first and the second node of the list. 
 ![image](https://assets.leetcode.com/users/just__a__visitor/image_1553184089.png)
 2) Connect the first node to the third node
 ![image](https://assets.leetcode.com/users/just__a__visitor/image_1553184135.png)
 3) Connect the second node to the first node
 ![image](https://assets.leetcode.com/users/just__a__visitor/image_1553184175.png)
4) Update the head and update the third node (via the recursion blackbox)
![image](https://assets.leetcode.com/users/just__a__visitor/image_1553184228.png)

