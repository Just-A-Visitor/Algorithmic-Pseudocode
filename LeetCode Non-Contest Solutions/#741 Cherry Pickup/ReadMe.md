Welcome to the end game of **Leetcode**! (Atleast that's what most people think it to be!). Of course, I too had the same notion, but after solving it, it doesn't look that scary anymore. Let's jump directly to the solution.

<details>
	<summary>Switch to one-Based Indexing</summary>

### Switch to one-Based Indexing
If we switch to one based indexing, our corner cases would become almost non-existent. Why? If we hit a row or column with index `0`, we know that it has gone out of the boundary.

The conversion is easy.
<details>
	<summary>Code</summary>
  
```cpp
vector<vector<int>> new_grid(n + 1, vector<int>(n + 1, 0))

for(int i = 0; i < n; i++)
	for(int i = 0; j < n; j++)
		new_grid[i + 1][j + 1] = old_grid[i][j]
```

</details>
</details>

<details>
	<summary>Greedy Doesn't Work</summary>

### Greedy Doesn't Work!
No matter how many times I see this question, I always end up thinking that I can collect the maximum cherries using DP in the first trip (while modifying the grid, of course) and then, on the return journey, collect the maximum cherries of the new grid. However, this approach is incorrect, and I always forget the counter case. So, let's make it concrete here. Consider the following grid. Assume that the blank cells are indeed blank and you can pass through it (There are no thorns in this configuration).

|           	| **Col 1** 	| **Col 2** 	| **Col 3** 	| **Col 4** 	| **Col 5** 	| **Col 6** 	| **col 7** 	|
|:---------:	|:---------:	|:---------:	|:---------:	|:--------:	|:--------:	|:--------:	|:-------:	|
| **Row 1** 	|     1     	|     1     	|     1     	|     1    	|          	|          	|         	|
| **Row 2** 	|           	|           	|           	|     1    	|          	|          	|         	|
| **Row 3** 	|           	|           	|           	|     1    	|          	|          	|    1    	|
| **Row 4** 	|     1     	|           	|           	|     1    	|          	|          	|         	|
| **Row 5** 	|           	|           	|           	|     1    	|          	|          	|         	|
| **Row 6** 	|           	|           	|           	|     1    	|          	|          	|         	|
| **Row 7** 	|           	|           	|           	|     1    	|     1    	|     1    	|    1    	|

If you try to maximize the cherries in each trip, you'll end up taking the following path in Round 1
* Go right till column 4 (Cherries Collected --> 4)
* Go down till row 7 (Cherries collected --> 6)
* Go right till column 7 (Cherries collected --> 3)

Total --> 13

In the return trip, you have 2 options
* Go left till column 1 and go up till row 1
* Go up till row 1 and go left till column 1.


As you can easily see, in both of these options, you can only collect a single cherry.

Total -->  1

So, you'll always end up leaving one cherry in the grid. However, if you play smart, you can collect all the cherries.   
**Optimal Path**
* **Trip 1** : Go right till column 4, go down till row 3, go right till column 7 and then go down till row 7.
* **Trip 2** : Go left till  column 4, go up till row 4, go left till column 1 and then go up till row 1.
</details>

<details>
	<summary>Pre-Requisite : Creating Multidimensional Vectors</summary>

### Pre-Requisite : Creating Multidimensional vectors
Say, we want to create a 4D vector of dimension `mat[n][n][n][n]`, initialized with default values `def_val`. Let us see the results for each smaller dimension first.

<details>
	<summary>Creating a 1D Vector</summary>
	
**Creating a 1D Vector**

1) Concise Approach

<details>
	<summary>Code</summary>

```cpp
vector<int> mat(n, def_val)
```

</details>
</details>

<details>
	<summary>Creating a 2D Vector</summary>
	
**Creating a 2D Vector**

1) Naive Approach
<details>
	<summary>Code</summary>

```cpp
vector<vector<int>> mat(n)

for(auto &row_vec : mat)
	row_vec.resize(n, def_val)	
```

</details>

2) Concise Approach

<details>
	<summary>Code</summary>

```cpp
vector<vector<int>> mat(n, vector<int>(n, def_val))
```

</details>

</details>

<details>
	<summary>Creating a 3D Vector</summary>
	
**Creating a 3D Vector**

1) Naive Approach
<details>
	<summary>Code</summary>

```cpp
vector<vector<vector<int>>> mat(n, vector<vector<int>>(n, vector<vector<int>>(n, def_val)))
```
</details>

2) Concise Approach
<details>
	<summary>Code</summary>

```cpp
vector<vector<vector<int>>> mat(n)

for(auto &vec_2d: mat)
	vec_2d.resize(n, vector<int>(n, def_val))
```
</details>

</details>

<details>
	<summary>Creating a 4D Vector</summary>
	
**Creating a 4D Vector**

1) Naive Approach
<details>
	<summary>Code</summary>

```cpp
vector<vector<vector<vector<int>>>> mat(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, def_val))))
```
</details>

2) Concise Approach
<details>
	<summary>Code</summary>

```cpp
// Create a temporary 2D vector first
vector<vector<int>> vec_2d(n, vector<int>(n, def_val))

vector<vector<vector<vector<int>>>> mat(n)

for(auto &vec_3d: mat)
	vec_3d.resize(n, vec_2d)
```

</details>
</details>
</details>

<details>
	<summary>Dynamic Programming to the Rescue</summary>

### Dynamic Programming to the Rescue
It is clear that greedily picking the maximum cherries is not a feasible option. Consider any optimal path from `source` to `destination` and back again. If you notice carefully, it is the same as 2 persons collecting maximum cherries collectively, where one person starts from `(1, 1)` and goes to `(n, n)` , while the other person starts from `(n, n)` and goes to `(1,1)`. 

If you look even more closely, you'll observe that it is also the same as 2 persons starting simultaneously from `(n, n)` and going towards `(1, 1)`. Of course, if they are present at the same cell at the same time, only one of them would take the diamond present in that cell.

That's all the obsesrvation we need to solve this question.

Suppose, there are 2 persons `A` and `B`. Both the persons start from certain cells (possibly different) **at the same time** and try to reach the left-most cell of the grid,i.e, `(1,1)`. Of course, they should only take valid step, i.e, **up** or **left**.

Let us define `dp[x][y][p][q]` as **The maximum amount of diamonds(combined) that can be collected by both persons along their path to `(1, 1)` when Person `A` starts at the cell `(x, y)` while Person `B` starts at the cell `(p, q)`.** (We assume that if both the people reach the exact same cell at any point, only one of them would collect the diamond in that cell). Of course, it might happen that you are not able to reach `(1,1)` from the given starting positions. In that case, we set `dp[x][y][p][q] = minus_infinity`. 

Notice that our answer would be `dp[n][n][n][n]`. 

The transitions are simple. At the next time step, both the persons have to take a step (either to the *left* or *up*). Observe that these are independent events.

Here are the 4 possible scenario.

| **A's Move** 	| **B's Move** 	| **A's New Pos** 	| **B's New Pos** 	|
|--------------	|--------------	|-----------------	|-----------------	|
|    **Up**    	|    **Up**    	|   `(x - 1, y)`  	|   `(p - 1, q)`  	|
|    **Up**    	|   **Left**   	|   `(x - 1, y)`  	|   `(p, q - 1)`  	|
|   **Left**   	|    **Up**    	|   `(x, y - 1)`  	|   `(p - 1, q)`  	|
|   **Left**   	|   **Left**   	|   `(x, y - 1)`  	|   `(p, q - 1)`  	|


After each one of them has performed their move, we would like to know what is the maximum diamonds that can be collected from the new positions. Now, this has been converted to a typical dynamic programming problem.

To summarise, the transitions are :

<details>
	<summary>Transistions</summary>

```cpp
/* Ensure DP is intialized with minus infinity */
if (either of the cell is a thorn)
	continue

dp[x][y][p][q] = max(up_up, up_left, left_up, left_left)

// All the moves are invalid
if( dp[x][y][p][q] < 0 )
	continue

dp[x][y][p][q] += mat[x][y]

if( both cells are not the same)
	dp[x][y][p][q] += mat[p][q]
```
</details>

The Base Case ? : When both the persons start at `(1, 1)`. There's no possible move left, and they can only collect the diamond in that cell. Hence, `dp[1][1][1][1] = mat[1][1]`.

</details>

<details>
	<summary>Do we need to modify the grid?</summary>

### Do we need to modify the grid?
The answer is **No**. At first sight, it looks as if person `B` can visit a cell which has been already visited by person `A`. However, this is not true. And I'll leave it to you to prove the following result.

**Theorem** : The paths of both the  persons are disjoint and intersect **if and only if** they meet at the intersecting cell (at the same time). [In other words, person `B` cannot enter a cell which has already been visited by person `A` in the past (and vice-versa)).

</details>

<details>
	<summary>Did we miss anything?</summary>

### Did we miss anything?
Yes, it might happen that there is no path from source to destination. Hence, we need to ensure that we do not return a negative value (Either return `0` or return `-1` as per the requirements of the question).

</details>

<details>
	<summary>Putting it all together</summary>

### Putting it all Together
Just to re-iterate
1) Convert to one based indexing.
2) Create a 4D vector and initialize it to `minus_infinity`
3) Set the base case. (`dp[1][1][1][1] = new_grid[1][1]`)
4) For each of the **n^4** starting positions, compute the maximum value of the next move.
5) If no move is possible, skip it.
6) Make the best move, and take the diamong in the current cells.
7) Make sure not to double count the current cell (if they are identical)
8) If there is no path, return 0, else, return `dp[n][n][n][n]`

<details>
	<summary>Code</summary>

```cpp
const int m_inf = -1e5;

int Solution :: cherryPickup(vector<vector<int>> &oldGrid)
{
	int n = oldGrid.size();

	// Let us create 2 borders by switching to one based index
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < n; j++)
			grid[i + 1][j + 1] = oldGrid[i][j];

	vector<vector<int>> vec_2d(n + 1, vector<int>(n + 1, m_inf));

	vector<vector<vector<vector<int>>>> dp(n + 1);
	for(auto &vec_3d : dp)
		vec_3d.resize(n + 1, vec_2d);

	/* dp[x][y][p][q] represents the maximum cherries that 2 persons can pick up
	 * if Person 1 goes from (x, y) ---> (1, 1) and Person 2 from (p, q) ---> (1, 1)
	 */

	// Base Case : Already at the destination
	dp[1][1][1][1] = grid[1][1];
	for(int x = 1; x <= n; x++)
	{
		for(int y = 1; y <= n; y++)
		{
			for(int p = 1; p <= n; p++)
			{
				for(int q = 1; q <= n; q++)
				{
					// Atleast one person is stuck
					if( (grid[x][y] == -1) or (grid[p][q] == -1))
						continue;

					int up_up = dp[x - 1][y][p - 1][q];
					int up_left = dp[x - 1][y][p][q - 1];
					int left_up = dp[x][y - 1][p - 1][q];
					int left_left = dp[x][y - 1][p][q - 1];

					int max_val = max(up_up, left_left);
					max_val = max(max_val, max(up_left, left_up));

					// No moves possible from here
					if(max_val < 0)
						continue;

					dp[x][y][p][q] = max_val + grid[x][y];

					// If they are not the same cell, add the contribution
					if( not (x == p and y == q))
						dp[x][y][p][q] += grid[p][q];
				}
			}
		}
	}

	// Don't forget to take maximum (if path doesn't exist)
	return max(0, dp[n][n][n][n]);
}
```
</details>
</details>


<details>
	<summary>Reducing the Time Complexity</summary>

### Reducing the Time Complexity
Notice that we are computing the answer for every possible pair of starting positions but in the end, we are only using the result of `dp[n][n][n][n]`. If you notice carefully, you'll see that if 2 persons start at the same time from cell at `(n, n)`, then there is a correlation between their co-ordinates at any given point of time.

**Lemma**
At any given point of time `(x + y) == (p + q)`, given both the people start from the same cell.

**Proof**
It is very easy to see that any step, person `A` would either take a step up, in which case, `x` reduces by 1, or takes a step left, in which case `y` reduces by 1. Hence, no matter what, the sum of the co-ordiantes, i.e `(x + y)` decreases exactly by 1. The same is true for the second person. Hence, this sum would be equal at all times, given they start from the same position.

So, now we don't need the fourth dimension in our DP table. We can recover it from the first three dimensions, effectively reducing the complexity to **O(n^3)** from **O(n^4)**.

**Everything remains the same except now we need to check if the recovered dimension goes out of bounds or not**. (Notice that we didn't need this check in the 4D DP case. Why?

</details>

<details>
	<summary>Final Working code</summary>

### Final Working Code

**Steps**
1) Convert to one based indexing.
2) Create a 3D vector and intialize it to `minus_infinity`
3) Set the base case, `dp[1][1][1] = new_grid[1][1][1]`
4) For each **n^3** states, do
	* Recover the fourth dimension.
	* Check whether it's going out of bounds or not.
	* Check if either of the current cells is a thorn.
	* Calculate the maximium profit from the next 4 moves.
	* If stuck from everywhere, skip.
	* Take the best move and also collect the diamond in the current cell.
	* Don't double count if you are in the same cell.
5) Make sure that the return value is atleast zero.

<details>
	<summary>Code</summary>

```cpp
const int m_inf = -1e5;

int Solution :: cherryPickup(vector<vector<int>> &oldGrid)
{
	int n = oldGrid.size();

	// Let us create 2 borders by switching to one based index
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < n; j++)
			grid[i + 1][j + 1] = oldGrid[i][j];

	vector<vector<vector<int>>> dp(n + 1);

	for(auto &vec_2d: dp)
		vec_2d.resize(n + 1, vector<int>(n + 1, m_inf));

	/* dp[x][y][p][q] represents the maximum cherries that 2 persons can pick up
	 * if Person 1 goes from (x, y) ---> (1, 1) and Person 2 from (p, q) ---> (1, 1)
	 * We recover 'q' from (x + y) = ( p + q)
	 */

	dp[1][1][1] = grid[1][1];
	for(int x = 1; x <= n; x++)
	{
		for(int y = 1; y <= n; y++)
		{
			for(int p = 1; p <= n; p++)
			{
				int q = ( x + y ) - p;

				// This move can never happen
				if( q < 1 or q > n)
					continue;

				if( (grid[x][y] == -1) or (grid[p][q] == -1))
					continue;

				int up_up = dp[x - 1][y][p - 1];
				int up_left = dp[x - 1][y][p];
				int left_up = dp[x][y - 1][p - 1];
				int left_left = dp[x][y - 1][p];

				int max_val = max(up_up, left_left);
				max_val = max(max_val, max(up_left, left_up));

				// Don't miss this case
				if(max_val < 0)
					continue;

				dp[x][y][p] = max_val + grid[x][y];

				// If they are not the same cell, add the contribution
				if( not (x == p and y == q))
					dp[x][y][p] += grid[p][q];
			}
		}
	}

	// Don't forget to check this case
	return max(0, dp[n][n][n]);
}
```

</details>
</details>

<details>
	<summary>Credits</summary>

### Credits
[The Real MVP](https://leetcode.com/problems/cherry-pickup/discuss/165218/Java-O(N3)-DP-solution-w-specific-explanation)
