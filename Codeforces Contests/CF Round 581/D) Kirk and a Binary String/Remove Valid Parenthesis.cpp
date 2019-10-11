#include <bits/stdc++.h>
using namespace std;

void solve(string str)
{
    // String to store the final answer
    string result = str;
    
    // This is an indicial stack
    stack<int> myStack;
    
    // Remove all valid brackets
    for(int i = 0; i < str.length(); i++)
    {   
        // Opening bracket, Push it onto stack
        if(str[i] == '1')
        {
            myStack.push(i);
        }
        
        // Closing bracket
        else
        {
            // Pop a matching pair if exists
            if(!myStack.empty())
                myStack.pop();
        }
    }
    
    // The remaining brakcets haven't been paired
    // We can convert all opening to closing now
    while(!myStack.empty())
    {
        result[myStack.top()] = '0';
        myStack.pop();
    }
    
    // Print the result
    cout << result << endl;
}

int main()
{
	string str;
	cin >> str;
	
	solve(str);
	
	return 0;
}
