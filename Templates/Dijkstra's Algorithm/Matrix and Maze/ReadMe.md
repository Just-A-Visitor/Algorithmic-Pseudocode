# Random
What do I say about this? I've been waiting for almost 7 months to code
this and finally I've completed the target. It always appeared to me that
as simple as **Dijkstra** is on paper, it would be a nightmare to
implement it. Guess, I was wrong! The implementation couldn't have been
easier. Thanks Hitesh for pushing me to solve this! Got to learn a lot of
new techniques.

---

# Class vs Pair<pair<pair.....>>
Intially, I hated making **structures** and the respective custom
comparators.
For example, if I wanted to create a triplet, I'd do `pair<int,
pair<int,int>>`. This works, but makes the code quite messy.
The sole reason for sticking to **pairs** was that you didn't have to
design a custom comparator or a **make_pair** function.
Now I've realized that all the above benefits can be taken by creating a
**class** or **structure**.

For a triplet, now I'd just do
```cpp
class Triplet
{
    int dist;
    int x_cord;
    int y_cord;
}
```

How to replace the **make_pair** function ? Simply create a constructor
```cpp
void Triplet :: Triplet(int dist, int x_cord, int y_cord)
{
    this->dist = dist;
    this->x_cord = x_cord;
    this->y_cord = y_cord;
}
```
As simple as that!
To instantiate an object, just call `Triplet(dist,x_cord,y_cord)`

How to replace the inbuilt comparators? Just include this in the class itself
```cpp
{
    bool operator <(const Triplet &biggerNode) const
    {
                return dist < biggerNode.dist;
    }
}
```
**Remark** ===> There's a slight modification to be made in the above
code. Refer down.

The benefit? You get to keep your own name such as `dist`, `x_cord`,
`y_cord` instead of `first`, `second`.

---

# Custom Comparators
I spent almost an hour debugging this, so it definitely demands a separate
section.

First of all, recall that a custom comparator should return true if the
first argument is less than the second, essentially behaving like
`lesser`.
In this setting, when we over-ride the `bool operator <`, the first
argument is the current object of the class. (Hence, I renamed the input
argument to **biggerNode**).

**Tip** ---- Don't forget the `const` at the end!
Intially, my comparator looked like this
```cpp
{
    bool operator <(const Triplet &biggerNode) const
    {
                return dist < biggerNode.dist;
    }
}
```
So, this will return **True** if the current object is smaller than the
argument passed!

But, this has some flaws!
This clearly doesn't specify which element is smaller if the condition
fails? This was casuing unexpected error.

**The Real Code**
```cpp
{
    bool operator <(const Triplet &biggerNode) const
    {
        if(dist==biggerNode.dist)
            {
            if (x_cord != biggerNode.x_cord)
                return x_cord < biggerNode.x_cord;
            else
                return y_cord < biggerNode.y_cord;
            }
                return dist < biggerNode.dist;
    }
}
```

As you can see, all the cases are handled explicitly.
All credits goes to [GFG]() for helping me debug this!

The benefit ?
* **GFG** usually creates a boolean function and pass it around. However,
with classes, you can simply declare it inside and never worry again.
* If you want to sort, just do `sort(triplet_vec.begin(), triplet_vec.end())`
* If you want to sort in the reverse manner, just flip the signs in the
comparators.

---

# The Legal Function
I cannot emphasize how many times this function has saved me from
segmentation faults. Now I just call this function before accessing the
element and sleep in peace!
And yeah, you guessed it, [GFG]() is responsible here too.

---

# Travelling Cardinal Directions
I learnt this trick recently. (This was from [LeetCode]()). This is a
pretty cool technique to perform similar operation on the neighbours.
I've written the template for cardinal direction in a different post.

---

# Dealing with Infinities
The main roadblock for me while dealing with **Dijkstra** was the fact
that during **Edge-Relaxation**, we compare the `deltas` to `other_delta +
weight`. Moreover, we also initialize all `deltas` as **infinity**  or
**Int_Max**. The issue with that is the fact that when we add something to
**Int_Max**, it actually becomes negative and the comparison would give
wrong results. One solution is to use infinity as **1e7** or a slightly
smaller number. This ensures that it doesn't become negative while
comparing. However, this creates a problem. What if the sum exceeds
**1e7**. This would give wrong results.

[GFG]() has a nice trick to avoid this problem. Refer below!

---

# Algorithm

* Create the structure to hold the triplets. This will store a particular
cell, (`x` and `y` co-ordinate and the `delta` value as mentioned in
**CLRS**).
* Create a normal comparator (not the reverse one) and constructor for the
class
* Define the cardinal directions, set the value of **infinity** and create
an empty set to hold triplets.
* Create another identical matrix to hold the hold the **delta** values.
(Yes, the set also holds the delta values, but this matrix will give us
constant time access).
* Intialize this matrix with **infinity** (Standard CLRS stuff).
* Update the `delta` value of cell (0,0) in the **delta** matrix. Push it
in the set too.
* **A very important invariant**  ===> Maintain an invariant that no element
whose `delta` value is infinity goes inside the set, This ensures that
during relaxation, the `delta` in which the weight is added has come from
the set itself, so of course, no overflow can happen. Even if the
comparison is with **infinity**, it would be on the left side.
* While the set does not become empty, do
    * Remove and store the minimum element by `delta` value. (The
beginning iterator of set).
    * Explore all its neighbours and perform edge relaxation on all of
them. If edge relaxation succeeds, it means it's time to update the
`delta` of that neighbbour. This is a tricky part, and I spent almost
half an hour debugging this.
    * First of all, **Check if the neighbour is present in the set. A
smart way is to check if the `delta` value is infinity or not. If it
is not, it must be in the set.**
    * Do not blindly delete an element if it is not present. This caused
me a lot of trouble.
    * After you've deleted the element (if present, just push the neighbor
with the updated delta values).
    * Update the delta values in the matrix too.
* Return the delta value of the bottom right cell.

---

# Miscellaneous
I've said that if the delta value is not **infinity**, it must be present
in the set. Is that always true? If you think about it deeply, no. A
simple counter example is the fact that at the end all the delta values
are not **infinity** and yet the set is empty. What's the catch?
The catch is that the above statement is only valid for cells which pass
the edge relaxation criteria. Ponder over it. If a non infinity delta
value passes the test, it has to be in the set. Of course, at the end, no
one will pass the relaxation test and hence they are not in the set.

---

# Credits
The theory, **CLRS**. To be honest, I did write 90% of the code all by
myself and took the help of **GFG** only at the end for debugging. Funnily
enough, our codes turned out to be almost similar.


