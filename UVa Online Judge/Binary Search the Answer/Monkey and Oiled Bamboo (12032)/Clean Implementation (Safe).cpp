#include <bits/stdc++.h>
using namespace std;

/* Assumes that the sentinel is appended at the front */
bool possible(vector<int> &a, int max_jump_length)
{
	int n = a.size();

	for(int i = 1; i < n; i++)
	{
		if(max_jump_length <= 0)
			return false;

		int jump = a[i] - a[i-1];

		if(jump > max_jump_length)
			return false;

		if(jump == max_jump_length)
			max_jump_length--;
	}

	return true;
}

int solve(vector<int> &a)
{
	int low = 1;
	int high = 1e7;
	
	int res;
	
	/* Clean implementation of Binary Search */
	while(low <= high)
	{
		int mid = (low + high)/2;

		if(possible(a, mid))
		{
			res = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	assert(possible(a, res));

	return res;
}

int main()
{
	int test;
	cin >> test;

	for(int i = 1; i <= test; i++)
	{
		int n;
		cin >> n;

		vector<int> a(n);
		for(auto &ele : a)
			cin >> ele;
		
		int sentinel = 0;
		
		// Technique to insert an element at the front
		a.insert(a.begin(), sentinel);

		cout << "Case " << i << ": "  << solve(a) << endl;


	}
}
