class Solution
{
	vector<vector<int>> mat;
public:
	int get_rectangle_sum(int x, int y, int p, int q);
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k);
};

int Solution :: get_rectangle_sum(int x, int y, int p, int q)
{
	int top_left = x and y ? mat[x-1][y-1] : 0;
	int top_right = x ? mat[x-1][q] : 0;
	int bot_left = y ? mat[p][y-1] : 0;
	int bot_right = mat[p][q];
	
	
	int sum = bot_right - top_right;
	sum -= (bot_left - top_left);
	
	return sum;
}

vector<vector<int>> Solution :: matrixBlockSum(vector<vector<int>>& input_matrix, int k)
{
	// Serious Bug (Due to Name Collision)
	this->mat = input_matrix;
	
	int row = mat.size();
	int col = mat[0].size();
	
	// Convert to partial sum
	for(int i = 0; i < row; i++)
	{
		int running_sum = 0;
		for(int j = 0; j < col; j++)
		{
			running_sum += mat[i][j];
			mat[i][j] = running_sum + (i ? mat[i-1][j] : 0);
		}
	}
	
	vector<vector<int>> res(row, vector<int>(col, 0));
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			int x = i-k, y = j-k;
			int p = i+k, q = j+k;
			
			res[i][j] = get_rectangle_sum(max(0,x), max(0,y), min(row - 1, p), min(col - 1, q));
		}
	}
	
	return res;
}
