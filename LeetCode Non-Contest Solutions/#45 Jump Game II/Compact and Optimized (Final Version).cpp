class Solution
{
public:
	int jump(vector<int>& nums);
};

int Solution :: jump(vector<int>& a)
{
	int n = a.size();
	
	// This also functions as the visited array
	vector<int> level(n,-1);
	
	// Queue contains the indexes
	queue<int> bfs;
	bfs.push(0);
	level[0] = 0;
	int min_un_reach = 1;
	
	/* min_un_reach denotes the minimum element which is not yet reached */
	
	// Perform the bfs
	while(!bfs.empty())
	{
		int ind = bfs.front();
		bfs.pop();
		
		
		while(min_un_reach < n and min_un_reach <= ind + a[ind])
		{
			bfs.push(min_un_reach);
			level[min_un_reach] = level[ind] + 1;
			min_un_reach++;
		}
	}
	
	return level.back();
}
