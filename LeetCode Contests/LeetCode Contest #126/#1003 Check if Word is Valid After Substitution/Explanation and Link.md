Approach 1

* Create a pattern of length 3, namely "abc".
* Search the pattern in the string and erase it from the string, It can be easily done via the str.find() function, Note that str.find() outputs npos defined in the scope of string if the pattern is not present in the string. To ensure that the string contains no valid instance of the pattern, we compare the output to string::npos to confirm whether to terminate the process or not.
* After the stage where no more patterns can be found and erased, check whether the string is empty or not. Ideally, it should be empty, since it was created with the help of valid strings.


Problems With Approach 1

* Deletion in a string is not really O(1), even if we are deleting small number of characters i,e, abc as we have to move the entire contents after it. So for very large strings, the approach 1 might not work that efficiently. Below, I describe a method that computes the answer in a single traversal of the string.

Approach 2

* Create a new class, specialStack that performs all the functionalities of a stack, along with keeping track of the second element in the stack (in O(1) ).
* Whenever you push an element, make sure to update the second element.
* Pop --- Whenever you pop an element, update the secondElement by popping the top element and immediately pushing it back. This ensures that the secondElement is automatically updated. [This was pointed by a user in the comment section].
 empty(), top(), size() remains unaffected.
* Traverse the string and keep pushing the elements onto the stack. Whenever you see a c, check whether the top two elements are b and a (in that order). If yes, pop them from the stack and keep going.
* At the end, the stack should be empty. If it is not, the string is invalid.
 Update

* A lot of people are posting solutions using just the count of a,b,c so far. But It fails for trivial test cases like aabbcc or any amount of a followed by same amount of b followed by same amount of c.
* As is evident from some of the other great answers, making a custom stack isn't that necessary, it can also be done via a simple stack. The below implementation just avoids case analysis.
 You can refer to the normal stack solution here
 
 
 Link
 
 https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/discuss/247603/C%2B%2B-Pattern-Matching-vs-Custom-Stack-(O(n))
