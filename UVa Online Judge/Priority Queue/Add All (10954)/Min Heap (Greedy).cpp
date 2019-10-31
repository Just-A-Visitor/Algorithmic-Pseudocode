#include <bits/stdc++.h>
using namespace std;

void solve(int size)
{
	vector<int> vec(size);
	for(auto &ele : vec)
		cin >> ele;
	
	priority_queue<int, vector<int>, greater<int>> minHeap;
    	for(auto ele : vec)
		minHeap.push(ele);

	int totalCost = 0;
	int currentCost;
	while(minHeap.size() > 1)
	{
		int min_ele = minHeap.top();
		minHeap.pop();

		int second_min_ele = minHeap.top();
		minHeap.pop();

		currentCost = min_ele + second_min_ele;
		totalCost += currentCost;

		minHeap.push(currentCost);
	}
	
	cout << totalCost << endl;
}

int main()
{
	int size;
	cin >> size;

	while(size != 0)
	{
		solve(size);
		cin >> size;
	}

	return 0;
}
