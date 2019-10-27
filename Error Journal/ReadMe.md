## Graphs
* Is the graph undirected ? Did you forget to add both sides of the edge in the adjacency list?
* Is the graph directed ? Did you accidentally add an undirected edge instead of a directed one?
* Is the input one-based? Did you forget to decrement everything while taking the input?
* Is the input one-based? Did you forget to increment everything while printing the output?
* Reusing a `visited` array / Re-running a `DFS`/`BFS`? Did you re-initialize everything?
* Have you wondered over the fact that the graph can be disconnected? What about isolated vertices?
* Does your code handle cycles in the graph?
* Take care of cycles of length 2 (Non existent in undirected graphs).
* Getting a **TLE** while running BFS? Did you forget to pop the queue?
