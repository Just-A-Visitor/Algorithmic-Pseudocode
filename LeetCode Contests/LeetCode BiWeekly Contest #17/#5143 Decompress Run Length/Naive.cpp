class Solution
{
public:
	vector<int> decompressRLElist(vector<int>& nums);
};

vector<int> Solution ::  decompressRLElist(vector<int>& a)
{
	vector<int> res;
	
	int n = a.size();
	int ind = 1;
	while(ind < n)
	{
		int element = a[ind];
		int copies = a[ind - 1];
		
		while(copies--)
			res.push_back(element);
		
		ind += 2;
	}
	
	return res;
}
