#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int alphabetSize = 26;
    vector<int> freq;
    vector<int> minMatching;
    vector<string> answer;
public:   
    Solution()
    {
        freq.resize(alphabetSize);
        minMatching.resize(alphabetSize, INT_MAX);
    }
    void mapCharacters(string str);
    vector<string> commonChars(vector<string>& a);
};

/* Maps the characters to its frequency */
void Solution :: mapCharacters(string str)
{
    // Initialise the frequency vector with zero
    for(auto &ele:freq)
        ele = 0;
    
    // Increase the frequency of each element as it is encountered
    for(auto ele : str)
        freq[ele-'a']++;
}

/* Returns the common characters in all the strings */
vector<string> Solution :: commonChars(vector<string>& a)
{
    // Iterate throught each string
    for(auto str : a)
    {
        // Map the charcters in the frequency vector
        mapCharacters(str);
        
        // Traverse the frequency map , and update the minimum matching
        for(int i=0; i<alphabetSize; i++)
            minMatching[i] = min(minMatching[i], freq[i]);
    }

    // Traverse the minMatching vector and fill the answer
    for(int i=0; i<alphabetSize; i++)
    {
        // Get the minimum number of repetitions of ecah charcter and append it to answer
        int count = minMatching[i];
        for(int j=0; j<count; j++)
            answer.push_back(string(1, 'a'+i));
    }
    
    return answer;
}

int main() 
{
	return 0;
}
