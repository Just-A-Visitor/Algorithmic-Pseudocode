#include <bits/stdc++.h>

using namespace std;

/* Returns the number of ways to lay the bricks */
int ways(int n)
{
	vector<int> dp(n+1, 0);

	// As per the sample test cases
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;

	// Either place a vertical or horizontal block first
	for(int i = 5; i <= n; i++)
		dp[i] = dp[i-1] + dp[i-4];

	return dp[n];
}

int redJohn(int n)
{
	int limit = ways(n);

	// Standard Sieve begins
	vector<bool> prime(limit + 1, true);

	prime[0] = false;
	prime[1] = false;
	
	// Be careful not to start outer loop from 1. Cost me a WA
	for(int i = 2; i <= limit; i++)
		for(int j = 2*i; j <= limit; j += i)
			prime[j] = false;
	
	int count = 0;
	for(int i = 0; i <= limit; i++)
		if(prime[i])
			count++;

	return count;
}


int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int result = redJohn(n);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}
