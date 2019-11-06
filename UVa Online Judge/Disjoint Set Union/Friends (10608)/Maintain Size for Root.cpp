#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
	vector <int> parent, size;
	int maxSize = 1;
public:
	UnionFind(int n, bool oneBasedIndexing);
	void make_set(int v);
	int find_set(int v);
	void union_sets(int a, int b);
};

/* We only store the size in the root node */

/* Pass another argument if you want one based indexing */
UnionFind :: UnionFind(int n, bool oneBasedIndexing = false)
{
	if(oneBasedIndexing)
		n++;
	
	parent.resize(n);
	size.resize(n, 1);
	for(int i = 0; i < n; i++)
		make_set(i);
}

void UnionFind :: make_set(int v)
{
	parent[v] = v;
}

int UnionFind :: find_set(int v)
{
	if(parent[v] == v)
		return v;
	
	// Path Compression
	parent[v] = find_set(parent[v]);
	return parent[v];
}

void UnionFind :: union_sets(int a, int b)
{
	int root_a = find_set(a);
	int root_b = find_set(b);
	
	if(root_a != root_b)
	{
		parent[root_b] = root_a;
		size[root_a] += size[root_b];
		maxSize = max(maxSize, size[root_a]);
	}
}


void solve()
{
    int n, queries;
    cin >> n >> queries;
    
    UnionFind dsu(n, true);
    for(int i = 0; i < queries; i++)
    {
        int left, right;
        cin >> left >> right;
        dsu.union_sets(left, right);
    }
    
    cout << dsu.maxSize << endl;
}

int main()
{
	int testCases;
	cin >> testCases;
	
	for(int i = 0; i < testCases; i++)
	{
	    solve();
	}
	
}
