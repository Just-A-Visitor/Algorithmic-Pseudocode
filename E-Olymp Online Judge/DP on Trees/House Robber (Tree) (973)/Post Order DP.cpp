#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
	int vertex;
	vector< vector<int> > adj;
	vector<int> coins, dp_include, dp_exclude;
	vector<int> dp_subtree;

public:
	Tree(int vertex);
	void addEdge(int u, int v);
	void update_dfs(int source, int parent);
};

Tree :: Tree (int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);

	coins.resize(vertex);
	dp_subtree.resize(vertex);
	dp_include.resize(vertex);
	dp_exclude.resize(vertex);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

/* dp_include[i] represents the maximum coins in the i-th subtree when you necessarily include the i-th vertex
 * dp_exclude[i] represents the maximum coins in the i-th subtree when you necessarily exlcude the i-th vertex
 * dp_subtree[i] represents the maximum coins in the subtree with the i-th vertex as root (covers all cases)
 */


void Tree :: update_dfs(int source, int parent)
{
	dp_include[source] = coins[source];
	dp_exclude[source] = 0;

	for(auto child : adj[source])
	{
		
		if(child == parent)
			continue;
		
		update_dfs(child, source);

		// A Tricky case. dp_subtree, not dp_include. Why? 
		dp_exclude[source]  += dp_subtree[child];
		dp_include[source]  += dp_exclude[child];
	}

	dp_subtree[source] = max(dp_exclude[source], dp_include[source]);
}
void solve()
{
	int vertex;
	cin >> vertex;

	Tree tree(vertex);
	
	for(int i = 0; i < (vertex - 1); i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;

		tree.addEdge(u, v);
	}

	for(int i = 0; i < vertex; i++)
		cin >> tree.coins[i];

	// Root the tree at the 0-th vertex
	tree.update_dfs(0, -1);
	
	int res = tree.dp_subtree[0];

	cout << res << endl;
}

int main()
{
	solve();
	return 0;
}
