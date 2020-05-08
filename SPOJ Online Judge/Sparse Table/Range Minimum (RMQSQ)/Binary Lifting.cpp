#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

class RMQ
{
public:
	int n, maxPower;
	vector<int> a;
	vector<vector<int>> jump;

public:
	RMQ(vector<int> &a);
	void build_lookup_table();
	int query(int low, int high);
};

RMQ :: RMQ(vector<int> &a)
{
	this->a  = a;
	n = a.size();

	// maxPower = 20 works too
	maxPower = floor(log2(n));
}

void RMQ :: build_lookup_table()
{
	// We want to access jump[][maxPower]
	jump.assign(n, vector<int> (maxPower + 1, inf));

	/* jump[ind][power] represents the minimum number in the range [ind, ind + 2^power] */
	/* Transitions : From ind, jump to 'ind + 2^(power-1)' , and then jump to 'ind + 2^power' */

	// The first jump of step 1 will lead you to the next element 
	for(int i = 0; i < (n-1); i++)
		jump[i][0] = min(a[i], a[i+1]);

	for(int power = 1; power <= maxPower; power++)
	{
		for(int i = 0; i < n; i++)
		{
			int mid_index = i + (1 << (power - 1) );
			int mid_val = jump[i][power-1];

			int dest_val  = inf;

			if(mid_index < n)
				dest_val = jump[mid_index][power-1];
			
			jump[i][power] = min(mid_val, dest_val);

		}
	}
}

/* Assumes zero based indexing */
int RMQ :: query(int low, int high)
{
	/** Caused me a WA. This is the number of jumps we have to take
	  * It's not (high - low + 1). Think about it
	  */
	int distance = high - low;
	
	// Needs to be handled separately like Binary Lifting. Why?
	if(distance == 0)
		return a[low];
		
	int current_ind = low;
	int current_min = a[low];
	for(int power = maxPower; current_ind < n and power >=0; power--)
	{
		// Make the jump if it appears in the 'power of two sum'
		if(distance & (1 << power))
		{
			current_min = min(current_min, jump[current_ind][power]);
			current_ind += (1 << power);
		}
	}
	
	return current_min;
}

void solve()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int &ele : a)
		cin >> ele;
	
	// Don't forget to build the lookup table
	RMQ rmq(a);
	rmq.build_lookup_table();

	int queries;
	cin >> queries;
	for(int i = 0; i < queries; i++)
	{

		// The input is already zero based
		int low, high;
		cin >> low >> high;
		cout << rmq.query(low, high) << endl;
	}
}

int main()
{
	solve();
	return 0;
}
