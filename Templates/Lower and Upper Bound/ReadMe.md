# Discussion
You might've already come across **Binary Search**, which gives you the index of a particular key (if it exists). However, STL, apart from its predefined function `binary_search`,  also provides 2 more powerful functions that are supersets of `binary_search`, namely `lower_bound` and `upper_bound`. The definition is a bit tricky, but once you understand the basic principles, you'll be using it everywhere (Trust me!).

#### **Observations**

* Without even defining the functions, let us digest a fact.
	* `lower_bound` and `upper_bound` are **exactly** identical functions of `key`  **if and only if** the key is not present in the container. (Notice the bi-directional implication).    
* The number of integers in the closed-open `[low, high)` or open-closed `(low,high]` is `high - low`.



#### **Definition**

* **Lower_Bound**
  * It gives you an iterator pointing to the first occurrence of the key.
  * If the key doesn't exist, it gives you an iterator to the first element which is greater than key.
  * If all the elements are smaller than key, it gives you an iterator to the end of the container.

* **Upper_Bound**
	* It gives you an iterator pointing to the first occurrence of a number which is **strictly** greater than key.
	* Its behaviour is same, irrespective of the fact whether the key exists or not.
	* If all the elements are smaller than or equal to the key, it gives you an iterator to the end of the container.

That's all the theory that you need to know to fully understand `upper_bound` and `lower_bound`.

<br></br>

#### **Examples**

Arr_Val = `[1, 3, 5, 5, 5, 7, 9, 9]`.   
Arr_Ind = `[0, 1, 2, 3, 4, 5, 6, 7]`.

* `lower_bound(5)` would give you an iterator pointing to index `2`. (with value 5)
* `upper_bound(5)` would give you an iterator pointing to index `5`. (with value 7)
* `lower_bound(6) == upper_bound(6)` (as 6 is not present). Both of them would point to the next greater element, i.e,  index `5` with value `7`.
* `lower_bound(9)` points to the index `6` with value `9`.
* `upper_bound(9)` points to the the end of the iterator (with index `8`)
* `lower_bound(10) == upper_bound(10)` points to the end of the container with index  `8`.

<br></br>

#### **Assumptions**
1) **The array is sorted in increasing (or non-decreasing) order**.
2) Assume zero based indexing everywhere.

<br></br>

#### **Task**
1) You need to answer each of the 9 queries in **O( log(n) )**

<br></br>

#### **Hints**
* You can answer each query using 2 simple **STL** functions, `Lower_Bound` and `Upper_Bound`.

<br></br>

#### **Notation**
* `Lower_Bound(key)` is to be implemented as `lower_bound(myVec.begin(), myVec.end(), key)`
* `Upper_Bound(key)` is to be implemented as `upper_bound(myVec.begin(), myVec.end(), key)`
* To convert an iterator to a number (more specifically *index*), we subtract `myVec.begin()` 
  * For example, whenever we say `Lower_Bound(key)`, we actually mean `lower_bound(myVec.begin(), myVec.end(), key) - myVec.begin()`.
  * However, when we say `Upper_Bound(key) - Lower_Bound(key)`, we do mean the syntax, `upper_bound(myVec.begin(), myVec.end(), key) - lower_bound(myVec.begin(), myVec.end(), key)`. 

<br></br>

### 1) Find the frequency of a  key
* **Question** : Find the frequency of an element `key` in the array. (It can be zero too).

<details>
	<summary>Spoiler</summary>

* **Answer** : `Upper_Bound(key) - Lower_Bound(key)`.
* **Implementation** : See the last notation.
* **Explanation** :  
	* **Key Exists** : We can find the first occurrence of the key using `lower_bound(key)`. Obviously, we need to include this index in our answer. Then, we can find the first occurrence of the number just greater than key using `upper_bound`. Of course, we won't include this index in our answer. So, it becomes a closed open set, with length `upper_bound(key) - lower_bound(key)`. (By observation-2)
	* **Key Doesn't Exist** : The above formula would still work as `lower_bound` and `upper_bound` would point to the same element , hence the difference is zero as required.

</details>

<br></br>

### 2) Find the count of elements strictly less than key
* **Question** : How many elements are there with `ele < key`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `Lower_Bound(key)`.
* **Implementation** : `lower_bound(myVec.begin(), myVec.end(), key) - myVec.begin()`
* **Explanation** : We can find the occurrence of the first element greater than or equal to key. We don't need to include this index in our answer. Moreover, the `0-th` index is a part of the answer. So the answer is the length of the closed-open set `[0, lower_bound(key)]`. Hence, the result follows from observation-2.

</details>

<br></br>

### 3) Find the count of elements less than or equal to key
* **Question** : How many elements are there with `ele <= key`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `Upper_Bound(key)`
* **Implementation** : `upper_bound(myVec.begin(), myVec.end(), key) - myVec.begin()`
* **Explanation** : 
	* We can find the index of the first element strictly greater than key. We don't need to include this index in our answer. So we again form a closed-open set with `0` on the left end. Hence, the result follows.
	* An alternate explanation is to add the frequency of the key in the last answer. Can you see that the result now follows from simple algebra?

</details>

<br></br>

### 4) Find the count of elements strictly greater than key
* **Question** : How many elements are there with `ele > key`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `n - Upper_Bound(key)`.
* **Implementation** : `n - ( upper_bound(myVec.begin(), myVec.end(), key) - myVec.begin() )`
* **Explanation** : Solve for complements.

</details>

<br></br>

### 5) Find the count of elements greater than or equal to key
* **Question** : How many elements are there with `ele >= key`

<details>
	<summary>Spoiler</summary>

* **Answer** : `n - Lower_Bound(key)`
* **Implementation** : `n - ( lower_bound(myVec.begin(), myVec.end(), key) - myVec.begin() )`
* * **Explanation** : Solve for complements.

</details>

<br></br>

### 6) Find the number of elements in closed-open interval [low, high)
* **Question** : How many elements are there with ` low <= ele < high`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `Lower_Bound(high) - Lower_Bound(low)`
* **Implementation** : See the last notation.
* **Explanation** : Find the first occurrence of the first number bigger than or equal to the `low`. We need to include this in our set. Then, find the first occurrence of a number bigger than or equal to `high`. We need to exclude this index. We get a closed-open set and the result follows.

</details>

<br></br>

### 7) Find the number of elements in closed-closed interval [low, high]
* **Question** : How many elements are there with `low <= ele <= high`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `Upper_Bound(high) - Lower_Bound(low)`
* **Implementation** : See the last notation.
* **Explanation**
	* *Short Explanation* : Just add the frequency of `high` to the last result.
	* *Alternate Explanation* : Find the first occurrence of a number greater than or equal to `low`. We need to include this in our set. Then find the first occurrence of a number strictly greater than `high`. We need to stop our search here (excluding it). We again get a closed open set.

</details>

<br></br>

### 8) Find the number of elements in open-closed interval (low, high]
* **Question** : How many elements are there with `low < ele < high`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `Upper_Bound(high) - Upper_Bound(low)`
* **Implementation** : See the last notation.
* **Explanation** 
* **Explanation**
	* *Short Explanation* : Just subtract the frequency of `low` from the last result.
	* *Alternate Explanation* : Find the first occurrence of a number strictly greater than `low`. We need to include this in our set. Then find the first occurrence of a number strictly greater than `high`. We need to stop our search here (i.e, exclude this index). This time, we get a closed-open set and the result follows.

</details>

<br></br>

### 9) Find the number of elements in open-open interval (low, high)
* **Question** : How many elements are there with `low < ele < high`?

<details>
	<summary>Spoiler</summary>

* **Answer** : `Lower_Bound(high) - Upper_Bound(low)`
* **Implementation** : See the last notation.
* * **Explanation**
	* *Short Explanation* : Just subtract the frequency of `high` from the last result.
	* *Alternate Explanation* : Find the first occurrence of a number strictly greater than `low`. We need to include this in our set. Then find the first occurrence of a number greater than or equal to `high`. We need to stop our search here (i.e, exclude this index). This time too, we get a closed-open set and the result follows.

</details>

<br></br>

### Practice Problems

I'll update this section after a while. In the meanwhile, here's a question to test your skills.

* **Knight Tournament**

  * [Question Link](https://codeforces.com/problemset/problem/356/A)
  * **Hint** : Use the **set** container and try to do it in **O( n log(n) )**. (There's a catch, there are 2 `lower_bound` in STL. One which can act on any container and the other which is defined specifically for each eligible containers, such as `maps, sets` etc. However, one of them has complexity **O( log(n))** while the other takes **O(n)** time. Figure out which is which.)
  * If you are still stuck, you can go through this [blueprint](https://github.com/Just-A-Visitor/Wayback-Machine/blob/master/Course%20Preparation/Knight%20Tournament%20(Blueprint).cpp).
