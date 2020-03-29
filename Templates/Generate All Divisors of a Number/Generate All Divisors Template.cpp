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

/* Function to generate all divisors of a number */
/* You can easily run it for 1e9 (once) as the max number of divisors is 1344 */
/* Remember to sort it on your end if you need it */
void generateDivisors(vector<pair<int, int>> &factor, long res, int index, vector<long> &divisors)
{
	if(index == factor.size())
	{
		divisors.push_back(res);
		return;
	}

	int multiplicity = factor[index].second;
	
	// Take care of the indexing and ordering of the 2 statements
	for(int to_take = 0; to_take <= multiplicity; to_take++)
	{
		generateDivisors(factor, res, index + 1, divisors);
		res *= factor[index].first;
	}
}


void testGenerateDivisors()
{
	for(int num = 2; num <= 50; num++)
	{
		vector<pair<int, int>> factors;
		factors = primeFactorization(num);
		
		vector<long> divisors;
		generateDivisors(factors, 1, 0, divisors);
		sort(divisors.begin(), divisors.end());

		cout << "The divisors of " << num << " are ";

		for(auto ele : divisors)
			cout << ele << " ";

		cout << endl;
	}
}

int main()
{
	testGenerateDivisors();
	return 0;
}
