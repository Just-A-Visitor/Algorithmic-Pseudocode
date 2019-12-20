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
		if(weight == big.weight)
		{
			if(u == big.u)
				return v < big.v;
			
			return u < big.u;
		}
		
		return weight < big.weight;
	}
};

int main()
{
	cout<<"GfG!";
	return 0;
}
