# Intuition
The moves are symmetric. Hence, we can just assume the problem to be in the first quadrant. Consequently, a simple BFS would give us the required result. We maintain the `visited` state in the `count` matrix itself. We initialize it to -1, meaning it has not been visited. If it is visited, we can just store the minimum number of steps taken to reach that cell.


[Blog](https://leetcode.com/problems/minimum-knight-moves/discuss/387004/Everything-is-in-First-Quadrant)
