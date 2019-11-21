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

void solve(int n)
{
	FenwickTree ft(n);
	
	// One based indexing
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ft.adjust(i, a[i] - 0);
	}

	cin.ignore();
	string str;

	while(getline(cin, str) and str != "END")
	{
		char type;
		int left, right;
		int ind, new_val;
		
		stringstream stream(str);
		
		stream >> type;
		if(type == 'M')
		{
			// Don't mix 'stream' and 'cin'
			stream >> left >> right;
			cout << ft.rsq(left, right) << endl;
		}

		if(type == 'S')
		{
			// Don't mix 'stream' and 'cin'
			stream >> ind >> new_val;
			ft.adjust(ind, new_val - a[ind]);
			
			// Remember to update the value in the array
			a[ind] = new_val;
		}
	}
}

int main()
{
	int n;
	int caseNumber = 1;

	while(cin >> n and n != 0)
	{
		if(caseNumber != 1)
			cout << endl;
			
		cout << "Case " << caseNumber++ << ":" << endl;
		solve(n);
	}

	return 0;
}
