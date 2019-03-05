#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string str);
};

/* Reverses the string but keeps the words same */
string Solution :: reverseWords(string str)
{
    // Create a new stringstream
    stringstream newStream(str);
    
    // Variables to store the results
    string finalAnswer, word;
    stack<string> myStack;
    
    // As long as the stream contains words, extract it and push it onto the stack
    while(newStream >> word)
        myStack.push(word);
    
    // Clear the stack and the string would be reversed
    while(!myStack.empty())
    {
        // Append the new word
        finalAnswer += myStack.top(); 
        myStack.pop();
        
        // If it is not the last iteration, append space
        if(!myStack.empty()) finalAnswer += " ";
    }

    // Return the reversed string
    return finalAnswer;
}

/* The question demands that extra spaces be removed, it takes care of that */


int main() 
{
	return 0;
}
