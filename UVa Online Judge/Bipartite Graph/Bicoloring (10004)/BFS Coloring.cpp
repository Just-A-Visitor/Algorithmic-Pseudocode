#include <bits/stdc++.h>
using namespace std;

#define white 0
#define black 1

class Graph
{
	vector<vector<int>> adj;
	int vertex;
	
	public:
	Graph(int vertex);
	bool isBiPartite();
	void addEdge(int u, int v);
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

bool Graph :: isBiPartite()
{
	vector<int> color(vertex);
	vector<bool> visited(vertex, false);
	queue<int> bfs;

	color[0] = white;
	bfs.push(0);
	visited[0] = true;

	while(!bfs.empty())
	{
		int current = bfs.front();
		bfs.pop();

		for(auto ele : adj[current])
		{
			if(!visited[ele])
			{
				bfs.push(ele);
				color[ele] = color[current] xor 1;
				visited[ele] = true;
			}
			else
			{
				if(color[ele] == color[current])
					return false;
			}
		}
	}

	return true;
}

/* Already 0 based Indexing */

void solve()
{
	int vertex, edges;
	cin >> vertex >> edges;

	Graph g(vertex);
	for(int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;
		
		// The graph is undirected
		g.addEdge(u, v);
		g.addEdge(v, u);
	}

	if(g.isBiPartite())
		cout << "BICOLORABLE." << endl;
	else
		cout << "NOT BICOLORABLE." << endl;
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
