# Definition
* **Partial sum** at a particular cell is defined to be the sum of all the elements inside the boundary created by the left and above.   

* **Partial sum** at a particular cell is defined to be the sum of all elements which can be reached by taking a step to the left or top (or any combination of left and top). 

* Partial sum at a particular cell includes that cell.

* `partial_sum[row][col] = sum(mat[row][0,...col]) + partial_sum[row-1][col]`

# Example
The partial sum of
```
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1
```

is 

```
1 2 3 4 5 
2 4 6 8 10 
3 6 9 12 15 
4 8 12 16 20 
5 10 15 20 25 
```
