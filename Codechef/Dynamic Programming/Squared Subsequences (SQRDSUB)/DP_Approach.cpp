
#include<bits/stdc++.h>
using namespace std;

/* Returns the total number of subarrays a[i...j] such that a[i]*...*a[j] is divisible by mod */
long Total_Subarrays_Divisible_By(int mod, vector<int> &a)
{
	int n = a.size();
	vector<vector<int>> dp(n, vector<int>(mod, 0));

	/* DP[i][rem] dentoes the number of subarrays ending at 'i' with remainder 'rem' */

	dp[0][a[0]%mod]++;
	for(int i = 1; i < n; i++)
	{
		int current_rem = a[i]%mod;
		
		// A single element subarray
		dp[i][current_rem]++;
		
		for(int old_rem = 0; old_rem < mod; old_rem++)
		{
			int new_rem = (current_rem*old_rem)%mod;
			dp[i][new_rem] += dp[i-1][old_rem];
		}
	}
	
	long res = 0;
	for(int i = 0; i < n; i++)
		res += dp[i][0];

	return res;
}

void Squared_Subsequences(vector<int> &a)
{
	long n = a.size();
	long ans = Total_Subarrays_Divisible_By(4, a);
	ans += n*(n+1)/2 - Total_Subarrays_Divisible_By(2, a);

	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		vector<int> a(n);
		for(auto &ele : a)
			cin >> ele, ele = abs(ele);

		Squared_Subsequences(a);
	}
	return 0;
}
	
