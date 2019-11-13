#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &vec, vector<int> &queries)
{
	sort(vec.begin(), vec.end());
	
	for(int query : queries)
	{
		auto itr = lower_bound(vec.begin(), vec.end(), query);
		
		int index = itr - vec.begin();
		
		// ++index to accomodate 1 based indexing
		if(index < vec.size() and vec[index] == query)
			cout << query << " found at " << ++index << endl;
		else
			cout << query << " not found" << endl;
	}
}

void scanVector(vector<int> &vec)
{
	for(auto &ele : vec)
		cin >> ele;
}

int main()
{
	int n, q;
	cin >> n >> q;
	
	int tc_number = 1;
	
	while(n > 0 and q > 0)
	{
		vector<int> vec(n), queries(q);
		
		scanVector(vec);
		scanVector(queries);
		
		cout << "CASE# " << tc_number++ << ":" << endl;
		solve(vec, queries);
		
		cin >> n >> q;
	}
	
	return 0;
}
