#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
/* Remember to convert to 0 based indexing and convert back */
 
void printVector(vector<int> &answer)
{
    cout << answer.size() << endl;
    for(auto ele : answer)
        cout << ele + 1 << " ";
}
 
void scanVector(vector<int> &vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        int temp;
        cin >> temp;
        vec[i] = temp - 1;
    }
}
 
void scanMatrix(vector<vector<int>> &adj)
{
    for(int i=0; i<adj.size(); i++)
    {
        for(int j=0; j<adj[0].size(); j++)
        {
            char temp;
            cin >> temp;
            adj[i][j] = temp-'0';
        }
    }
}
 
void solve(vector<vector<int>> &adj, vector<int> &a)
{
    stack<int> s;
    
    int ind = 0;
    int m = a.size();
    bool working = true;
    while(working)
    {
        if(s.size() >= 3)
        {
            int right = s.top();
            s.pop();
            
            int current = s.top();
            s.pop();
            
            int left = s.top();
            s.pop();
            
            // If left and right are not connected, remove current
            if(left!=right and adj[left][current] == 1 and adj[current][right] == 1 and adj[left][right] == 0)
            {
                s.push(left);
                s.push(right);
            }
            
            // Push them all back
            else
            {
                s.push(left); 
                s.push(current); 
                s.push(right);
                
                if(ind >= m)
                    working = false;
                else
                    s.push(a[ind++]);
            }
        }
        
        else
        {
            if(ind < m)
                s.push(a[ind++]);
            else
                working = false;
        }
    }
    
    vector<int> answer;
    
    while(!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());
    printVector(answer);
}
 
int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n, vector<int>(n,0));
    scanMatrix(adj);
    
    int m;
    cin >> m;
    
    vector<int> a(m,0);
    
    scanVector(a);
    solve(adj,a);
    
	return 0;
}
