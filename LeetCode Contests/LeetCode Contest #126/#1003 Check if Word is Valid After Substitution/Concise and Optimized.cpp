class Solution
{
public:
    bool isValid(string str);
};

/* Return true if the word is valid */
bool Solution :: isValid(string str)
{
    vector<char> specialStack;
    int n;
    
    // Traverse the string and keep deleting 'abc' in O(1)
    for(auto ele : str)
    {
        n = specialStack.size();
        
	// If the character is 'c', pop the matching 'b' and 'a' from the stack, if they exist 
        if(ele!= 'c' || n==0) specialStack.push_back(ele);
        else
            if(n>=2 && specialStack[n-1]=='b' && specialStack[n-2]=='a')
                specialStack.pop_back(), specialStack.pop_back();
    }
    
    return specialStack.size()==0;
}
