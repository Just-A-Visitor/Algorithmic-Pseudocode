#include <bits/stdc++.h>
using namespace std;

/* Note : Be very careful with comparators if you are going to use equality method 
 * If there are 2 small arguments, you can just skip 'auto' and compare directly 
 * The comparator can never look like lhs <= rhs. Why is that? Think Carefully.
 */

/* It also includes the default constructor to create fixed size arrays 
 * You can skip the default constructor if you are aren't creating fixed size vector
 * Instead, use `push_back`
 */

class Edge
{
public:
	int u, v, weight;

public:

	Edge() : u(), v(), weight() {};
	
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
	int n;
	cin >> n;
	
	vector<Edge> vec(n);
	
	for(auto &ele : vec)
		cin >> ele.u >> ele.v >> ele.weight;
	
	for(auto &ele : vec)
		cout << ele.u << " " << ele.v << " " << ele.weight << "\n";
	  
	return 0;
}
