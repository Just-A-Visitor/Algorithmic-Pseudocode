class Solution
{
public:
	int oddCells(int n, int m, vector<vector<int>>& indices);
};

int Solution :: oddCells(int row, int col, vector<vector<int>>& indices)
{
	vector<vector<int>> mat(row, vector<int>(col,0));
	for(auto vec : indices)
	{
		int r = vec.front();
		int c = vec.back();
		
		int i = r;
		for(int j = 0; j < col; j++)
			mat[i][j] += 1;
		
		int j = c;
		for(int i = 0; i < row; i++)
			mat[i][j] += 1;
	}
	
	int count = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(mat[i][j] & 1)
				count++;
	
	return count;
}
