#include <bits/stdc++.h>
using namespace std;

/** This only works for zero based indexing **/

#define white 0
#define gray 1 
#define black 2 

class Graph
{
public:
	int vertex;	
	bool cyclePresent = false;
	
	vector<vector<int>> adj;
	vector<int> color;

public:
	Graph(int vertex);
	void addEdge(int u, int v);
	void dfs(int source);
	void dfs_wrapper();
	vector<int> topologicalSort();
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	color.resize(vertex, white);
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph :: dfs(int source)
{
	color[source] = gray;
	
	for(auto ele : adj[source])
	{
		if(color[ele] == white)
		{
			dfs(ele);
		}
		else 
		{
			if(color[ele] == gray)
				cyclePresent = true;
		}
	}
	
	color[source] = black;
}

void Graph :: dfs_wrapper()
{
	color.assign(vertex, white);
	for(int i = 0; i < vertex; i++)
		if(color[i] == white)
			dfs(i);
}

vector<int> Graph :: topologicalSort()
{
	vector<int> inDegree(vertex,0);

	for(auto &row_vec : adj)
		for(auto &child : row_vec)
			inDegree[child]++;
			
	vector<int> topologicalVec;
	queue<int> myQueue;
	
	for(int node = 0; node < vertex; node++)
		if(inDegree[node] == 0)
			myQueue.push(node);
	
	while(not myQueue.empty())
	{
		int current = myQueue.front();
		myQueue.pop();

		topologicalVec.push_back(current);

		for(auto child : adj[current])
		{
			inDegree[child]--;

			if(inDegree[child] == 0)
				myQueue.push(child);
		}
	}

	return topologicalVec;
}

void pickup_sticks(int vertex, int edges)
{
	Graph graph(vertex);
	for(int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		
		graph.addEdge(u,v);
	}
	
	graph.dfs_wrapper();
	
	if(graph.cyclePresent)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	vector<int> result = graph.topologicalSort();
	for(auto node : result)
	{
		node++;
		cout << node << endl;
	}
}

int main()
{
	int vertex, edges;
	
	cin >> vertex >> edges;
	
	while(vertex > 0 and edges > 0)
	{
		pickup_sticks(vertex, edges);
		cin >> vertex >> edges;
	}
	return 0;
}
