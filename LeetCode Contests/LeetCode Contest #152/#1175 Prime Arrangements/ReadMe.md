# Intuition
* First, count all the primes from 1 to **n** using **Sieve**. Remember to terminate the outer loop at **sqrt(n)**.
* Next , iterate over each positon and get the count of prime positions, call it `k`.
* So, for the `k` prime numbers, we have limited choice, we need to arrange them in `k` prime spots.
* For the `n-k` non prime numbers, we also have limited choice. We need to arrange them in `n-k` non prime spots.
* Both the events are indepent, so the total ways would be product of them.
* Number of ways to arrange `k` objects in `k` boxes is `k!`.
* Use the property that `(a*b) %m = ( (a%m) * (b%m) ) % m`.



[Blog Link](https://leetcode.com/problems/prime-arrangements/discuss/371968/Detailed-Explanation-using-Sieve)
