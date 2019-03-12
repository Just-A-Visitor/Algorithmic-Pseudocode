**Intuition**
* Create a helper function `minSteps` that takes as input 2 vectors and a `candidate` and returns the minimum steps to convert every element in the `target` array to `candidate`. It returns -1 if the target vector cannot be converted in the desired fashion. This function is used to remove code redundancy.
* Create a frquency array and update the frequency of each element (as every element is in the range `[1,6]`.)
* Traverse the frequency array and capture the `candidates`, i.e, elements which occur atleast half the time [inclusive]. Note that this is not the same as majority element as majority element should occur strictly more than `n/2` times(and hence Moore's Algorithm won't work). However, there can be atmost 2 candidates.
* If there is no candidate, return -1
* For each of the candidate, try to adjust it in both the top and bottom half and take the best outcome of the two.


**Blog**   https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252446/detailed-explanation

**Alternate link**   https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252242/JavaPython-Find-Intersection-of-Dominos

https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252266/C%2B%2B-check-A0-and-B0
