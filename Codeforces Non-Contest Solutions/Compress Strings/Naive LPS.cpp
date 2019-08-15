#include <bits/stdc++.h>
using namespace std;
 
vector<int> prefix_function(string str)
{
    int n = str.length();
    vector<int> lps(n);
    
    for(int i=1; i<n; i++)
    {
        int j = lps[i-1];
        while(j>0 and str[j]!=str[i])
            j = lps[j-1];
        
        if(str[i]==str[j])
            j++;
        
        lps[i] = j;
    }
    
    return lps;
}
 
void merge_strings(vector<string>& a)
{
    int n = a.size();
    string previousString = a[0];
    
    for(int i=1; i<n; i++)
    {
        string newString = a[i] + '#' + previousString;
        vector<int> lps = prefix_function(newString);
        
        int overlapped_parts = lps.back();
        for(int j=overlapped_parts; j<a[i].length(); j++)
            previousString += a[i][j];
    }
    
    cout << previousString << endl;
}
 
int main()
{
    int n;
    cin >> n;
    
    vector<string> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    merge_strings(a);
    
	return 0;
}
 
