#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int vertex;
	int last_visited_node = 0;
	int total_gain = 0;

	vector<vector<int>> adj;
	vector<int> gain;
	
public:
	Graph(int vertex, vector<int> &gain);
	void addEdge(int u, int v);
	void dfs(int source);
};

Graph :: Graph(int vertex, vector<int> &gain)
{
	this->vertex = vertex;
	adj.resize(vertex);
	this->gain = gain;
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph :: dfs(int source)
{
	total_gain += gain[source];
	last_visited_node = source;
	
	int next_vertex_max_gain = INT_MIN;
	int next_vertex = -1;
	for(auto ele : adj[source])
	{
		if(next_vertex_max_gain < gain[ele])
		{
			next_vertex_max_gain = gain[ele];
			next_vertex = ele;
		}
	}
	
	if(next_vertex_max_gain != INT_MIN)
		dfs(next_vertex);
}

void solve()
{
	int vertex, edges;
	cin >> vertex >> edges;
	
	vector<int> gain(vertex);
	for(auto &ele : gain)
		cin >> ele;
	
	Graph graph(vertex, gain);
	
	for(int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		
		graph.addEdge(u, v);
	}
	
	graph.dfs(0);
	cout << graph.total_gain << " " << graph.last_visited_node << endl;
}

int main()
{
	int test;
	cin >> test;
	
	for(int i = 1; i <= test; i++)
	{
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}
