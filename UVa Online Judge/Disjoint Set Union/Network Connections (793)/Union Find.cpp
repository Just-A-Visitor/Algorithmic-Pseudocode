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


void solve()
{
	int size;
	cin >> size;
	cin.ignore();
	
	int success = 0, failure = 0;
	
	// One Based Indexing
	UnionFind dsu(size, true);

	while(cin.peek() != EOF and cin.peek() != '\n')
	{
		char queryType;
		int left, right;
		cin >> queryType >> left >> right;
		
		if(queryType == 'c')
		{
			dsu.union_sets(left, right);
		}
		else
		{
			if(dsu.find_set(left) == dsu.find_set(right))
				success++;
			else
				failure++;
		}
		
		cin.ignore();
	}
	
	cout << success << "," << failure << endl;
}

int main()
{
	int testCases;
	cin >> testCases;
	
	for(int i = 0; i < testCases; i++)
	{
	    if(i != 0)
	        cout << endl;
	        
	    solve();
	}
	
}
