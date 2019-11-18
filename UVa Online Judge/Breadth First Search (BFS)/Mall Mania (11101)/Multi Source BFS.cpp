#include <bits/stdc++.h>
using namespace std;

// Take care of the limits. Cost me a WA
const int R = 2000 + 1;
const int C = 2000 + 1;

// Global constants for better readability
const int source = 1;
const int dest = 2;
const int unvisited = -1;

/* Performs a multi-level bfs (Multiple Source, Multiple Destination) */
int solve(vector<vector<int>> &mat)
{
	vector< vector<int> > level(R, vector<int>(C, unvisited));
	
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	queue< pair<int, int> > bfs;
	
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mat[i][j] == source)
			{
				level[i][j] = 0;
				bfs.push({i,j});
			}
		}
	}
	
	// Wow! I discovered a new keyword. Definitely using this from now on
	while(not bfs.empty())
	{
		auto current = bfs.front();
		bfs.pop();

		int x, y;
		x = current.first, y = current.second;

		if(mat[x][y] == dest)
			return level[x][y];

		for(int i = 0; i < 4; i++)
		{
			int p = x + dx[i];
			int q = y + dy[i];

			if(p < 0 or p >= R or q < 0 or q >= C)
				continue;

			if(level[p][q] == unvisited)
			{
				level[p][q] = level[x][y] + 1;
				bfs.push({p,q});
			}
		}
	}
}

int main()
{
	int sourceSize, destSize;
	int x, y;
	
	while(cin >> sourceSize and sourceSize != 0)
	{
		vector< vector<int> > mat(R, vector<int>(C, 0));
		
		for(int i = 0; i < sourceSize; i++)
		{
			cin >> x >> y;
			mat[x][y] = source;
		}
		
		cin >> destSize;
		for(int i = 0; i < destSize; i++)
		{
			cin >> x >> y;
			mat[x][y] = dest;
		}

		cout << solve(mat) << endl;
	}
	
	return 0;
}
