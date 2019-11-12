#include <bits/stdc++.h>
using namespace std;

int getSum(vector<vector<int>> &partial, int x, int y, int p, int q)
{
	int top_left  = x and y ? partial[x-1][y-1]: 0;
	int top_right = x ? partial[x-1][q] : 0;
	int bot_left  = y ? partial[p][y-1] : 0;
	int bot_right = partial[p][q];
	
	int res = bot_right - top_right;
	res -= (bot_left - top_left);
	
	return res;
}

void partialSum(vector<vector<int>> &mat)
{
	int R = mat.size();
	int C = mat[0].size();
	
	vector<vector<int>> partial(R, vector<int>(C, 0));
	
	for(int i = 0; i < R; i++)
	{
		int runningSum = 0;
		for(int j = 0; j < C; j++)
		{
			runningSum += mat[i][j];
			partial[i][j] = runningSum + (i ? partial[i-1][j] : 0);
		}
	}
	
	mat = partial;
}

int main()
{
	
	int n;
	cin >> n;
	
	int R, C;
	R = C = n;
	
	vector<vector<int>> mat(R, vector<int> (C, 0));
	
	for(auto &row_vec : mat)
		for(auto &ele : row_vec)
			cin >> ele;
	
	partialSum(mat);
	
	int global_max = INT_MIN;
	
	for(int x = 0; x < R; x++)
		for(int y = 0; y < C; y++)
			for(int p = x; p < R; p++)
				for(int q = y; q < C; q++)
					global_max = max(global_max, getSum(mat, x, y, p, q));
					
	
	cout << global_max << endl;
}
