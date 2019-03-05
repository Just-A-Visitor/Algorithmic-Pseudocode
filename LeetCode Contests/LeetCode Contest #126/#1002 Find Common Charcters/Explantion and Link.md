Approach

* Create a vector freq that maps each character of the alphabet to its frequency in any given string.
* Create a vector minMatching that stores the count of characters which occur in all the strings so far
* Traverse the list of strings and for each string, update (overwrite) the freq vector and accordingly update the minMatching vector.
* At the end, traverse the minMatching vector and append each character as a single string in the answer vector.

Miscellaneous

* The minMatching vector has been initialised with INT_MAX instead of 0 to handle the updation of first string. After that, all the non-appearing charcters would be set to zero.

Link

https://leetcode.com/problems/find-common-characters/discuss/247798/detailed-explanation-c-on
