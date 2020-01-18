#include <bits/stdc++.h>
using namespace std;

#define white 0
#define black 1

class Graph
{
public:
	int vertex;
	bool not_bi_colorable = false;
	vector<int> color;
	vector<bool> visited;
	vector<vector<int>> adj;
	
public:
	Graph(int vertex);
	void addEdge(int u, int v);
	void dfs(int source);
	void dfs_wrapper();
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	color.resize(vertex);
	visited.resize(vertex);
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph :: dfs(int source)
{
	visited[source] = true;
	
	for(auto ele : adj[source])
	{
		if(!visited[ele])
		{
			color[ele] = color[source] xor 1;
			dfs(ele);
		}
		else if(color[ele] == color[source])
		{
			not_bi_colorable = true;
		}
	}
}


void Graph :: dfs_wrapper()
{
	visited.assign(vertex, false);
	color.assign(vertex, white);
	
	for(int u = 0; u < vertex; u++)
		if(!visited[u])
			dfs(u);
}

/* Already 0 based Indexing */

void solve()
{
	int vertex, edges;
	cin >> vertex >> edges;

	Graph graph(vertex);
	for(int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		
		// The graph is undirected
		graph.addEdge(u, v);
		graph.addEdge(v, u);
	}
	
	graph.dfs_wrapper();
	
	if(graph.not_bi_colorable)
		cout << "NOT BICOLORABLE." << endl;
	else
		cout << "BICOLORABLE." << endl;
}

int main()
{
	while(cin.peek() != '0')
	{
		solve();
		cin.ignore();
	}

	return 0;
}
