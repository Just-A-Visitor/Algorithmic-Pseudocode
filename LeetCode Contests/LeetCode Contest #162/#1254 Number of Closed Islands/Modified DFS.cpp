class Solution
{
public:
	int row, col;
	bool terminal = false;
	void dfs(vector<vector<int>> &grid, int row, int col);
	int closedIsland(vector<vector<int>>& grid);
};

void Solution :: dfs(vector<vector<int>> &grid, int i, int j)
{
	if(i < 0 or j < 0 or i >= row or j >= col)
		return;
	
	if(grid[i][j] == 1 or grid[i][j] == 2)
		return;
	
	if(i == 0 or j == 0 or i == row - 1 or j == col -1)
		terminal = true;
	
	// Visit this cell
	grid[i][j] = 2;
	
	dfs(grid, i, j + 1); dfs(grid, i, j - 1);
	dfs(grid, i + 1, j); dfs(grid, i - 1, j);
}

int Solution :: closedIsland(vector<vector<int>>& grid)
{
	row = grid.size();
	col = grid[0].size();
	
	int count = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(grid[i][j] == 0)
			{
				terminal = false;
				dfs(grid, i, j);
				
				if(!terminal)
					count++;
			}
		}
	}
	
	return count;
}
