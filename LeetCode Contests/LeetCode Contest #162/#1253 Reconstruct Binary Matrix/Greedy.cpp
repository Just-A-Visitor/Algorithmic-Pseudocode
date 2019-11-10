class Solution
{
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum);
};

vector<vector<int>> Solution :: reconstructMatrix(int upper, int lower, vector<int>& colsum)
{
	int n = colsum.size();
	vector<vector<int>> mat(2, vector<int> (n, 0));
	
	for(int i = 0; i < n; i++)
		if(colsum[i] == 2)
			mat[0][i] = 1, mat[1][i] = 1;
	
	auto& first_row = mat[0];
	int current_upper_sum = accumulate(first_row.begin(), first_row.end(), 0);
	
	int diff = upper - current_upper_sum;
	
	if(diff < 0)
		return vector<vector<int>>();
	
	for(int i = 0; i < n; i++)
	{
		if(colsum[i] == 1)
		{
			if(diff > 0)
				mat[0][i] = 1, diff--;
			else 
				mat[1][i] = 1;
		}
	}
	
	auto& second_row = mat[1];
	int current_lower_sum = accumulate(second_row.begin(), second_row.end(), 0);
	
	if(current_lower_sum != lower)
		return vector<vector<int>> ();
	
	return mat;
		
}
