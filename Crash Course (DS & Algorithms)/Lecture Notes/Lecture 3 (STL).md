<details>
  <summary>Motivation</summary>  
	
# Motivation   
This is probably the most important lecture of this course so far. Make sure you code (and submit) all of the example algorithms. This would ensure that you get familiar with **containers** and **C++** in general. From now on, try to incorporate **C++** in all the programs that you write. Need to scan an integer? Use `cin`. Need to create an array? Force yourself to use vector. Need global variables? Create a **class**. Need to iterate over a container? Use Range Based For Loops. The point is, almost all of the things can be done in **C**, but you should try it using the paradigms of C++. This would ensure that you would be able to use it fluently when the time comes. It's like when you learn to drive. No matter how much you read on the subject, the best experience that you can get is getting down on the road and driving by yourself.

With that said, you should maintain the curiosity of how these data structures are implemented internally. At some point in your life, you might need to tune the source code a bit. But, that's not gonna happen if you don't even know what's inside. I had planned to cover containers in the last class after we completed the theory. But, now that I think of it, we have limited time, and so I decided to cover the applications first so that the people who are sitting for placements (and others) might be able to practice questions during the mid-sem break. However, if you are planning to use these black boxes in interview, be prepared to answer questions on how are they implemented internally.     

---

</details>

<details>
  <summary>Headers</summary>  
	
# Headers
We will talk about headers later. For now, we'll just include `#include<bits/stdc++.h>` at the top of our file. This ensures that all the required headers are imported.

---

</details>


<details>
  <summary>Namespaces</summary>  
	
# Namespaces
They are basically used to handle name collisions. Suppose you define a function with the name `sort`. However, if you have included the above header, then there's already a function called `sort` which has been created by the developers of C++. What happens when you try to use `sort`. Which function should the compiler call? Actually, it will call the newly created function. Ok, but now you want to use the `sort` function of C++. How do you do this without changing your function's name? 

Well, that is why `namespaces` were defined. Almost every feature that you study in this lecture is included inside a `namespace` called `std`. This means that you'll have to use `std :: functionName` to use any containder. Of course, you need to use `std :: cin` and `std :: cout`. Since, this is too tiresome, we import the namespace in our program. We can just include a line `using namespace std` which implies that any unknown function that you used will be looked up in the `std` namespace.

_The answer to the first question_ : If you want to use the library sort, instead of your own, this time you would have to explicitly define the namespace. Use this `std :: sort`. 

---

</details>


<details>
  <summary>Input / Output</summary>  
	
# Input / Output
Once you switch to C++, it is very difficult to go back. Hence, before switching, take one last look at the old syntax and remember them. (You have to code in C in a couple of tests).

* How do you scan an integer in C? Well, you simply do `scanf("%d", &num)`. How do you print an integer? It's `printf("%d", num)`.  How do you scan and print a character, a float, a double or a long long integer? Well, just change the format specifier `%d` to `%c`, `%f`, `%lf`, `%lld`.
* What is the equiavalent notation in C++ ? Well, you can just do `cin >> variableName`. It does not matter what the data type of the variable is. It's universal.  
* String is a container in itself. We will talk about the input and output of strings under different section.
* To print a newline, you can either use `cout << endl` or `cout << 'n'`
* A common issue in C++ is scanning of whitespaces. While `%c` is designed to treat space as a single character, `cin` is engineered to ignore it. This is quite intuitive, since ideally you would want to neglect the spaces.

---

</details>

<details>
  <summary>A Minimal Working Example</summary>  
	
## A Minimal Working Example
[Playground](https://ide.geeksforgeeks.org/N4TfxWSMpB)

<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int smallNumber;
    long int bigNumber;
    long long biggestNumber;
    
    /* Note that int after long is optional */
    /* long long int is same as long long */
    
    // You can take input in one line too
    cin >> smallNumber >> bigNumber >> biggestNumber;
    
    // You can also print in one line. Take care of spaces manually
    cout << smallNumber << " " << bigNumber << endl;
    
    // Let us scan some character
    char firstChar, secondChar;
    
    cin >> firstChar >> secondChar;
    cout << firstChar << " " << secondChar << endl;
    
    return 0;
}
```   
</p></details>


---

</details>

<details>
  <summary>References</summary>  
	
# References
Remember the trick to swap 2 numbers in C? Well, that was quite messy. You needed to pass the pointer of the 2 numbers to ensure that the changes are reflected back. Here's a sample code.    
[Playground](https://ide.geeksforgeeks.org/lh5S704wje)

<details>
  <summary>Code</summary><p>
  
```cpp
#include <stdio.h>

void swap(int *a, int *b)
{
    // Make a backup of a
    int backup = *a;
    
    // Overwrite a with the value of b
    *a = *b;
    
    // Overwrite b with the backup
    *b = backup;
}

int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	printf("%d %d",a,b);
	return 0;
}
```   
</p></details>  

There are a couple of nuances that you need to remember here. First, you need to change the function arguments to include `*` everywhere. Then, you also need to use that messy star everwhere inside the function. Finally, you need to remember to pass the address of the variable denoted by `&a` while calling the function. Quite a lot of scope of error.  Moreover, how do you pass a copy of an array?

#### C++ to the Rescue
In C++, the concept is very simple. First, write the entire function as if you are passing a copy of the arguments. Then, if you need to reflect the changes outside, just write an `&` before the name of the arguments. Observe that you don't need to modify any code inside your function. Moreover, you also don't need to change the way you call your function. 

[Playground](https://ide.geeksforgeeks.org/CktduTG7sq)   
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

void swap(int a, int b)
{
    int backup = a;
    a = b;
    b = backup;
}

int main()
{
	int a = 1, b = 2;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
```
</p></details>  

Isn't that neat? The key takeaway in this discussion, you just need to insert one special symbol to ensure that changes are reflected back. Want more? C++ also has a function called `swap(,)` which takes as input 2 elements and swap them. And the interesting part is, it can even swap containers.  Here's an example which swaps 2 string containers.   
[Playground](https://ide.geeksforgeeks.org/dsi01frA8F)   
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string first  = "first";
    string second = "second";
    
    cout << first << " " << second << endl; 
    swap(first, second);
    cout << first << " " << second << endl; 
	return 0;
}
```
</p></details>  


---

</details>

<details>
  <summary>Class</summary>  
	
# Class 
C++ is an object oriented programming language and that is one of the key points which distinguishes it from C. If you know Java, you'll realize that Java is also an object oriented programming language, as everything in Java is an object which interact with each other on runtime. (Even `main` is an object). Although we won't go into all the functioalities of OOPs, we'll just cover some topics which would help us to write clean and error free code. The reall power of OOPs is visible when you try to write a working software. 

**Class** 
* A class is exactly what it means. It is a collection or a blueprint of an object. In the world, the set of all people is a class. This is because they share a similar functionalitiy such as the ability to talk, facial construction, etc. Although all people belong to the same class, they have diferrent properties which uniquely identifies them such as gender, voice, hairstyle, etc. Another example is the class of cars. Any particular car, such as BMW, Mercedes, etc is a part of this class. Although they share the same features, they are different in some aspect such as horsepower, cost, etc. 

**Instance Variables**
* A class can store some basic information of the object in the form of instance variables. For exapmle, hair color, eye color, etc is a defining feature of people. Hence, they are called instance variables. Similarly, the cost of a car can be considered as an instance variable.

**Methods**
* A class can have several functions associated with it. In the case of people, think of the different talents they have. In the case of animals, think of the sound they make. Although the name of the function `sound` is same for all the animals, the functioning is different. This gives us the flexibility to use the same name for different but similar functions.

**Objects**
* We say that an object is an **instance** of a class. It's like you have used the blueprint to create an actual human. There can several different objects of the same class in a single program. These 

**A New World**
* Whenever you create an instance of a class, that object starts living in a new world of its own. You can decide whether to interact this object with others or not. This is paritcularly useful in using gloabl variables. The general suggestion is that you should avoid using global variables as much as possible. _Why?_ This is because people tend to forget them to re-initialize thos variables if there are multiple cases.
 
 * Similarly, you should also avoid using **static**. This is because for each of the test case, you would want the function to be initialized once and updated the rest of the time. However, the issue with _static_ is that a particular line containing that keyword is run once for the entire program (and not once for each test case). Hence, you would end up using the answer of the last test cases instead of initializing it again. 

**Experimenting with static**    
[Playground](https://ide.geeksforgeeks.org/nmMO994yjb)   
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

void fun()
{
    static int a = 0;
    a++;
    
    cout << a << " ";
}

int main()
{
    for(int i = 0; i < 2; i++)
    {
        fun(), fun();
    }
    
    /*
    
    The expected answer is 
    1 2 
    1 2 
    
    But we get 
    1 2 
    3 4
    
    */
	return 0;
}
```
</p></details>  

During the class, someone had a question that if we call the function with a static line from 2 different functions, even then the static line is executed once for the entire program. (Which is logical). However, static works differently in classes. If you write a static line inside a function of a class, then it would only be executed when you create the first object of the class. (I think I was confused during the lecture whether it is called each time the object is initiated or just once. So please correct this in your notes. I have very less experience with using static :) ). Anyway, the point is, with classes and objects, you would never see the need to use static (which is a bit tricky concept). You should always try to use instance variables.    
[Playground](https://ide.geeksforgeeks.org/22oQohcEGs)   
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void fun();
};

void Solution :: fun()
{
    static int a = 0;
    a++;
    
    cout << a << " ";
}

int main()
{
    for(int i = 0; i < 2; i++)
    {
        Solution object;
        object.fun();
        object.fun();
        cout << endl;
    }
    
    /*
    
    The expected answer is 
    1 2 
    1 2 
    
    But we get 
    1 2 
    3 4
    
    */
	return 0;
}
```
</p></details>  

**Constructors**     
* Constructors are basically a function which defines how an object should look like when it is first instantiated. To call the constructor while creating an object, use `className objectName(....)` where `...` represents the constructor arguments.

**Scope**      
We have talked about the different worlds that classes create. To remove the ambiguity of which class we are referring to, there is the concept of scopes. When you write a function inside your class, you can either write the entire function with one level of indentation within the class, or you can define the function prototype inside and write the actual code outside it using scopes. See below examples.

**This Keyword**    
A common problem that arise while writing constructors is renaming variables.Suppose you have a class of cars with an instance variable called `color`. Now, you pass an argument to the constructor, naturally you would want to rename that variable as `color` because that's what it is logically. However, this creates a conflict in the name. When you try to print `color` in the constructor, which `color` should be printed (The answer is the local one, the one which was passed as an argument). The workaround to this is to use different name, say `shade` in the function parameter. and the do `color = shade`. But what if we don't want to keep thinkng up new names? This is where the **this** keyword comes in handy. If you keep the same name, then you can refer to the instance variable as `this->color`. Naturally, you can assign color by `this->color = color`.


**Linking All Together**    
* While declaring a class, don't forget the semi colon and the scope.
* For now, just make everthing public.
* Here is my code for the first question of the first programming assignment. You can see how I use constructors, scope, access instance variables, call functions, create new objects in each test case, get rid of gloabl variables, etc. Further, notice that I don't need to move the taken arrray and the reqWeight around.    

[Playground](https://ide.geeksforgeeks.org/16Nhlu0Qb4)

<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minCount;
    vector<int> a;
    vector<bool> taken;
    int n, reqWeight;
    
    // The constructor
    Solution()
    {
        minCount = INT_MAX;
    }
    
    void scanVector();
    void solve(int ind);
};

/* Demonstration of Scope */
void Solution :: scanVector()
{
    cin >> n;
    cin >> reqWeight;
    
    a.resize(n);
    taken.resize(n);
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void Solution :: solve(int ind)
{
    if(ind == n)
    {
        long long sum = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++)
            if(taken[i])
                sum += a[i], count++;
            
        if(sum == reqWeight)
            minCount = min(minCount, count);
        
        return;
    }
    
    taken[ind] = true;
    solve(ind + 1);
    
    taken[ind] = false;
    solve(ind + 1);
}

int main()
{
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
	    Solution object;
	    object.scanVector();
	    object.solve(0);
	    
	    if(object.minCount == INT_MAX)
	        cout << "impossible" << endl;
	    else
	        cout << object.minCount << endl;
	}
	return 0;
}
```
</p></details>  


---

</details>

<details>
  <summary>Pairs</summary>  
	
# Pairs
Pairs are one of the most wonderful features of C++. It helps you a lot when you want to return 2 different values from a function. By the way, how do you return 2 or more different values from a function without using pairs? (_Answer_ : Since you can return only one thing from a function, so before calling a function, create some variables to store the result. Now, pass the reference of these variables in the function and update them inside. This ensures that changes are reflected back and hence you have returned multiple values from a function). 

**Key Points**
* To define a pair, use `pair<int, int> myPair`. The first 2 data types can be anything. (not necessarily homogenous).
* Do generate a triplet, you can use `pair<int, pair<int,int>> myTriplet`. 
* The first element of a pair can be accessed via `myPair.first` notation and the second element can be accessed via `myPair.second` . Notice that there are no `()` because this is an instance variable and not a method. 
* To fill values in a pair, use `make_pair(firstVal, secondVal)`. The return type of this function is a pair of the desired type. Note that you can also use constructors while declaring a pair. See example below.
* Want more?  Pairs are well ordered. It means that you can sort a vector of pairs. Elements with smaller values of the `first` field are treated as smaller and if the `first` values are the same, then the `second` values are compared.

[Playground](https://ide.geeksforgeeks.org/mhkJM1t04y)
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // The constructor method
    pair<int, int> myPair(2,3);
    cout << myPair.first << " " << myPair.second << endl;
    
    // The Manual Method
    myPair = make_pair(1,2);
    cout << myPair.first << " " << myPair.second << endl;
    
    // A Triplet Method
    pair<int, pair<int,int>> myTriplet;
    myTriplet = make_pair(1, make_pair(2,3));
    cout << myTriplet.first << " ";
    cout << myTriplet.second.first << " ";
    cout << myTriplet.second.second << endl;
    
    /* Here's the interesting part. Pairs are well ordered */
    /* You can sort a vector of pairs. */
    /* It would sort by x first. If x matches, it would sort by y */
    
    vector<pair<int,int>> myVector;
    
    myVector.push_back(make_pair(1,3));
    myVector.push_back(make_pair(5,7));
    myVector.push_back(make_pair(2,9));
    myVector.push_back(make_pair(1,2));
    myVector.push_back(make_pair(2,6));
    myVector.push_back(make_pair(3,7));
    
    // Let's sort them and see what happens
    sort(myVector.begin(), myVector.end());
    
    // Print the vector
    cout << "Printing the sorted vector" << endl;
    for(auto ele : myVector)
        cout << ele.first << " " << ele.second << endl;
	return 0;
}
```
</p></details>  

---

</details>

<details>
  <summary>Iterators</summary>  
	
# Iterators (Introduction)
Iterators are a friendly version of _pointers_. A lot of people end up getting confused or doing segmentation faults with _pointers_. (Java is smart, it doesn't have any pointers). You can visualize an iterator as an arrow which points to a specific element. Note that the design of the arrow might not be the same for each data type. Visually, you would want the arrow of a string to be different from an arrow of an integer. Hence, each container has a different type of iterator. But, the best part is, most of the library functions in C++ are written so as to work on all types of iterators. Of course, an iterator makes no sense without a container. Hence, we'll study a container first and then come back to iterators. 

**Key Points**
* Why are iterators smart? It's because additon (and subtraction arithmetic work on them). It means that if you have an iterator `itr` pointing to the front element of the container, then doing `itr++` will give you an iterator to the second element of the container. (There's something called forward iterator and reverse iterator. The -- operator works on only reverse iterators). We will only be using the forward iterator, and hence you should never do `itr--`.
* For any container, `myContainer.begin()` gives you the an iterator to the front element. You can actually de-reference it and print the values. But the tricky part is that `myContainer.end()` doesn't give you an iterator to the last element of the array. It actually gives an iterator to the end of the container. Hence, you should never try to de-reference `myContainer.end()`.

---

</details>

<details>
  <summary>Vectors</summary>  
	
# Vectors
Vectors are on of the most amazing thing that you'll encounter in C++. It has such a wide range of applications. Vectors are essentially **dynamic arrays**, It means they can adjust their size as per the wish of the user. What more? You don't need to pass the length of an array to a function anymore. You can just pass a vector and deduce the size inside the function itself. 

**Key Points**
* You can declare a vectory by `vector<int> myVector`. Note that you can replace the `int` with `char` or any other data type (including `string` and `vector<int>`).  In fact, you can create a vector of any container that we are going to study. If you want to declare a vector of size `size` and use it like an array, you can do so by `vector<int> a(size)`.  This would also set the first n values to 0. Now, if you use `push_back(ele)`, the element would be inserted at the n+1th position. So, only use index
* You have 2 choices while declaring a vector. Either declare the size when you initiate the object or resize it dynamically. **Please do not mix them**.
* You can insert an element at the back in **O(1)** using `myVector.push_back(element)`.
* You can pop an element at the back in **O(1)** using `myVector.pop_back()`.
* Try not to pass the size of the array around unless absolutely necessary. You can use `myVector.size()` to get the size of the vector. This also works in **O(1)**.
* A very important function is `resize` which adjusts the vector to the desired size. The syntax is `myVector.resize(new_size)`. Note that if the vector was initially empty, it would be resized to behave as an array of length. What more? C++ would also put the default value 0 in all the `n` positions. Another important feature is that you can specify what to put as the default value in place of zero. The syntax is `myVector.resize(new_size, default_value)`

#### Iterating a Vector
We'll continue the discussion of iterators in context of vectors. There are basically 3 ways to iterate a vector.   

**First Method**
* Use the traditional method. Get the size of the vector and iterate it from `0` to `n-1` like an array. Note that a vector has all the functionalities of an array.

**Second Method**
* We can iterate it via iterators. Recall that an iterator is just a different kind of pointer, or an arrow pointing towards an element. If you want the value of that element, you need to de-reference it. You can do so by using `*`. To define an iterator, we can just write the container name along with the data type and then write an iterator in this scope. Then, we can give it a name. To define an iterator of `vector<int>`, we can just do `vector<int> :: iterator itr`. Here, `itr` is the name of the iterator. So, we keep iterating the container unitll we reach the end. Again, remember not to de-reference the end iterator.

**Third Method**
* We can use the **Range Based For Loop** similar to Python. The benefit of this is that we get direct view on the elements instead of an arrow pointing towards them. This means that we won't have to de-reference it. However, remember that you get a copy of the element. So, if you want to modify the elements, you'll have to use reference. The syntax is `for(int &ele : myVector)`. If you forget to write the reference, then you'll just get a copy.

### Automatic Type Deduction
One of the important features in C++ is the automatic type deduction. Sometimes, it might be a bit cumbersome to write `vector<int> :: iterator itr`. However, if you use `auto` while intialising an iterator, it will automatically deduce the type of the iterator. (This only works if you assign something to it the moment you declare it). Note that once assigned a type, the type of the iterator cannot change. The syntax is `auto itr = myVector.begin()`. It will automatically deduce that you are talking about an iterator defined in the scope of `vector<int>`. However, `auto itr;` is incorrect as you haven't initialized it. Moreover, `auto` can be used in any data types and is not limited to iterators. An example of this is the range based For Loops.

 
**Experimenting with the 3 Methods and the Auto Keyword**    
[Playground](https://ide.geeksforgeeks.org/Dhj8xNhTnx)
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Create an empty vector
   vector<int> myVector;
   
   // Fill 5 elements 
   for(int ele = 1; ele <= 5; ele++)
        myVector.push_back(ele);
    
    // Resize it to length 10 and fill remaining elements
    myVector.resize(10);
    for(int i = 5; i < 10; i++)
        myVector[i] = i + 1;
    
    /* Fill 5 more elements */
    for(int ele = 11; ele <= 15; ele++)
        myVector.push_back(ele);
    
    // First method
    for(int i = 0; i < myVector.size(); i++)
        cout << myVector[i] << " ";
    cout << endl;
    
    // Second method
    vector<int> :: iterator itr;
    for(itr = myVector.begin(); itr != myVector.end(); itr++)
        cout << *itr << " ";
    cout << endl;
    
    // Third Method
    for(auto ele : myVector)
        cout << ele << " ";
    cout << endl;
    
    // Modification of elements using third methods.
    // Notice the reference and auto keyword
    for(auto &ele : myVector)
        ele = -1 * ele;
    
    // A better version of second method
    for(auto itr = myVector.begin(); itr != myVector.end(); itr++)
        cout << *itr << " ";
    cout << endl;
	return 0;
}
```
</p></details>  

#### A Few More Functionalities
* `myVector.front()` gives you the starting element of the vector. `myVector.back()` gives you the ending element of the vector. Notice the difference with `begin` and `end`. Those give you iterators while these give you the value of these elements.
* `myVector.clear()` erases all the elements in the container. Of course, the time complexity is **O(n)**.
* You can also insert any element anywhere in the vector. However, insertion is not **O(1)**.  It is **O(n)**. To insert an element, you need an iterator before which the element should be placed. For example, to insert an element at the beginning of the container, you can do `insert(myVector.begin(), incomingValue)`.


---

</details>

<details>
  <summary>Dealing with Matrices</summary>  
	
# Dealing with Matrices
Passing matrices around in C is very tricky. You need to create a pointer to a pointer and allocate memeory using `malloc` and then move it around. You can find the working code below.    
[Playground](https://ide.geeksforgeeks.org/JJNOIXXXuQ)
<details>
  <summary>Code</summary><p>
  
```cpp
#include <stdio.h>
#include <stdlib.h>

/* Pass a 2D matrix to this function */
void fun(int **mat, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
	// Create a pointer to a pointer
	int **mat;
	
	int row, col;
	scanf("%d %d", &row, &col);
	
	// Allocate memory to rows;
	mat = (int **)malloc(row * sizeof(int *));
	
	// Allocate memory to columns
	for(int i = 0; i < row; i++)
	    mat[i] = (int *)malloc(col * sizeof(int));
	
	
	// Scan the matrix
	for(int i = 0; i < row; i++)
	    for(int j = 0; j < col; j++)
	        scanf("%d",&mat[i][j]);
	
	// Pass it to a function
	fun(mat, row, col);
	
	return 0;
}
```
</p></details>  

Okay, this works but is quite ugly. You need to move the number of rows and columns around along with using malloc.    
Well, in C++, you can just create a vector of vector and move it around with or without reference. You don't even need to pass the number of rows and columns. Plus, each row can have different number of columns.    
[Playground](https://ide.geeksforgeeks.org/MQeV2cJ7AX)
<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Pass a 2D matrix to this function */
void fun(vector<vector<int>> &mat)
{
    // Extract the row and columns
    int row = mat.size();
    int col = mat[0].size();
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
	// Create a vector of vector with 0 size
	vector<vector<int>> mat;
	
	int row, col;
	cin >> row >> col;
	
	// Create the row
	mat.resize(row);
	
	// Create the columns for each row
	for(auto &row_vec : mat)
	    row_vec.resize(col);
	
	/* Notice the reference above */
	
	
	// Scan the matrix
	for(int i = 0; i < row; i++)
	    for(int j = 0; j < col; j++)
	        cin >> mat[i][j];
	
	// Pass it to a function
	fun(mat);
	
	return 0;
}
```
</p></details>  


---

</details>

<details>
  <summary>Unordered Map</summary>  
	
# Unordered Map
An important container is `unordered_map`. You can visualize this as a black box which can perform a couple of operations in **O(1)**. They are : **Insertion, Searching, Size**. Moreover, with every key that you insert, you can (and should) also attach an associated value with it. The algorithm on which this black box works does not depend on the values. Hence, there are some restrictions as to what you can keep as your keys. When we insert a key with value `val`, we say that we are hashing the key with the given value. Notice that this doesn't allow duplicate keys. If you want to insert a key value pair `(2,3)` and then you want to insert another pair with same key, say `(2,5)`, then the final value associated with the key 2 would be 5. It simply means that duplicate keys are overwritten.  

**Warning** 
* Although the insertion and deletion is **O(1)** in average cases, in the worst case it might go upto **O(n)**. Now, in the class we had discussed that we should only consider the worst case time complextiy of an algorithm. So, why not here? The reasoning is quite simple, Worst case input of hash maps are rare given the number of queries. I would have to design well thought out test cases to ensure that happens. However, if you aren't doing Competitive Programming, then you can use it safely. And if you are too hesitant, use `map` which is introduced later.
* You cannot hash`pair<int, int>` in unordered_map. Use maps for that. Also, you cannot hash custom classes and structures (neither in ordered nor in unordered maps). However, you can place custom classes as a value in both of them. The only things which you can hash safely are integers, character, strings, and pointers. (Yes, you can hash the address of linked list nodes, and the address of the trees).

**Usage**
* To declare an unordered map, simply do `unordered_map<int, int> myMap`. The first data type is the type of key and the second one corresponds to the type of value.
* To get the number of keys, simply use `myMap.size()`.
* To search for an element, use the `find` function. It accepts as an argument the key, and returns an iterator to that element if that is present. (Of course, you can de-reference that iterator to get the value). If that element does not exist, it returns an iterator to the end of the container. `myMap.find(key) == myMap.end()` signifies that the key is not present. 
* To access the value of a key, first ensure that it is present using the above criteria. If it is present, you can simply do `myMap[key]` and this would give you the value. What more? You can also update the value of this key, Simply do `myMap[key] = newValue`.
* To insert a key value pair, simply do `myMap[key] = Value`. This would ensure the overwriting if the key is already present. 
* _Out of Bound Access_ : We should try not to access the value of the key which is not present. However, if we do so, we won't get segmentation fault. Instead we will get the default value which is zero. (Note that the size of hashmap doesn't change when you access illegal keys). Suppose, you need to insert keys in the hashmap, where the value represents the frequency in an array. If that key is not present, you want to insert it with a frequency of 1, else you want to increase the frequency (value) by 1. For each key, regardless of whether it is present or not, simply doing `myMap[key]++` does the job. Can you see why?
* To erase a key value pair , simply do `myMap.erase(key)`.
* The individual entries in the container are `pair`. The first element of the pair represents the key while the second pair represents the valule. Hence, when you iterate it via iterators, after de-referencing, you get a pair. Of course, you can also iterate it via the range based for loops.

**Experimenting with Maps**    
[Playground](https://ide.geeksforgeeks.org/lvC1kWBLIv)
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // A new to intialise vector
    vector<int> myVector = {1,1,1,2,2,3,5,5,5,5};
    
    unordered_map<int, int> myMap;
    
    // If not present, insert the element
    // If present, increment the count by 1 
    for(auto key : myVector)
    {
        // Not present, insert it
        if(myMap.find(key) == myMap.end())
            myMap[key] = 1;
        else
            myMap[key]++;
    }
    
    // First Way to traverse the map
    for(auto itr = myMap.begin(); itr != myMap.end(); itr++)
        cout << (*itr).first << " " << (*itr).second << endl;
    
    // Update the frequency of 3 from 1 to 2
    myMap[3]++;
    
    // Overwrite the frequency of 1 to 100
    myMap[1] = 100;
    
    // Erase the elment 5 from hash map
    myMap.erase(5);
    
    // Insert a new element with frequency 1 (Default Value -- 0)
    myMap[1234]++;
    
    /* Notice that 1234 doesn't exist yet
       but if you try to increment it, it comes to existence 
    */
    
    // Print the number of keys in the hash map
    cout << myMap.size() << endl;
    
    // Iterate the key value pairs in a clean Way
    for(auto ele : myMap)
        cout << ele.first << " " << ele.second << endl;
    
	return 0;
}
```
</p></details>  


---

</details>

<details>
  <summary>Maps</summary>  
	
# Map
There's not much of a difference betweeen unordered_map and map. While `unordered_map` provides insertion, deletion and searching in average **O(1)**, sometimes, it can blow up to **O(n)**. However, map (or ordered map) guarantees that the worst case complextiy would be **O(log (n))**. We have already seen that we can compromise a bit on **O(log (n))** and **O(1)** because the hidden constant factor in **O(1)** might be huge. Hence, you should generally use maps. Another benefit of maps is that it can store **pairs** as keys. The important property of maps is that it stores the key in a sorted order inside the black box. Hence, when you iterate the ordered map, you will get keys in sorted order. (Note that the values does not influence the internal algorithm of map).  Hence, you can use anything as values, including containers such as vectors. Moreover, the permissible keys that can be mapped are integer, pair of integers, (and not pair of custom class), character and strings. The strings are stored in lexicographical order. This gives us another method to sort `n` numbers. Insert them into a map along with frequency and then iterate the map and print any key `frequency` times. 

**Usage**
* To define a map, use `map<int, int> myMap`.
* Insertion, deletion, seacrhing, and size has same syntax as unordered_map.
* Iterating the map also has same syntax. The only difference is that now you'll get a sorted order of keys.
* To clear the container such as map and unordered map, use `myMap.clear`

[Playground](https://ide.geeksforgeeks.org/wmeAkEtGGI)
<details>
  <summary>Code</summary><p>
  
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // A new to intialise vector
    vector<int> myVector = {1,1,1,2,2,3,5,5,5,5};
    
    // Demonstrate
    map<int, int> myMap;
    
    // If not present, insert the element
    // If present, increment the count by 1 
    for(auto key : myVector)
    {
        // Not present, insert it
        if(myMap.find(key) == myMap.end())
            myMap[key] = 1;
        else
            myMap[key]++;
    }
    
    // First Way to traverse the map
    for(auto itr = myMap.begin(); itr != myMap.end(); itr++)
        cout << (*itr).first << " " << (*itr).second << endl;
    
    /* As you can see, the keys are in sorted order */
    
    // Update the frequency of 3 from 1 to 2
    myMap[3]++;
    
    // Overwrite the frequency of 1 to 100
    myMap[1] = 100;
    
    // Erase the elment 5 from hash map
    myMap.erase(5);
    
    // Insert a new element with frequency 1 (Default Value -- 0)
    myMap[1234]++;
    
    /* Notice that 1234 doesn't exist yet
       but if you try to increment it, it comes to existence 
    */
    
    // Print the number of keys in the hash map
    cout << myMap.size() << endl;
    
    // Iterate the key value pairs in a clean Way
    for(auto ele : myMap)
        cout << ele.first << " " << ele.second << endl;
    
    /* Let's create a map with pair as keys.
       We'll just set all values to 1 
    */
    
    
    cout << "Map of Pairs " << endl;
    
    map<pair<int,int>, int> pairMap;
    
    pairMap[make_pair(1,3)] = 1;
    pairMap[make_pair(5,7)] = 1;
    pairMap[make_pair(2,9)] = 1;
    pairMap[make_pair(1,2)] = 1;
    pairMap[make_pair(2,6)] = 1;
    pairMap[make_pair(3,7)] = 1;
    
    // Let's iterate over the map and print keys
    for(auto ele : pairMap)
        cout << ele.first.first << " " << ele.first.second << endl;
    
    /* As you can see, pairs are sorted by the order we defined */
    
    /* Let us clear the map */
    pairMap.clear();
    
    cout << "The size of map is " << pairMap.size() << endl;
	return 0;
}
```
</p></details>  


---

</details>

<details>
  <summary>Unordered Set</summary>  
	
# Unordered Set
Unordered_set is a smaller version of unordered_map. It just takes keys and no values. You can keep inserting duplicate keys in the set but the algorithm would determine that the key is duplicate and would ignore it without any warning. Note that, everything that can unordered_set can do can be done easily by Unordered_map by just using a dummy value for each node. Hence, in practice, you won't be using unordered_set much.  Of course, the time complexity analysis is exactly the same as unordered_map.

[Playground](https://ide.geeksforgeeks.org/S64TCKBwBK)
<details>
  <summary>Code</summary><p>
  
```cpp
/* Code borrowed from GFG */

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	// Declaring set for storing string data-type 
	unordered_set <string> stringSet ; 

	stringSet.insert("code") ; 
	stringSet.insert("in") ; 
	stringSet.insert("c++") ; 
	stringSet.insert("is") ; 
	stringSet.insert("fast") ; 
    
    // Let us insert a duplicate key
    stringSet.insert("code");
    
    // Let us search for a key
	string key = "slow" ; 
	if (stringSet.find(key) == stringSet.end()) 
		cout << key << " not found" << endl ; 
	else
		cout << "Found " << key << endl << endl ; 

	key = "c++"; 
	if (stringSet.find(key) == stringSet.end()) 
		cout << key << " not found\n" ; 
	else
		cout << "Found " << key << endl ; 

    // Let's iterate over the container
	unordered_set<string> :: iterator itr; 
	for (itr = stringSet.begin(); itr != stringSet.end(); itr++) 
		cout << (*itr) << endl; 
} 
```
</p></details>  


---

</details>

<details>
  <summary>Set</summary>  
	
# Set
You can consider set to be a trimmed down version of ordered maps. It also has some extra properties (such as `lower_bound` and `upper_bound`). Note that these 2 properties are also present in ordered map, but we seldom use. You'll be using sets quite frequently, so study this section carefully. A set can only accept keys but not values. It keeps the keys in sorted order and if you try to insert a duplicate key, it would quietly ignore it without making a fuss. 

**Properties**
* The syntax for creating a set is `set<int> mySet`. By default, the sorted order is ascending order. If you want to store keys in descending order, you can pass in an optional argument `set<int , great<int>> mySet`, or `set< pair<int,int>, greater< pair<int,int> > >  mySet`. We'll talk about `greater<int>` and comparators when we come to *heaps*. Note that `greater<...>` doesn't work for structs and custom classes.
* How do you erase an element from the set? You can either call `mySet.erase(key)` or `mySet.erase(iterator_of_key)`. But how do you get the iterator of a key? Use `set.find(key)`.
* All the basic opertions (excluding size) is **O(log (n))**
* Set also has 2 very interesting properties. `lower_bound(key)` returns an iterator to the first element of the container which is equal to `key`. If key is not present, it returns the iterator of the next element which is just greater than `k`. In case all elements are smaller than `k`, it returns an iterator to the end.
* `upper_bound(key)` returns an iterator to the first element of the container which is just greater than key. Not that it ignores element which is equal to `key`.  If all the elements are smaller or equal to `key`, it returns an iterator to the end. 
* To learn more about `lower_bound` and `upper_bound`, you can read [this]([http://www.cplusplus.com/reference/set/set/lower_bound/](http://www.cplusplus.com/reference/set/set/lower_bound/)) and [this]([http://www.cplusplus.com/reference/set/set/upper_bound/](http://www.cplusplus.com/reference/set/set/upper_bound/)). Don't worry so much about these 2 properties for now. Once you use them in a question, you'll get the hang of it.
* The above 2 properties also work in **O(log (n))**

[Playground](https://ide.geeksforgeeks.org/bMlUViRLzj)
<details>
  <summary>Code</summary><p>
  
```cpp
/* Example borrowed from GFG */

#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
	// A set with in descending order 
	set <int, greater <int> > gquiz1;		 

	// Insert elements in random order 
	gquiz1.insert(40); 
	gquiz1.insert(30); 
	gquiz1.insert(60); 
	gquiz1.insert(20); 
	gquiz1.insert(50); 
	gquiz1.insert(50); // only one 50 will be added to the set 
	gquiz1.insert(10); 

	// Printing set gquiz1 
    for(auto ele : gquiz1)
        cout << ele << " ";
	cout << endl; 

	// Assigning the elements from gquiz1 to gquiz2 
	set<int> gquiz2(gquiz1.begin(), gquiz1.end()); 
    
    /* This would also work */
    /* mySet.insert(myVector.begin(), myVector.end()); */
    
	// Printing set gquiz2 
    for(auto ele : gquiz2)
        cout << ele << " ";
	cout << endl; 

	// Remove all elements up to 30 in gquiz2 
	gquiz2.erase(gquiz2.begin(), gquiz2.find(30)); 
	cout << "\ngquiz2 after removal of elements less than 30 : "; 
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
		cout << '\t' << *itr; 

	// Remove element with value 50 in gquiz2 
	int num; 
	num = gquiz2.erase (50); 
	cout << "\ngquiz2.erase(50) : "; 
	cout << num << " removed \t" ; 
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
	{ 
		cout << '\t' << *itr; 
	} 

	cout << endl; 

	// Lower bound and upper bound for set gquiz1 
	cout << "gquiz1.lower_bound(40) : "
		 << *gquiz1.lower_bound(40) << endl; 
	cout << "gquiz1.upper_bound(40) : "
		 << *gquiz1.upper_bound(40) << endl; 

	// Lower bound and upper bound for set gquiz2 
	cout << "gquiz2.lower_bound(40) : "
		<< *gquiz2.lower_bound(40) << endl; 
	cout << "gquiz2.upper_bound(40) : "
		<< *gquiz2.upper_bound(40) << endl; 

	return 0; 

} 
```
</p></details>  


---

</details>

<details>
  <summary>Sorting</summary>  
	
# Sorting
We have seen how to sort n numbers in **O(n log(n))**. Although the code of merge sort is very easy, it is not possible to write the entire code everytime. C++ provides a library function which can sort linear containers. To Sort a vector, you can use `sort(myVector.begin() ,  myVector.end())`. To sort an array, you can use `sort(arr, arr + n)` because array is not a container as such. To sort a string which a container, use `sort(str.begin() , str.end())`.



---

</details>


<details>
  <summary>Boolean Data Types</summary>  
	
# Boolean Data Types
C++ also has boolean data types (and so does C). Try to use them instead of using 0 or 1.    
The syntax is `bool newVar = true` and `bool newVar = false`.

---

</details>

<details>
  <summary>The Clutter of and / or</summary>  
	
# The Clutter of `and` `or`
C++ also has 2 reserved keywords, namely `and` , `or`. Try to use them in place of `&&` and `||`. Not that it makes a difference, it just makes the code look more clean.


---

</details>

<details>
  <summary>Reverse Function</summary>  
	
# Reverse Function
Like swap, C++ also has a function which can reverse any linear container (i.e, vector and string). The syntax is `reverse(str.begin() , str.end())` and `reverse(myVector.begin() , myVector.end())`.


---

</details>

<details>
  <summary>Examples</summary>  
	
# Examples
1) **Remove Duplicates** : 
	* The task is to remove duplicates from an array. One approach that works in O(n^2) is to pick each element, traverse the array and set the other copies to infinity. Simulataneously, place this single element at the back of a vector. At the end, the vector would contain all the unique elements.
	* Another approach is to use sorting. Sort the array, and then all duplicates would come together. Extract them in a new vector. **O(n log(n))**
	* A yet another approach is to insert all the elements in a set and take them out. This would ensure that duplicates are removed. **O(n log(n))**
	* A final approach which also maintains the order of appearance is to start hashing the elements one by one. If the element is already hashed, don't do anything. If it is not hashed, store it at the back of a vector and also hash it. At the end, the vector would have unique elements in the same order of appearance.  **O(n)**

2) **Count Frequency of Each Element**
	* An **O(n^2)** approach is to pick any element, count its frequency, store the answer in a vector of pairs and set all copies to infinity. Repeat for all the elements. At the end, vector would contain the answer.
	* Another approach is to sort the elements. Now, all duplicates are clubbed together. You can find the frequency in one traversal. **O(n log(n))**.
	* A yet annother approach is the following. Map each value in the array to its frequency. (i.e keep updating frequency whenever you see an element). In the end, traverse the hashmap and you'll have the key frequency pair. **O(n)**
3) **A Data Structure that supports Insert, Delete, getRandom in O(1)**
Note that all incoming elements are distinct.
	 * Create an empty vector and keep inserting elements at the back. Simultaneously, keep updating a map with key as incoming number and value as the index in the array. 
	 * As soon as a deletion query comes, look up the index of the element from the hashmap. If it is not present, do nothing. If present, go to that index in the vector. Swap that element with the last element of the vector and pop the last element. This is O(1). Finally, remember to erase the key from hashmap.
	 * For getRandom, extract the size of the vector. Generate a random number and take it modulo `size`. This would give you a number between `0` and `size - 1`. Just return the element at that index. Note that this ensures that each element has equal probability of being returned.
