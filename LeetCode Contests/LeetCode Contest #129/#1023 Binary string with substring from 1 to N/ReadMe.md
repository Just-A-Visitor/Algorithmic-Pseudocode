[Blog](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/discuss/261123/detailed-explanation-still-bruteforce-though-c)

**Credits**
* I thought this bruteforce idea during the contest but didn't have the courage to code it up during the contest. (As I was afraid of **TLE**). However, after seeing the solution of the top performers after the contest,  especially [neal_wu's](https://leetcode.com/neal_wu/) submission, I realized that the problem was indeed a simple one and I should've gone for the bruteforce solution. **Sometimes, you just have to trust your instincts**.
* You can refer to [votrubac's post](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/discuss/260882/C%2B%2B-O(S-log-N)-vs.-O(N-*-(S-%2B-log-N))) to convince yourself why the bruteforce method works. As **Vlad** pointed out, there aren't too many numbers you can fit in such a small string. Hence, the loop would break very soon.

**Intuition**
* For each number from 1 to `N`, convert its binary representation to a string and check whether the string is present in the original string or not. Alhough string matching can be done in O(n) using **KMP** or **Rabin Karp**, I've used the bruteforce method of string library (which in practcice is more faster than the above mentioned algorithms since the chances of a lot of partial matches is very less.)
