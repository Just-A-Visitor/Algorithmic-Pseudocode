#include <bits/stdc++.h>
using namespace std;

/* Note : Be very careful with comparators if you are going to use equality method 
 * If there are 2 small arguments, you can just skip 'auto' and compare directly 
 * The comparator can never look like lhs <= rhs. Why is that? Think Carefully. 
 */

/* It's missing one thing. You always have to provide arguments during instantiation */

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
