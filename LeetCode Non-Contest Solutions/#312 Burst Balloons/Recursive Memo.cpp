class Solution
{
	vector< vector<int> > memo;

public:
	int collect(vector<int> &a, int low, int high);
	int maxCoins(vector<int> &a);
};

/* Max Coins that you can collect in the range (low, high) (Both exclusive) */
int Solution :: collect(vector<int> &a, int low, int high)
{
	int len = high - low + 1;

	if(len <= 2)
		return 0;

	if(memo[low][high] != -1)
		return memo[low][high];

	int max_profit = 0;
	for(int k = low + 1; k < high; k++)
	{
		int collect_left = collect(a, low, k);
		int collect_right = collect(a, k, high);
		int collect_now = a[low]*a[k]*a[high];

		int profit_now = collect_left + collect_right + collect_now;

		max_profit = max(max_profit, profit_now);
	}

	memo[low][high] = max_profit;
	return max_profit;
}

int Solution :: maxCoins(vector<int> &a)
{
	int sentinel = 1;

	// Create 2 boundaries
	a.push_back(sentinel);
	a.insert(a.begin(), sentinel);

	int n = a.size();
	memo.resize(n, vector<int> (n, -1));

	return collect(a, 0, n - 1);
}

