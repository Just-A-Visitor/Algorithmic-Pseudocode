## Time Limit Exceeded
* Huge input/output? Did you try using `scanf`, `printf`?
* Huge input/output? Did you try `fast_input_output`?
* Too many lines to print? Use `#define endl '\n'`
* Interactive Problems? Did you forget to flush the output?

## Class
* Compilation error? Did you forget the semi colon?
* Compilation error? Did you forget to make the functions/constructor public?
* Compilation error? Did you forget to override a virtual function?
* Compilation error? Did you forget to mention the scope of the methods?

## Strings
* TLE? Consider using an array of size `26`/`256` instead of a map.

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


## Trees
* Did you forget to convert everything to zero based indexing?
* *DP on Trees*? Did you forget the condition `parent == child`? (+2)


## DFS
* Recursive call ? Did you call `source` again instead of `child`?

## Sieve
* Did you start the outer loop from 2 instead of 1?

## Bitwise
* Don't mixup `|`, `or`
