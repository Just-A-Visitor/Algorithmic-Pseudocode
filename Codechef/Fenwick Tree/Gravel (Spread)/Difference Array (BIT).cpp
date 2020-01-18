#include <bits/stdc++.h>
using namespace std;

int LSone(int n)
{
	return (n & (-n));
}

class FenwickTree
{
	vector<long long> ft;
public:
	FenwickTree(int n)
	{
		ft.assign(n+1, 0);
	}

	long long rsq(int b);
	void adjust(int ind, int to_add);
	void updateRange(int left, int right, int to_add);
	long long queryPoint(int ind);
};

long long FenwickTree :: rsq(int b)
{
	long long sum = 0;
	for(; b > 0; b -= LSone(b))
		sum += ft[b];

	return sum;
}

void FenwickTree :: adjust(int ind, int to_add)
{
	for(; ind < ft.size(); ind += LSone(ind))
		ft[ind] += to_add;
}

void FenwickTree :: updateRange(int left, int right, int to_add)
{
	// Note :: The Out of Bound access would be taken care by adjust
	adjust(left, to_add);
	adjust(right + 1, -1*to_add);
}

long long FenwickTree :: queryPoint(int ind)
{
	return rsq(ind);
}

/* One Based Indexing for the array */
void solve(vector<int> &a, int n, int queries)
{
	
	// Convert to difference array
	a[0] = 0;
	vector<int> diff(a.size(), 0);
	for(int i = 1; i <= n; i++)
		diff[i] = a[i] - a[i-1];

	// Remember, one based indexing
	FenwickTree ft(n);

	// Intialize the Fenwick Tree
	/* ft.updateRange(i, i, diff[i]) is wrong. Why? */
	/* Very Serious Bug. Cost me a WA */
	for(int i = 1; i <= n; i++)
		ft.adjust(i, diff[i]);
		
	// Answer the queries
	for(int i = 0;  i < queries; i++)
	{
		char type;
		cin >> type;

		if(type == 'S')
		{
			int left, right, to_add;
			cin >> left >> right >> to_add;

			ft.updateRange(left, right, to_add);
		}

		if(type == 'Q')
		{
			int ind;
			cin >> ind;

			cout << ft.queryPoint(ind) << endl;
		}
	}
}

int main()
{
	// Cheap Trick to pass the test cases
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, queries, initial_data;
	cin >> n >> queries >> initial_data;

	// One based indexing
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
		a[i] = initial_data;

	solve(a, n, queries);
	return 0;
}
