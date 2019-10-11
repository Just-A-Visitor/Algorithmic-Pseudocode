## Review
I didn't realize that the 2 trees were BST. I solved it assuming normal trees (by converting to hash map). Although the complexity remains linear, it's not such a good solution. I should really code up the alternate solution using Tree Paradigms.

# Time Complexity
I see a lot of solutions applying **Binary Search** on the second tree. The worst case time complexity of these solution is *O(n1 * n2)*. This is because *Searching* in a Balanced BST is *O(log(n))* but searching in a normal BST is only bounded by *O(h)* where, `h` is the height of the tree. Hence, in the worst case, the second tree might be tilted to one side and hence searching would take *O(n)* time for each call resulting in *O(n1 * n2)* time complexity.

**My Suggestion** : Since we are already using Linear Space (due to recursive calls), why not just store the second BST in  a Red Black Tree (such as Maps in C++). This would ensure worst case **O(n log(n))**.

# Intuition
Perhaps this is better visualized as an array problem. Given 2 arrays, does there exists 2 numbers (one in each) that sums upto `k`. Calculating this is very easy. Just store all the values of both the trees in 2 hashmap, and then for each element in one hashmap, check if its complement is present in the other or not.


## Blog
[Link](https://leetcode.com/problems/two-sum-bsts/discuss/397796/Searching-in-a-BST-is-not-O(-log(n)-))
