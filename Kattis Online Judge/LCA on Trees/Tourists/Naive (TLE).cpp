#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
	int vertex;
	vector< vector<int> > adj;
	vector<int> depth, parent;
public:
	Tree(int vertex)
	{
		this->vertex = vertex;
		adj.resize(vertex);
	}
	
	void addEdge(int u, int v);
	void level_order_traversal();
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
	depth.assign(vertex, -1);
	parent.assign(vertex, -1);

	queue<int> bfs;

	int source = 0;
	depth[source] = 0;
	parent[source] = -1;
	bfs.push(source);

	while(not bfs.empty())
	{
		int current = bfs.front();
		bfs.pop();

		for(auto child : adj[current])
		{
			// A child may contain parent in its adjList
			if(depth[child] == -1)
			{
				depth[child] = depth[current] + 1;
				parent[child] = current;
				bfs.push(child);
			}
		}
	}

}

/* Returns the lowest common ancestor of 2 vertices */
int Tree :: LCA(int u, int v)
{
	// Assume that the first node is deeper in the tree
	if(depth[u] < depth[v])
		return LCA(v,u);

	// Make the depths equal
	while(depth[u] != depth[v])
		u = parent[u];

	// Start climbing up the tree
	while(u != v)
	{
		u = parent[u];
		v = parent[v];
	}

	return u;
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
