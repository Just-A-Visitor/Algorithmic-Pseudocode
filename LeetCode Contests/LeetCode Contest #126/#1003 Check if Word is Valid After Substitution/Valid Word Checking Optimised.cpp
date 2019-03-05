#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string str);
};

class specialStack
{
    public:
    stack<char> mainStack;
    char secondElement = '#';
    
	// While pushing the element, update the second element, if it exists
    void push(char key)
    {
        if(!mainStack.empty()) secondElement = mainStack.top();
        else secondElement = '#';
        mainStack.push(key);
    }
    
    // While popping, update the secondElement
    void pop()
    {
        mainStack.pop();
        if(mainStack.empty()) secondElement = '#';
        else
        {
            char topElement = mainStack.top();
            mainStack.pop();
            push(topElement);
        }
    }
};

bool Solution :: isValid(string str)
{
	// Create a special stack named wrapper
    specialStack wrapper;
    
	// Traverse the string and keep deleting 'abc' in O(1)
    for(auto ele:str)
    {
		// If the character is 'c', pop the matching 'b' and 'a' from the stack, if they exist 
        if(ele!= 'c' || wrapper.mainStack.empty()) wrapper.push(ele);
        else
            if(wrapper.mainStack.size()>=2 && wrapper.mainStack.top()=='b' && wrapper.secondElement=='a')
                wrapper.pop(), wrapper.pop();
    }
    
    return wrapper.mainStack.empty();
}

int main() 
{
	return 0;
}
