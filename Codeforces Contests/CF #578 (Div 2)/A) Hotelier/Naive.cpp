#include <bits/stdc++.h>
using namespace std;

/* Scans the contents of a vector of any data type*/
/* Assumes that the vector has been resized */
template <typename universal_type>
void scanVector(vector<universal_type> &myVector)
{
    for(auto &ele : myVector)
        cin >> ele;
}
 
 
void solve(string str)
{
    int n = 10;
    vector<bool> occupied(n, false);
 
    for(auto ele : str)
    {
        if(ele == 'L')
        {
            int i = 0;
            while(i<n and occupied[i])
                i++;
            
            occupied[i] = true;
        }
            
        if(ele == 'R')
        {
            int i = n-1;
            while(i>=0 and occupied[i])
                i--;
            
            occupied[i] = true;
        }
        
        else
        {
            int index = ele - '0';
            occupied[index] = false;
        }
    }
    
    for(auto ele : occupied)
        cout << ele;
    
    cout << endl;
        
}
 
signed main()
{
    int size;
    cin >> size;
    
    string str;
    cin >> str;
    
    solve(str);
    
	return 0;
}
