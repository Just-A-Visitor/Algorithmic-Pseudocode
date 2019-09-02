The bitwise solution is a genius one. However, `bits` didn't even cross my mind during the contest. I need to up my coding skills!
Anyway, I was thinking of the *trie* based approach during the contest (by looking at the constraints given). It cleared all the test cases and hence I would like to share my approach.
# Intuition
* First of all, notice that for each word, the ordering and the count of elements does not matter. So, we can keep all our words in a sorted order and avoid the duplicate letters. This makes the maximum size of the word to be 26 (instead of 50). 

* Further, notice that the ordering of words in the puzzle doesn't matter. We just need to keep track of the first letter of the puzzle.  So, we can also keep our puzzle in sorted manner.

* Let us define a **trie** on the set of words. The `bool isEndOfWord` field has been modified to store the number of words ending at that node. 

* Insertion in the trie is trivial, just follow the normal procedure for insertion, and in the end, increase the count of words ending at the last node by 1. 

* For any puzzle, we willl traverse the tree and get the answer. Observe that we only need to go 7 levels deep. 

* We explore all the 7 possibilities. As soon as we see the first element, we can keep incrementing the count from this node onwards. 

* If we don't see the first element, we keep going down without changing count.


# Time Complexity Analysis
At the first level, we have 7 choices, but at the next level, we only have 6 choice, and the next 5, and so on, This gives us an upper bound od `7 * 6 * ....1` = `7!`,  for each query. The overall complexity becomes **O(query_length * 7!)**, which is on the border but would hopefully pass.

### Is the bound asymptotically tight?
If we think about it in big O notation, the derivation is correct. But to make the bounds tighter, let's use the theta notation and amortized analysis,

## Lowering the upper bound
Notice that we can only go 7 levels deep. So, the answer can lie in either or all of this levels.

1) How many answers lie in the first level ? Clearly, in the worst case, it is `7C1` , as selecting any 1 would give us an answer.

2) How many answers lie in the second level? Clearly, selecting any 2 elements out of the 7 would give us an answer (since any 2 elements from the set can have only 1 sorted order, hence we need to just select elements instead of permuting them). So, the answer at the second level is `7C2`

3) Similarly, how many at the third level? Clearly, we can select 3 elements out of the 7, and it would give us a unique answer. Therefore, at the third level. we have `7C3`.

.
.
.

7) At the 7th level, we have `7C7` = 1 answer (as there is only one way to reach the 7th level as everything has to be sorted).


In conclusion, the maximum nodes we would have to visit is `7C1 + ... 7C7` = `2^7 - 1` = 127.

So, the worst case traversal would be of the order of `10 ^ 2`. So, the overall complexity is O(100 * queries_length). 

[Even if you include the hidden constant factors, it won't go beyond `100 * queries_length`


# To Do
Implement the bitwise solution.   


[Blog Link](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/371876/Detailed-Explanation-using-Trie-O(word_length-%2B-100*puzzle_length))
