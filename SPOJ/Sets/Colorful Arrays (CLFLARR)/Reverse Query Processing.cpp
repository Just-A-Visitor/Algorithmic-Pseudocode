#include <bits/stdc++.h>
using namespace std;

class Query
{
public:
	int l, r, color;
	Query(int l, int r, int color)
	{
		this->l = l;
		this->r = r;
		this->color = color;
	}
};

void colorful_arrays(int n, vector<Query> &queryVec)
{
	// One based Indexing
	vector<int> finalColor(n + 1);

	set<int> uncolored;
	for(int i = 1; i <= n; i++)
		uncolored.insert(i);

	// Process the queries in reverse order
	reverse(queryVec.begin(), queryVec.end());

	for(auto ele : queryVec)
	{
		auto itr = uncolored.lower_bound(ele.l);

		while(itr != uncolored.end() and *itr <= ele.r)
		{
			finalColor[*itr] = ele.color;
			itr = uncolored.erase(itr);
		}

	}

	for(int i = 1; i <= n; i++)
		cout << finalColor[i] << endl;

}

int main()
{
	int n, queryLength;
	cin >> n >> queryLength;

	vector<Query> queryVec;
	
	for(int i = 0; i < queryLength; i++)
	{
	    int l, r, color;
	    cin >> l >> r >> color;
	    queryVec.push_back(Query(l, r, color));
	}

	colorful_arrays(n, queryVec);
	
	return 0;
}
