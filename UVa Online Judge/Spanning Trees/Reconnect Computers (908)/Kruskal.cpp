#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
	vector<int> parent, rank;
	
public:
	UnionFind(int n, bool oneBasedIndexing);
	void make_set(int v);
	int find_set(int v);
	void union_sets(int a, int b);
};

UnionFind :: UnionFind(int n, bool oneBasedIndexing = false)
{
	if(oneBasedIndexing)
		n++;
	
	parent.resize(n);
	rank.resize(n);
	for(int i = 0; i < n; i++)
		make_set(i);
}

void UnionFind :: make_set(int v)
{
	parent[v] = v;
	rank[v] = 0;
}

int UnionFind :: find_set(int v)
{
	if(parent[v] == v)
		return v;
	
	int root_v = find_set(parent[v]);
	parent[v] = root_v;
	return root_v;
}


void UnionFind :: union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	
	if(a != b)
	{
		if(rank[b] > rank[a])
			swap(a,b);
		
		parent[b] = a;
		
		if(rank[a] == rank[b])
			rank[a]++;
	}
}

class Edge
{
public:
	int u, v, weight;
	
public:
	Edge(int u, int v, int weight)
	{
		this->u = u;
		this->v = v;
		this->weight = weight;
	}
	
	bool operator < (const Edge &incoming)const
	{
		return weight < incoming.weight;
	}
};


	


	
long long Kruskal_MST(int totalVertex, vector<Edge> &EdgeList)
{
	sort(EdgeList.begin(), EdgeList.end());
	
	vector<Edge> answer;
	long long  minWeight = 0;
	
	UnionFind dsu(totalVertex, true);
	for(auto edge : EdgeList)
	{
		if(dsu.find_set(edge.u) != dsu.find_set(edge.v))
		{
			dsu.union_sets(edge.u, edge.v);
			answer.push_back(edge);
			minWeight += edge.weight;
		}
	}
	
	/* Answer contains the required edges */
	/* minWeight contains the sum of weights of the spanning tree */
	
	return minWeight;
}



void solve()
{
	int n;
	cin >> n;
	
	long long oldCost = 0;
	for(int i = 0; i < (n-1); i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		oldCost += w;
	}

	int k;
	cin >> k;
	
	vector<Edge> EdgeList;
	for(int i = 0; i < k; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		EdgeList.push_back(Edge(u,v,w));
	}
	
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		EdgeList.push_back(Edge(u,v,w));
	}
	
	long long newCost = Kruskal_MST(n, EdgeList);
	cout << oldCost << endl;
	cout << newCost << endl;
	
	cin.ignore(2);
}

int main()
{
    int counter = 0;
    while(cin.peek() != EOF and cin.peek() != '\n')
    {
        if(counter !=0)
            cout << endl;
        counter++;
        solve();
    }
}
