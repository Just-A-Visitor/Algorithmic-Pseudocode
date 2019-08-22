[Problem](https://codeforces.com/contest/1204/problem/C)     
[Submission](https://codeforces.com/contest/1204/submission/59329198)     
[Editorial](https://codeforces.com/blog/entry/69244)    

# Strategy
There were a total of 5 questions. This time I decided to start the contest with the third problem. 

It took me around 1 hour and 25 minutes to come up with the logic and around 25 minutes to code (and debug it). 

At first, I read the problem description and drifted far away from the intended solution. I believed that it would involve concepts of **back edges** and the **BFS tree**. I spent a  lot of time building a solution in that direction. Finally, I realized that **C** level questions aren't that difficult and that I was overthinking things. 

At one step, I saw the constraints and concluded that we needed to remove the cycles in the path (as the number of vertices was at max 100, and the number of vertices in the path were at max 10^6). I thought that we cannot have repeating vertices in the path. I took some time to build the solution to the sub problem (i.e, removing cycles).

Finally, I came up with this logic. Create an array `next`, where `next[i]` represents the next vertex to visit, if we are standing at the i-th vertex. Naturally, when a cycle is detected, the `next[start]` would be updated to the next vertex which needs to be visited after the cycle is completed. [Here, `start` represents the starting point of the cycle]. 
At the end, `next[i]` would represent the last vertex which was visited from the i-th node. This ensures that all cycles will vanish.

At this stage, I had reduced `m` from 10^6 to 100. I still had no progress in the question itself. But then I looked up the solution and realized that we did not need to remove the cycles (in fact, that was the main crux of the problem statement). Removing cycles would definitely generate an incorrect answer as we do not require the elements of the cycle anymore for the shortest path (while the question demands that the shortest path should be equal to the original subsequence). Moreover, the second test case had repeating vertices in the answer, but I didn't look at that test case before thinking up the solution. So, in fact the size of the answer set could have been as huge as 10^6 and not just 100.



All my efforts till now were wasted and time was running out. I think it was over an hour now. And all this happened simply because I hadn't read the question properly and didn't go through the test cases given before jumping onto the solution.



Then I tried to find some pattern using just the first test case. I somehow approached the problem greedily. I started with the second vertex and asked myself, can I remove this vertex? Let's call the triplet `(left, current, right)`. If it was possible to go from `left` to `right`, then we cannot remove `current` at any cost (as we won't need `current` again in the shortes path from `left` to `right`, while the question demands that we should need every vertex in the original path). However, if `left` and `right` are not connected, then we can remove `current` as to go through `left` to `right` in the shortes path, we will have to pass through `current`, hence retaining the sequence.


Doing this for the second element seemed trivial. Now, suppose we exclude the second element from our journey. When the third element becomes `current`, what should be `left`? . Is it the 2nd element or the first one? I thought over it a lot and concluded that since you have removed 2nd and if there was a way to go from 1 to 3, then we would never need 2 again (which was violating the rules of the question). Hence, I need to check the triplet (1,3,4) instead of (2,3,4). This implies that we are actually deleting the element from the array if it is not a part of the journey. Naturally, to simulate this, we would need a stack. (I felt pretty good that I finally discovered that it was a stack based solution in disguise).

To code up the solution, I needed to decide what to put on stack? Should I put 2 elements on the stack , and keep `right` pointer on the array?. Finally, after a **LOT** of experimenting, I decided to insert 3 elements in the stack, take out 3 elements, apply the above check, and if `current` needs to be deleted, insert `left` and `right` back. After this, insert one more element from the array and repeat. If `current` is not deleted, it means that the stack wasn't changed. Just put those 3 back, and then put the next element of the array. 

# Issues
* After coding up the solution, I kept running into seg faults. After some time, I realized that the rows of the matrix was in the form `10101` and not `1 0 1 0 1`. I was in fact taking integer inputs, whereas I should have taken character input and then converted to integer.

* Made a lot of silly mistakes while not using touch typing. Got a bit nervous and started typing with 2 fingers. This led to a lot of compilation errors.

* Didn't write the pseudocode before starting to code. This led to a lot of errros.

* Missed the case where there is a cycle of length 2. Saw this from the sample test case. I should have figured it out myself. In that case, I can go from `left` to `right` as they are same. But, in the adjacency matrix, the value was zero, leading us to believe that you can't go from `a` to `a`. There were 2 ways to handle this, either put 1 on diagonals or explicitly write `left != right`. I choose the latter.

* Another issue was the fact that after removing a vertex, we can't even go from `left` to `current`. So, we should not at all check whether we can go from `left` to `right`. 
I handled this by adding this condition. 
    * If left is not equal to right and you can go from left to current and also from current 
    to right but not from left to right, remove the `current` vertex.

* The stack might need to be processed even after the last vertex is added. Spent a lot of time debugging this.


With around 10 to 15 minutes left, I finally had a working solution.

# Surprise 1
I tried to submit the solution, but the judge said I hadn't registered for the contest. **Wow!**. I forgot to register.


I waited a long time for the system testing to be over so that I can finally submit my solution. 


# Surprise 2
I submitted the solution and it passed all system test cases. Wow, big achievement for me. 


# Aftermath
I went to the comment section. No one had used stack. A lot of them were talking about *Floyd Warshall*. (Wow, where did that come in?). It runs in O(n^3) time. I was happy that my solution runs in O(m) time, plus the time to scan the matrix. Morevoer, the top rankers had solved it in O(m*n + n^3). I was very happy to come up with solution with better complexity.

Someone even asked in the comments section where he went wrong with the greedy approach. I told him that you need to iterate the triplets in the modified array using stack and not every triplet in actual array.

# Surprise 3
I was trying to sleep. It's 2 AM and I'm not even thinking about the question. And suddenly it struck me that my solution is wrong and Greedy won't work. The system test cases were too weak. Suppose we have a linear chain, `1-2-3-4`. The answer should be `1-4` but my code produces `1-3-4` (as it terminates because 1 and 3 aren't connected). I am frustrated. Greedy has betrayed me. I couldn't sleep. I woke up and verified the test case. Yes, my solution was wrong. Then I went through the submissions, and I realized that the 2 approach for greedy (with and without modifying the array failed on simpe test cases). Here is the [test case](https://codeforces.com/blog/entry/69223#comment-536849).


# Level Zero
Everything went in vain. I submitted both the test cases to the testers (ultimately being hacked, of course). Now I am at level zero. I need to learn **Floyd Warshall** and revisit this question.

**Don't trust Greedy**.










































































