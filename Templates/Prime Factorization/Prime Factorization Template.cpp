#include <bits/stdc++.h>
using namespace std;

/* Function to obtain all prime factors of a number, along with its multiplicity */
/* Time Complexity is O( sqrt(n) ) */
vector<pair<int, int>> primeFactorization(long num)
{
	vector<pair<int, int>> res;

	for(int factor = 2; factor*factor <= num; factor++)
	{
		int multiplicity = 0;

		while(num % factor == 0)
		{
			num /= factor;
			multiplicity++;
		}

		if(multiplicity != 0)
			res.push_back(make_pair(factor, multiplicity));
	}

	if(num != 1)
		res.push_back(make_pair(num , 1));

	return res;
}

void testPrimeFactorization()
{
	for(int num = 2; num <= 50; num++)
	{
		vector<pair<int, int>> factors;
		factors = primeFactorization(num);

		cout << "The prime factors of " << num << " are ";

		for(auto ele : factors)
			cout << ele.first << " ";

		cout << endl;
	}
}

int main()
{
	testPrimeFactorization();
	return 0;
}
