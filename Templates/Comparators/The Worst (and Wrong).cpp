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
		return weight < big.weight;
	}
};

/* Why is this comparator wrong?
 * Hint : It would work correctly for Kruskal but not for Dijkstra. Why?
 * Suppose you have one element in a set (2,3 weight = k)
 * Now, you try to find an element (6, 7, weight = k)
 * Do you think you'll get the correct answer. Experiment with it.
 * But how does it work correctly for Kruskal?
 * Why does it fail for Dijkstra. I mean, what do I care about vertex ordering by its index?
 */

int main()
{
	cout<<"GfG!";
	return 0;
}
