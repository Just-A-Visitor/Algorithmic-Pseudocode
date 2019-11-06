# Intuition

There is one key point for understanding the solution ==> **If we start at the i-th station and the first station that we are unable to reach is numbered `k`, then we won't be able to reach `k` even if we start at at any station to the right of `i` but left of `k`**. This is very crucial since it tells us that neither `i` nor any station between `i` and `k` can be a candidate for the answer. The reason is simple, leaving out stations to the left can only result in fuel loss so we won't be able to make it.

# Algorithm

* Start at the first station. Enqueue it. Add the fuel and remove the distance to be covered. It might happen that we are unable to reach the second station. Enqueue it nevertheless. We will rectify the mistake in the next iteration.

* In the next iteration, if the fuel becomes negative, then it's an indication that we made a wrong decision in the previous step to enqueue the previou station. This means that the current staton can't be reached by any station encountered before (**Intuition**). Clear the queue and reset the fuel counter as we will start a new iteration from this station (as base).

* If the fuel is not negative, enqueue the current station (adding up the fuel and reducing the distance). 

* Keep incrementing **current** via modulo **n** to ensure that it forms a circular pattern of neighbours.

* At any point, if the size of the queue becomes **n**, it means that after we enqueued the first element, the fuel was never negative. This means that we have found the station to perform the circular tour. Return the front of the queue. Ensure that the size is checked after the fuel check. This ensures that we didn't make a wrong decision while connecting the endpoints of the circle.

# Termination

* It is clear that if the size of the queue is **n**, we've found an answer. What if the answer doesn't exist? How do we detect that?

* If you look closely, each station is enqueued exactly once in the first pass, no matter what. When the last station is enqueued, each of the stations would be enqueued once more. (except the last if the answer exists). If the answer doesn't exists, the last station will be enqueued again, and so will the 1st station.

* **If the first station is enqueued the third time, no solution exists.**


## Reducing the Space Complexity

* Since the elements of the queue are in order (and can be determined if we are given the first element and the size of the queue), we don't need and explicit queue.
* Just update size while enqueuing and update `start` only when the first element is being enqueue.
* While clearing the queue, set `start` to -1 and `size` to 0.


# Tasks

* Read *LeetCode's* top solution for an alternate approach.
* Explain the clean **Concatenation Approach**
