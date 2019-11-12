#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &mat)
{
	int R = mat.size();
	int C = mat[0].size();
	
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			cout << mat[i][j] << " \n"[j == C - 1];
}

void scanMatrix(vector<vector<int>> &mat)
{
	for(auto &row_vec : mat)
		for(auto &ele : row_vec)
			cin >> ele;
}
int main()
{
	int n;
	cin >> n;
	
	vector<vector<int>> mat(n, vector<int>(n,0));
	
	scanMatrix(mat);
	printMatrix(mat);
	
	return 0;
}
