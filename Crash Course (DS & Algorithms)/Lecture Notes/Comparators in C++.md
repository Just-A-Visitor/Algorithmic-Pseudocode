<details>
  <summary>Introduction</summary>  
	
# Introduction
Comparators are an inherent part of _class_. Suppose you design a new class, and then you instantiate 2 new objects of this class. Now, we ask the question, _which object is bigger among the two?_ The Notion of Big and Small varies. For example, we can say that the object with a larger value of a specific instance variable is big, or even, the object with a larger memory consumption is big. Notice that without any certain ordering between 2 elements, we cannot talk about the sorted order of these elements. (As that would require finding out the smallest and biggest elements from the entire set). 

---

</details>

<details>
  <summary>Structures Vs Class</summary>  
	
# Strucutures vs Class
When you need to create your own data types, generally _structures_ suffice. However, there is no harm in using _classes_ to achieve the same task. Since we've only covered _classes_, we will base the entire discussion on it. However, keep in mind that everything can be equally applied to _structures_ as well. The bottomline is, if you want to create a new data type (containing heterogenous fields), you should use _class_ and if you are planning to deal with pointers a lot, use _structures_ as you are already familar with it.

---

</details>


<details>
  <summary>The Default Comparator</summary>  
	
# The Default Comparator
Numbers are represented as bits in the computer. We've been using numbers a lot (along with their comparisons, such as `>`, `<`, `==`). To define their relative ordering, we have the concept of a comparator. **A comparator is a function which takes 2 objects as an argument and returns True if the first argument is smaller than the second, else it returns False**.  (Notice that the order of arguments matter a lot).

So now, we need to tell the computer that `2 < 3`. How do we do this? Lucky for us, there is a default comparator in C++ which does the job. The **default** comparator is `lesser<int>`. Let us talk about what this is. First of all, `lesser<int>` is a function with a boolean return value. So far, we have only talked about the notation `<...>` in the context of containers. What does this symbol mean in terms of function? Well, it means the same. In containers, this notation was used to make the containers universal and accomodate any data type. You just needed to put the name of the data type inside `<...>`. It is the same thing as functions, it is written as a universal function which can accept any data type and perform the same type of operations on that data type. Makes sense, right? Because if you are creating a function that returns the absolute value, you wouldn't create a bunch of functions with different names. Rather you would want to create a function which can take `int`, `long int`, `long long int`, `float` , etc and just return the absolute value of these arguments. Hence, the data type of the input needs to be made universal. This is called **Templates** in C++.

**Caution** : Comparators are not exactly functions, as it is wrapped over a class. But, to keep the discussion less technical, we'll just assume that they are normal functions.

Coming back to `lesser<int>`. As you might have guessed by now, this is a function which takes as an input 2 arguments `(first, second)` and returns true if the first argument is lesser than the second. Else, it returns false. The most important thing is the ordering of the arguments. If you called the function for the arguments `(second, first)`, naturally you would want to get the reverse results.

Similarly, there is a function called `greater<int>`. As you might have guessed by now, this function would return true if the first argument is greater than the second. 

**Default Comparators**    
By default, C++ uses `lesser<int>` to compare 2 numbers. Hence, to know which of the numbers `7,5` is smaller, it would call `lesser(7,5)` and get the answer `false` which means `5` is smaller. Similarly, if it had accidentally called `lesser(5,7)`, it would get the answer `true` and it would still conclude that `5` is smaller. 

**Tricking the Computer**    
C++ would **always** expect the comparator to behave as `lesser<int>`. Hence, no matter what comparator you desgin, if you return `true` from that comparator, C++ would automatically think that the first argument is `smaller`. (As it would  expect it to behave as `lesser<int>`). Using this idea, how do we trick the computer to sort the numbers in descending order? Suppose, there was a way to change `lesser<int>` to any other function that you want. Can you do it now? Yes, we can just replace it with `greater<int>`. Now, when C++ calls the comparator with the arguments `(7,5)` , it would get the answer as `true`. Hence it would assume `7 < 5` (as we discussed earlier). Similarly, if it accidentally calls the comparator on `(5,7)`, it would get `false`. It would still conclude that `7 < 5`. I hope you see the underlying trick here. We have fooled the computer into believing that numbers with large magnitude should be seen as smaller numbers. Hence, in the sorted order, we'll have the largest number first (as the computer thinks it to be the smallest number). In this manner, we can sort it in descending order.

Now, recall the **Merge Sort** algorithm. While manually merging the 2 sorted array, there was just one instance where we used `<`. So, if we want to sort custom objects, we need to clarify what is meant by one object being `<` than the second. There are 2 options, either include this as a blueprint in the source code of your object or pass an overloaded optional third parameter to the **sort** function. We'll discuss what the first option means. But for the second option, we just need to create a function that returns `true` when the first arguments is `greater` than the second (to imitate the reverse of `lesser<int>`). If we pass this optional parameter, all usage of `lesser` would be replaced by this function. Here's an example with numbers.    
[Playground](https://ide.geeksforgeeks.org/lxIMuLVyov)
<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Demonstrating Comparators for Sort Function */

void printVector(vector<int> &myVec)
{
    cout << "Printing the contents of the vector" << endl;
    for(auto ele : myVec)
        cout << ele << " ";
    
    cout << endl << "Done" << endl;
}

/* It should return true if you say a to be smaller */
bool personalComparator(int &a, int &b)
{
    // We actually want to say the element with large value is smaller
    if(a > b)
        return true;
    else
        return false;
}
int main()
{
    vector<int> myVec = {5,3,9,4,8,1,6,4,5,7,0};
    printVector(myVec);
    
    // Let's sort it in ascending order
    cout << endl <<"Sorting in ascending order " << endl;
    sort(myVec.begin(), myVec.end());
    printVector(myVec);
    
    // Let's replace the default comparator with our own
    cout << endl <<"Sorting in descending order " << endl;
    sort(myVec.begin(), myVec.end(), personalComparator);
    printVector(myVec);
	return 0;
}
```   
</p></details>

Ok, what about structs and classes? The process is same. Here's an example.    
[Playground](https://ide.geeksforgeeks.org/wsydcTLuh9)

<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Note that if you aren't dealing with pointers,
   it is a good idea to do everything with class */    

/* Definiton for struct */
struct S_Node
{
    int data;
    char myChar;
};

/* Comparator for the struct object */
bool structComparator(struct S_Node &first, struct S_Node &second)
{
    // The object with big data is smaller
    if(first.data > second.data)
        return true;
    else
        return false;
}

/* Blueprint for the class */
class C_Node
{
    public:
    int data;
    char myChar;
};

/* Comparator for the class object */
bool classComparator(C_Node &firstObject, C_Node &secondObject)
{
    // The object with small data is smaller
    if(firstObject.data < secondObject.data)
        return true;
    else
        return false;
}

/* Utility function to print structs */
void printStruct(vector<S_Node> myVec)
{
    cout << endl << "Printing the struct " << endl;
    for(auto ele : myVec)
        cout << ele.data << " ";
    cout << "Done " << endl;
}

/* Utility function to print structs */
void printClass(vector<C_Node> myVec)
{
    cout << endl << "Printing the class " << endl;
    for(auto ele : myVec)
        cout << ele.data << " ";
    cout << "Done " << endl;
}
int main()
{
    // Let us create a vector of structs
    vector<S_Node> structVec;
    
    for(int i = 1; i <= 10; i++)
    {
        S_Node temp;
        temp.data = i;
        temp.myChar = 'a';
        
        structVec.push_back(temp);
    }
    
    // Let us create a vector of structs
    vector<C_Node> classVec;
    for(int i = 1; i <= 10; i++)
    {
        C_Node temp;
        temp.data = i;
        temp.myChar = 'a';
        
        classVec.push_back(temp);
    }
    
    // Let us sort the struct in descending order 
    sort(structVec.begin(), structVec.end(), structComparator);
    printStruct(structVec);
    
    // Let us sort the class in ASCENDING order
    sort(classVec.begin(), classVec.end(), classComparator);
    printClass(classVec);
	return 0;
}
```   
</p></details>

So now, you can create a custom structure / class and sort it in any manner that you want. 

---

</details>


<details>
  <summary>Containers and Comparators</summary>  
	
# Containers and Comparators
Every container has an optional argument that can over ride the default comparator. For example, if you want to create a set which is sorted in reverse manner, you'd need to write `set<int, greater<int>>`. This just tells the function to use `greater<int>` instead of `lesser<int>` which reverses the behaviour. A word of caution ---- The third parameter in the **sort** function was a function, with a boolean return type. However, with containers, the scenario is different. The optional parameter is a class which hides the boolean function. So, to create your own comparators to pass into a container, declare a class of any name, and inside that class, write **public** function by the name `operator()(firstArgument, SecondArgument)`. Notice the syntax. This is a boolean function. Of course, the arguments are the reference to the objects. Inside the function, you can do everything that we did with sort comparators. Here's an example.    
[Playground](https://ide.geeksforgeeks.org/zWve97w3H4)    
<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Blueprint for the class */
class custom_class
{
    public:
    int data;
    char myChar;
};

/* Comparator for container */
class MyComparator
{
    /* Don't forget the const and public keyword */
    public:
    bool operator()(const custom_class &firstObject,  const custom_class &secondObject)
    {
        // The object with big data is smaller
        if(firstObject.data > secondObject.data)
            return true;
        else
            return false;
    }
};

/* Utility function to print class */
void printClass(vector<custom_class> myVec)
{
    cout << endl << "Printing the class " << endl;
    for(auto ele : myVec)
        cout << ele.data << " ";
    cout << "Done " << endl;
}
int main()
{
    // Let us create a vector of class
    vector<custom_class> classVec;
    for(int i = 1; i <= 10; i++)
    {
        custom_class temp;
        temp.data = i;
        temp.myChar = 'a';
        
        classVec.push_back(temp);
    }
    
    // Let's add some duplicates
    custom_class temp;
    temp.data = 2;
    temp.myChar = 'a';
    classVec.push_back(temp);
    
    temp;
    temp.data = 5;
    temp.myChar = 'a';
    classVec.push_back(temp);
    
    // Let us print the class and see the contents
    printClass(classVec);
    
    // Let's create a set that can store the objects in descending order of data
    
    /* Syntax --- set<newDataType, ComparatorClass> mySet */
    
    set<custom_class, MyComparator> mySet;
    
    // Fancy way to insert elements into a set :)
    mySet.insert(classVec.begin(), classVec.end());
    
    // Let's iterate the set and see what happens
    cout << "Printing the set" << endl;
    for(auto ele : mySet)
        cout << ele.data << " ";
	return 0;
}
```   
</p></details>

Yes, you can also create priority queue with this comparator. There's just one little change in syntax. In priority queue, you need to specify the container that you wish to use. So, to create min heaps, you would use `priority_queue<int, vector<int>, greater<int>> minHeap`. The first argument contains the data types, the second argument contains the container name, and the third argument is the comparator class. While defining heaps on custom class, use this syntax, `priority_queue<custom_class, vector<custom_class>, Comparator_class> myHeap`. 

Be careful with what you expect out of heaps. Heaps will always give you the object which you call the biggest. Hence, by default, you get max heap. However, if you switch to `greater<int>` , you'd call the smallest value the biggest and hence you can extract the minimum element from the heap.

Here's an example demonstrating custom heaps.    
[Playground](https://ide.geeksforgeeks.org/fEqVWFbd7g)
<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Blueprint for the class */
class custom_class
{
    public:
    int data;
    char myChar;
};

/* Comparator for container */
class MyComparator
{
    /* Don't forget the const and public keyword */
    public:
    bool operator()(const custom_class &firstObject,  const custom_class &secondObject)
    {
        // The object with big data is smaller
        if(firstObject.data > secondObject.data)
            return true;
        else
            return false;
    }
};

/* Utility function to print class */
void printClass(vector<custom_class> myVec)
{
    cout << endl << "Printing the class " << endl;
    for(auto ele : myVec)
        cout << ele.data << " ";
    cout << "Done " << endl;
}
int main()
{
    // Let us create a vector of class
    vector<custom_class> classVec;
    for(int i = 1; i <= 10; i++)
    {
        custom_class temp;
        temp.data = i;
        temp.myChar = 'a';
        
        classVec.push_back(temp);
    }
    
    // Let's add some duplicates
    custom_class temp;
    temp.data = 2;
    temp.myChar = 'a';
    classVec.push_back(temp);
    
    temp;
    temp.data = 5;
    temp.myChar = 'a';
    classVec.push_back(temp);
    
    // Let us print the class and see the contents
    printClass(classVec);
    
    // Let's create a min Heap
    
    /* Syntax --- priority_queue<custom_class, container, class_comparator> */
    // Note that internally, heaps need some container to work on 
    
    // Let us create a priority queue 
    priority_queue<custom_class, vector<custom_class>, MyComparator> pq;
    
    // Insert all element into the priority queue
    for(auto ele : classVec)
        pq.push(ele);
    
    // Let us see the top element
    cout << "The top element has data ";
    cout << pq.top().data << endl;
    
    cout << "We successfully created a min Heap";
	return 0;
}
```   
</p></details>

---

</details>


<details>
  <summary>Making our lives Simpler</summary>  
	
# Making our lives simpler
To create custom containers, there is a lot of work involved. You need to create a new class, put a new function, remember the difference in the syntax between `priority_queue` and `set`, etc. Plus, we still don't know how to implement custom maps. 

Let's think about this a bit. When you create a container of integers, do you do all this? No, right! This is beacause all the comparators are already hidden inside the integers. Hence, we don't have to worry about them. Can we do the same for objects? Can we inject something in the blueprint of the object so that compiler would treat it as integers. If so, than our lives would become much simpler. Turns out, there is such a way and I'll let you in on this secret in a few moments.

In Java, there is one superclass, and every class inherits from it. What's more, you can also over ride the inherited functions. In C++, when defining any class, there is a hidden boolean function called `operator<` which takes a single parameter and determines whether the current object of the class is smaller than the incoming object. This is the default comparator. If you write this function precisely, then you won't have to use comparators with this class, not even in sorting. To sort, you can just do `sort(customVec.begin(), customVec.end())`. To create a set, jsut do, `set<customClass>`. To create heaps, just do `priority_queue<cusomClasss>`. To create maps, just do `map<customClass, ValueDataType>>`. As you can see, we can now use it like any other data type because we have embedded the comparator in the blue print. So, all that remains is to modify the blue print.

To do so, just create a public function with this template
```
boool operator < (const &IncomingObject) const
{
	// Return true if you see current object is smaller than incoming one
	// Don't forget to return false explicitly if it is bigger or equal
}
```

**Notice the extra const at the end. Weird syntax, but it is what it is**

Although it looks like it takes 1 argument, it actually takes 2 under the hood. It's just like `lesser<int>`. So now, we want to know what is the first argument and what is the second argument. (Remember, the ordering matters a lot). Well, it turns out, that **The first argument is the object of the class that you are currently standing at and the second is the incoming object**. Hence, the comparator expects that if the object that you are standing at is smaller than the incoming object, then it is your duty to return true. Now, how to access the instance variables of the object that you are standing at? It's simple. Either use `this->VariableName` or just use `instanceVariableName` . This is because there is no name collisons and we don't really require `this`. How to access the variables of incoming object? Use the dot notation. 

After we are done, we don't have to worry about using any function / container which uses ordering. This is the template that I use (and prefer). It's not as difficult as it seems

---

</details>


<details>
  <summary>Final Demonstration</summary>  
	
# Final Demonstration   
[Playground](https://ide.geeksforgeeks.org/1RpuheKTFO)
<details>
  <summary>Code</summary><p>
  
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Blueprint for the class */
class custom_class
{
    public:
    int data;
    char myChar;
    
    // Embed it in the Blueprint
    public:
    bool operator<(const custom_class &incoming)const
    {
        // The object with big data is smaller
        if(data > incoming.data)
            return true;
        else
            return false;
            
        /* If it returns true, it means that the current object has bigger data
           and ideally we would want to call it small */
        
        /* Remember the rule, True implies that you are viewing the first argument
           as smaller */
    }
    
};

/* Utility function to print class */
void printClass(vector<custom_class> myVec)
{
    cout << endl << "Printing the class " << endl;
    for(auto ele : myVec)
        cout << ele.data << " ";
    cout << "Done " << endl;
}
int main()
{
    // Let us create a vector of class
    vector<custom_class> classVec;
    for(int i = 1; i <= 10; i++)
    {
        custom_class temp;
        temp.data = i;
        temp.myChar = 'a';
        
        classVec.push_back(temp);
    }
    
    // Let's add some duplicates
    custom_class temp;
    temp.data = 2;
    temp.myChar = 'a';
    classVec.push_back(temp);
    
    temp;
    temp.data = 5;
    temp.myChar = 'a';
    classVec.push_back(temp);
    
    // Sorting is easy
    sort(classVec.begin(), classVec.end());
    
    // Let us print the class and see the contents
    // It should be sorted in reverse manner
    printClass(classVec);
    
    // Let us create a priority queue 
    priority_queue<custom_class> pq;
    
    // Insert all element into the priority queue
    for(auto ele : classVec)
        pq.push(ele);
    
    // Let us see the top element
    cout << "The top element has data ";
    cout << pq.top().data << endl;
    
    cout << "We successfully created a min Heap";
    
    // Ok, Let us create sets
    set<custom_class> mySet;
    
    mySet.insert(classVec.begin(), classVec.end());
    
    // Let's iterate the set and see what happens
    cout << "Printing the set" << endl;
    for(auto ele : mySet)
        cout << ele.data << " ";
        
	return 0;
}
```   
</p></details>

---

</details>


<details>
  <summary>Practice Problems</summary>  
	
# Practice Problems
Here's some of the problems that made me learn the power of comparators.

1) [Rearrange a string such that no two adjacent elements are same]([https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/](https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/))   
	[My Code](https://ide.geeksforgeeks.org/p2pKceKwpG)
	
2) [Flattening a Linked List]([https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1))    
 [My Code](https://ide.geeksforgeeks.org/8kg2MfphRV)

3) [Median in a stream of Integers]([https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0](https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0))    
	[My Code](https://ide.geeksforgeeks.org/HUEAT1ihsl)    
Don't worry so much about the comments in the code. I was actually experimenting with the techniques at that time. Feel free to use any method that you feel comfortable with.


Lastly, Two problems to help you practice     
[Activity Selection](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0)    
[Shrinking Space](https://www.codechef.com/problems/SPACE)
