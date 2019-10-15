
# Proof of Correctness of E

Let us draw a graph on 3 vertices, namely `a` , `b`, and `c`.  There is an edge from `i` to `j` if it is permissible to go from `i` to `j`. Notice that there can be self loops. Initially, the graph looks like this.      
![Initial Graph](https://github.com/Just-A-Visitor/Coding/blob/master/Codeforces%20Contests/CF%20Round%20582/Images/1.png)     

Now, as soon as we receive a query, we need to remove the corresponding edge in the graph. For example if the string `s` is `ab`, it means we won't be able to go from `a` to `b` as it is now forbidden. Similarly, if the string `t` is `cc`, it means that we need to remove the self loop of `c`.  It is clear that we need to remove exactly 2 edges from the graph, and after that if we can traverse the graph such that all the vertices are visited exactly `n` times, and at the same time, ensuring that we travel only on permissible edges, then we can get our answer.

**Case 1** --> We remove 2 self loops.     
![Graph of Case 1](https://github.com/Just-A-Visitor/Coding/blob/master/Codeforces%20Contests/CF%20Round%20582/Images/2.png)     
Observe that we can travel the graph in the path `abc abc ...`. 

**Case 2** --> We remove 1 self loop and 1 normal edge.      
![Graph of Case 2](https://github.com/Just-A-Visitor/Coding/blob/master/Codeforces%20Contests/CF%20Round%20582/Images/3.png)      
WLOG, assume that the directed edge from `a` to `b` has been removed. This means that if we start at `a`, we can't directly go to `b`. Fine, Let us start from the vertex which isn't reachable in one move, i.e `b`. We traverse the graph in the manner `bac bac ...`.

**Case 3** --> We don't remove any self loops. For each edge `i --> j`which is removed, we will call `i` as being marked.      
**Sub Case 1** ⇒ Only 1 vertex is marked     
![Graph of subcase 1](https://github.com/Just-A-Visitor/Coding/blob/master/Codeforces%20Contests/CF%20Round%20582/Images/4.png)       
WLOG, Suppose, only the vertex `a` is marked, this means that both outgoing edges from `a` is removed. We can traverse the graph in the order`ccc... bbb.... aaa...`

**Sub Case 2** ⇒     
![Graph of sub case 2](https://github.com/Just-A-Visitor/Coding/blob/master/Codeforces%20Contests/CF%20Round%20582/Images/5.png)      
2 Vertices are marked. Suppose they are `a` and `b`.  If we cutoff both the link of `a` and `b`, we can traverse the graph in the manner `acb bca acb ....`.  So now, the only case remaining is the one where the edge `a ---> b` is cutoff, and the edge `b --> c` is cutoff. Notice that we can still traverse the graph in the manner `acb acb ...`


