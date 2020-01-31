#include <bits/stdc++.h>
using namespace std;

/* dp_incl[source] represents the min vertex cover of subtree rooted at source, 
 * when you necessarily include the source in your cover. No Restriction on children
 */

/* dp_excl[source] represents the min vertex cover of subtree rooted at source, 
 * when you necessarily exclude the source from your cover
 */

/* dp_subtree[source] represents the min vertex cover of subtree at source,
 * with no restriction on exclusion/inclusion
 */

class Tree
{
public:
	int vertex;
	vector<int> dp_incl, dp_excl, dp_subtree;
	vector<vector<int>> adj;
public:
	Tree(int vertex);
	void addEdge(int u, int v);
	void minVertexCover(int source, int parent);
};

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	dp_incl.resize(vertex, 0);
	dp_excl.resize(vertex, 0);
	dp_subtree.resize(vertex, 0);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Tree :: minVertexCover(int source, int parent)
{
	dp_excl[source] = 0;
	dp_incl[source] = 1;

	for(int child : adj[source])
	{
		// A Recurring Problem. Take care next time. Risky!
		if(child == parent)
			continue;
		
		minVertexCover(child, source);

		// Pay attention to the second line. No Restriction on children
		dp_excl[source] += dp_incl[child];
		dp_incl[source] += dp_subtree[child];
	}

	dp_subtree[source] = min(dp_excl[source], dp_incl[source]);
}

void solve()
{
	int vertex, edges;
	cin >> vertex;
	
	edges = vertex - 1;

	Tree tree(vertex);
	for(int i = 0; i < edges; i++)
	{
		int x, y;
		cin >> x >> y;
		
		// Make zero based indexing
		x--; y--;
		
		tree.addEdge(x,y);
	}

	tree.minVertexCover(0, -1);
	cout << tree.dp_subtree[0] << endl;
}

int main()
{
	solve();
	return 0;
}
