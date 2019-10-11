**Iterative Solution**
* This is one of those solutions where the iterative version is easier than the recursive one.
* We traverse the linked list and reverse elements on the go.
* Initially previous points to the left of `head`, i.e `nullptr` and `current` points to the head
* In each iteration, we first make a backup of the element to the right of `current` (or else we would lose access to it as we plan to modify `current->next`). Next we actually modify `current->next` to point to the previous element (the element to the left of it). Then, we modify our `previous` to point to `current` (as next iteration is about to begin), and finally we update our `current` to the right neighbour, i.e the backup `temp` pointer.
* This would ensure that all the element would point to its left (instead of right).
* Finally make sure that you return `previous` as the new head (because when the loop exits, `current` would be null).


**Recursive Solution**
* This was a great use-case of recursion.
* Thinking naively, we can reverse all elements except the `head` recursively and then put `head` in its correct place (i.e the end of the reversed linked list). However this approach has very bad time complexity (Why?). Because in each recursive call, after the sub-list has been reversed, you'll end up travelling the entire list to get to the last element (in order to connect it to head). Upon analysis,we find that it takes up `1+2+3+...n`  = `n(n+1)/2` time which is `O(n^2)`. 
* How do we improve? Clearly the only thing which leads to huge time complexity is the fact that we do not have access to the last element of the reversed list. 
* But, think carefully, what would the last element of the reversed sub-list be? It would actually be the second element of the original list. Do we have access to it in constant time? Yes, we can easily access it via `head->next` as we haven't altered `head` yet.
* So now, we access the last element of the reversed sub-list in `O(1)` and connect it to the first element of the original list. (its correct place in the new list).
* We have to make sure that we block the access of the `head` (which was referencing to the last element of the reversed sub-list). Since `head` is now the last element, `head->next` would be null. 
* Remember to return the new reversed head obtained from the recursive call.


**Time Complexity** of both solutions is `O(n)`. The space complexity is `O(1)` and `O(n)`.

**Credits** ----- Inspired by a couple of `Discuss` posts for this question.


**Blog** https://leetcode.com/problems/reverse-linked-list/discuss/254618/C%2B%2B-Detailed-Explanation-Recursive-and-Iterative
