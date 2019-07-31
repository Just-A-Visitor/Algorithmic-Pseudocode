#include <bits/stdc++.h>
using namespace std;

/* The smallest window inside big containing all characters of small */
void solve(string &text, string &pattern)
{
    // Extract the lenght of both the strings
    int text_length = text.length();
    int pattern_length = pattern.length();

    // HashMap to store the frequencies of small  and big string
    unordered_map<char, int> textCount, patternCount;
    
    // Hash the pattern according to frequencies
    for(auto ele : pattern)
        patternCount[ele]++;
    
    // Get the number of distinct elements in the pattern
    int numDistinct = patternCount.size();
    
    // Count represents the number of elements whose frequency is complete
    int count = 0;
    
    int left = 0, right = 0;
    
    int minWindow = INT_MAX;
    int start = -1;
    
    // Get the first window
    while(left<=right and right<text_length)
    {
        char current = text[right];
        
        // Hash the current element
        textCount[current]++;
        
        // If the frequency is complete, we found one element
        if(patternCount[current]!=0 and textCount[current]==patternCount[current])
            count++;
        
        // If all elements have been found, try to contract the window
        if(count == numDistinct)
        {
            while(left<=right and right<text_length and count==numDistinct)
            {
                int current_window = right - left + 1;
                if(minWindow > current_window)
                {
                    minWindow = current_window;
                    start = left;
                }
                char current = text[left];
        
                //Decrease the frequency
                textCount[current]--;
                
                if(patternCount[current]!=0 and textCount[current] < patternCount[current])
                    count--;
                    
                left++;
            }
        }
        
        right++;
    }
    
    if(minWindow==INT_MAX)
        cout << -1 << endl;
    else
        cout << text.substr(start, minWindow) << endl;
}


int main()
{
    int test; 
    cin >> test;
    
    for(int i=0; i<test; i++)
    {
        string text, pattern;
        cin >> text >> pattern;
        solve(text,pattern);
    }
	return 0;
}
