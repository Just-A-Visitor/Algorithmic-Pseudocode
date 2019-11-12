#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int u, v, weight;

public:
	Edge(int u, int v, int weight)
	{
		this->u = u, this->v = v;
		this->weight = weight;
	}
	
	bool operator < (const Edge& big) const
	{
		auto lhs = tie(weight, u, v);
		auto rhs = tie(big.weight, big.u, big.v);
		
		return lhs < rhs;
	}
};

int main()
{
	cout<<"GfG!";
	return 0;
}
