

Approach

*    Create a new stream called newStream which behaves as if the characters of the current string are present in the standard 
     input or cin
*   Start extracting each string from the streaming string
*    Keep pushing the words onto the stack. This ensures a LIFO order and the last word to enter would be popped first.
*    Keep doing the process till the stream becomes empty.
*    Extract words from the stack and append it to answer
*    Remember to append space if it is not the last word.

Problem

https://leetcode.com/problems/reverse-words-in-a-string/

Blog

https://leetcode.com/problems/reverse-words-in-a-string/discuss/248752/C%2B%2B-Detailed-Explanation-stringstream-Memory-InEfficient  
