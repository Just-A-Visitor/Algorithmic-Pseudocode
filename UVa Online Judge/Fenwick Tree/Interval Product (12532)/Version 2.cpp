#include <bits/stdc++.h>
using namespace std;

int LSone(int n)
{
	return (n & (-n));
}

class FenwickTree
{
	vector<int> ft;

public:
	FenwickTree(int n)
	{
		ft.resize(n + 1);
	}

	int rsq(int b);
	int rsq(int a, int b);
	void adjust(int ind, int to_add);
};

int FenwickTree :: rsq(int b)
{
	int sum = 0;
	for(; b > 0; b -= LSone(b))
		sum += ft[b];

	return sum;
}

int FenwickTree :: rsq(int a, int b)
{
	int big = rsq(b);
	
	if(a != 1)
		big -= rsq(a-1);

	return big;
}

void FenwickTree :: adjust(int ind, int to_add)
{
	for(; ind < ft.size(); ind += LSone(ind))
		ft[ind] += to_add;
}

void update(FenwickTree &ft_pos, FenwickTree &ft_neg, vector<int> &a, int ind, int newVal)
{
	if(newVal > 0)
	{
		if(a[ind] < 0)
		{
			ft_neg.adjust(ind,-1);
			ft_pos.adjust(ind, 1);
		}

		if(a[ind] == 0)
			ft_pos.adjust(ind, 1);
	}

	if(newVal < 0)
	{
		if(a[ind] > 0)
		{
			ft_pos.adjust(ind, -1);
			ft_neg.adjust(ind, 1);
		}

		if(a[ind] == 0)
			ft_neg.adjust(ind, 1);
	}
	
	if(newVal == 0)
	{
		if(a[ind] > 0)
			ft_pos.adjust(ind, -1);
		
		if(a[ind] < 0)
			ft_neg.adjust(ind, -1);
	}
	
	// Very Important Step
	a[ind] = newVal;
}

string solve(int n)
{
	int queries;
	cin >> queries;	

	// One based indexing
	vector<int> a(n + 1);
	FenwickTree ft_pos(n);
	FenwickTree ft_neg(n);
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		if(a[i] > 0)
			ft_pos.adjust(i, 1);
		
		if(a[i] < 0)
			ft_neg.adjust(i, 1);
	}
	
	string res = "";
	for(int i = 0; i < queries; i++)
	{
		char type;
		int left, right;
		int ind, newVal;

		cin >> type;

		if(type == 'C')
		{
			cin >> ind >> newVal;

			update(ft_pos, ft_neg, a, ind, newVal);
		}

		if(type == 'P')
		{
			cin >> left >> right;

			int interval_len = right - left + 1;

			int pos = ft_pos.rsq(left, right);
			int neg = ft_neg.rsq(left, right);
			
			if(pos + neg != interval_len)
				res += '0';
			else if(neg % 2 == 0)
				res += '+';
			else if(neg %2 != 0)
				res += '-';

		}
	}

	return res;
}

int main()
{
	int n;
	while(cin >> n)
		cout << solve(n) << endl;

	return 0;
}
