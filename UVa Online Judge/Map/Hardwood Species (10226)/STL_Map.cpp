#include <bits/stdc++.h>
using namespace std;

void calculateFraction(vector<string> &collection)
{
	map<string, int> freq;
	for(auto str : collection)
		freq[str]++;

	int totalCount = 0;
	for(auto ele : freq)
		totalCount += ele.second;
	
	cout << std :: setprecision(4) << std :: fixed;
	for(auto ele : freq)
	{
		// Promotion
		double fraction = (100.0 * ele.second) /totalCount;

		cout << ele.first << " ";
		cout << fraction << endl;
	}
}

int main()
{
	int testCases;
	cin >> testCases;

	cin.ignore(2);
	for(int i = 0; i < testCases; i++)
	{
		string str;
		vector<string> collection;
        
		while(getline(cin, str) and str.length () != 0)
			collection.push_back(str);

		if(i != 0)
    			cout << endl;
            
		calculateFraction(collection);
	}

	return 0;
}
