### Review
* Clearly the **Hello World** of DP on Trees. Make sure to understand **House Robber on a 1D array** first.
* Initially, I forgot the `parent` parameter which led to **TLE** (Infinite Loop).
* The second one was a serious bug and I was able to debug it only because the sample cases where nice and tricky. When we decide to leave the `i-th` vertex, we shouldn't necessarily take all the `children`. (Why?). Because it might devoid us of taking the grand children. However, we do want to take the profit from the subtree of all the children. Hence, I declared a new array `dp_subtree` which gives the maximum coins that can be robbed from the `i-th` subtree (regardless of whether we take it or not).
* Naturallly, `dp_subtree[i] = max(dp_include[i], dp_exclude[i])`. So, when we decide to leave the `i-th` vertex, we can just accumulate the profit of all the subtrees rooted at the children via this array. 
* Of course, we could have done this without creating an array. However, I wanted to keep things self-explanatory for the first time.
* Looking on the bright side, I did clear all the test cases on the first submission.


### Credits
* [Codeforces Blog](https://codeforces.com/blog/entry/20935)
