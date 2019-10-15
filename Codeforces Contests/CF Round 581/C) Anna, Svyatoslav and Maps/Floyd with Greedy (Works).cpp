#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;
int inf = 1e9;

class Solution
{
    public:
    int n;
    Matrix d;
    Matrix adj;
    vector<int> path;
    vector<int> ans;
    
    public:
    void floyd_warshall();
    void solve();
    void scan_adj();
    void scan_path();
    void print();
};

void Solution :: floyd_warshall()
{
    // Create the Matrix and Initialize to inf
    d.resize(n, vector<int>(n,inf));
    
    // The zeroth phase
    for(int i = 0; i < n; i++)
        for(int j = 0; j<n; j++)
            if(adj[i][j])
                d[i][j] = adj[i][j];
    
    // Initialize the diagonal
    for(int i = 0; i < n; i++)
        d[i][i] = 0;
    
    // Borrowed from CP algorithms
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
}

void Solution :: solve()
{
    // Run Floyd Warshall to get APSP Matrix
    floyd_warshall();
    
    int m = path.size();
    
    int ind = 0;
    
    while(ind < m)
    {
        int current_vertex = path[ind];
        ans.push_back(current_vertex);
        
        int dist = 1;
        ++ind;
        while(ind < m and d[current_vertex][path[ind]] >= dist)
            ind++, dist++;
        
        // The current index is violating the conditions, hence we need to block it
        if(ind >= m)
            break;
        else
            ind--;
    }
    
    // Push the last index manually
    if(ans.back() != path.back())
        ans.push_back(path.back());
}

/* Remember to take character input */
void Solution :: scan_adj()
{
    cin >> n;
    adj.resize(n, vector<int>(n,0));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            adj[i][j] = temp - '0';        
        }
    }
}

void Solution :: scan_path()
{
    int path_length;
    cin >> path_length;
    
    path.resize(path_length);
    for(auto &ele : path)
    {
        cin >> ele;
        ele--;
    }
}

void Solution :: print()
{
    cout << ans.size() << endl;
    for(auto ele : ans)
        cout << (ele + 1) << " ";
        
}

int main()
{
	Solution s;
	s.scan_adj();
	s.scan_path();
	s.solve();
	s.print();
	return 0;
}
