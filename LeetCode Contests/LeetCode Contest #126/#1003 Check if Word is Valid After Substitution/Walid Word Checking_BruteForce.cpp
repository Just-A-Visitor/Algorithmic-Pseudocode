#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string str);
};

bool Solution :: isValid(string str)
{
    string pattern = "abc";
    
    auto position = str.find(pattern);
    
    while(position != string::npos)
    {
        str.erase(position, pattern.length());
        position = str.find(pattern);
    }
    
    return str.empty();
}
int main() 
{
	return 0;
}
