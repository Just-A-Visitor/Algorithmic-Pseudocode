class Solution
{
public:
	int subarrayBitwiseORs(vector<int>& a);
};

/* collection[i] is the set of all distinct bitwise 'or'
 * of all the subarrays ending at i.
 * Clearly, collection[i] = a[i] union (a[i] | collection[i-1])
 */

/* We can also reduce the space complexity using 'curr' & 'prev' set */

/* Don't mix up '|' and 'or'*/
int Solution :: subarrayBitwiseORs(vector<int>& a)
{
	// Too strict time limit. Use Hashing 
	vector<unordered_set<int>> collection(a.size());
	int n = a.size();
	
	// Initially, each collection contains one element
	for(int i = 0; i < n; i++)
		collection[i].insert(a[i]);
	
	// Simple DP. Size of each collection[i] < 32
	for(int i = 1; i < n; i++)
		for(auto ele : collection[i-1])
			collection[i].insert(a[i] | ele);
	
	unordered_set<int> final_collection;
	
	// Use reference whenever possible
	for(auto& set : collection)
		for(auto ele : set)
			final_collection.insert(ele);
	
	return final_collection.size();
}
