#include <bits/stdc++.h>
using namespace std;

const int sentinel = -1;

class Tree
{
public:
	int vertex, maxPower;
	vector< vector<int> > adj;
	vector< vector<int> > jump;
	vector<int> depth, parent;
public:
	Tree(int vertex)
	{
		this->vertex = vertex;
		adj.resize(vertex);
	}
	
	void addEdge(int u, int v);
	void level_order_traversal();
	void binary_lifting();
	int walk(int source, int k);
	int LCA(int u, int v);
	int shortest_path(int u, int v);
};

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Tree :: level_order_traversal()
{
	depth.assign(vertex, sentinel);
	parent.assign(vertex, sentinel);

	queue<int> bfs;

	int source = 0;
	depth[source] = 0;
	parent[source] = sentinel;
	bfs.push(source);

	while(not bfs.empty())
	{
		int current = bfs.front();
		bfs.pop();

		for(auto child : adj[current])
		{
			// A child may contain parent in its adjList
			if(depth[child] == sentinel)
			{
				depth[child] = depth[current] + 1;
				parent[child] = current;
				bfs.push(child);
			}
		}
	}

}

/* Set up the lookup table */
void Tree :: binary_lifting()
{
	// Find the maximum jump that you can make
	maxPower = floor(log2(vertex)); 
	
	/* I struggled so much with the above bug. Cost me 5 WA
	 * Remember the difference between log and log2
	 * Initially, it gave the default log value to the base 10
	 * A safe way is to use maxPower as a constant 20
	 */

	int n = vertex;

	// Create the skip list. Notice the extra one
	int row = maxPower + 1;
	int col = vertex;
	
	// Resize the matrix
	jump.assign(row, vector<int> (col, sentinel));

	// The node at the first jump is the parent
	for(int i = 0; i < n; i++)
		jump[0][i] = parent[i];

	// Fill the rest of the table
	for(int k = 1; k <= maxPower; k++)
	{
		for(int i = 0; i < n; i++)
		{
			// Make the first jump at 2^(k-1)
			int mid = jump[k-1][i];

			// Check if you have over shooted
			if(mid == sentinel)
				continue;

			// Make the second jump at 2^(k-1)
			int dest = jump[k-1][mid];

			// The final jump is the sum of both
			jump[k][i] = dest;
		}
	}
}

/* Walk exactly k distance up the tree */
int Tree :: walk(int source, int k)
{
	for(int i = maxPower; i >=0 and source != sentinel; i--)
	{
		// If the i-th bit is set, jump by 2^i amount
		if( (1 << i) & k)
			source = jump[i][source];
	}

	return source;
}

/* Finds the LCA between u and v */
int Tree :: LCA(int u, int v)
{
	if(depth[u] < depth[v])
		swap(u,v);

	// The first node is the deeper one. Bring them on the same level
	u = walk(u, depth[u] - depth[v]);
	
	// This has to be handled explicitly. Think why? (We have to be one shy)
	if(u == v)
		return u;
	
	// Keep trying the largest jump possible
	for(int k = maxPower; k >= 0; k--)
	{
		if(jump[k][u] != jump[k][v])
		{
			u = jump[k][u];
			v = jump[k][v];
		}
	}

	// We are one shy of the ancestor
	return jump[0][u];
}

/* Returns the number of edges in the shortest path from 'u' to 'v' */
int Tree ::  shortest_path(int u, int v)
{
	return depth[u] + depth[v] - 2*depth[LCA(u,v)];
}

void solve()
{
	int vertex, edges;
	cin >> vertex;
	edges = vertex - 1;

	Tree tree(vertex);
	for(int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;

		// Take care of one based indexing
		u--; v--;
		tree.addEdge(u, v);
	}

	tree.level_order_traversal();
	tree.binary_lifting();	
	int n = vertex;
	long long sum = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 2*i; j <= n; j += i)
		{
			// Accomodate for one based indexing
			sum += tree.shortest_path(i-1, j-1);

			// The question actually asks for the number of vertices, not edges
			// `k` edges b/w shortest path ==> `k + 1` vertices
			sum += 1;
		}
	}

	cout << sum << endl;
}

int main()
{
	solve();
	return 0;
}
