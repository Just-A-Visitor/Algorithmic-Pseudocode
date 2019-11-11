#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
	vector <int> parent;
public:
	UnionFind(int n, bool oneBasedIndexing);
	void make_set(int v);
	int find_set(int v);
	void union_sets(int a, int b);
};

/* Pass another argument if you want one based indexing */
UnionFind :: UnionFind(int n, bool oneBasedIndexing = false)
{
	if(oneBasedIndexing)
		n++;
	
	parent.resize(n);
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
		parent[root_b] = root_a;
}

void solve(int n, int g, vector<int> &origin, vector<int> &dest)
{
	// We want 1 based indexing
	UnionFind dsu(n, true);
	for(int num = g + 1; num <= n; num++)
		for(int factor = 2; num*factor <= n; factor++)
			dsu.union_sets(num, num*factor);
			
	for(int i = 0; i < origin.size(); i++)
	{
		if(dsu.find_set(origin[i]) == dsu.find_set(dest[i]))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}

int main()
{
	int n, g, queries;
	cin >> n >> g >> queries;
	
	vector<int> origin(queries);
	vector<int> dest(queries);
	
	for(auto &ele : origin)
		cin >> ele;
	
	// Useless Input
	cin >> queries; 
	for(auto &ele : dest)
		cin >> ele;
		
	solve(n, g, origin, dest);
}
