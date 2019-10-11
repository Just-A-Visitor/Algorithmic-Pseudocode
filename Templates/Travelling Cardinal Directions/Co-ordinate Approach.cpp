#include <bits/stdc++.h>
using namespace std;

/* Technique to travel the four cardinal directions */
void travelCardinalDirections(vector<vector<int>> &mat, int row, int col)
{
    // Defining directions with [row][col] as origin
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for(int i=0; i<4; i++)
    {
        int x = row + dx[i];
        int y = col + dx[i];
        
        // Access mat[x][y]
    }
}
int main()
{
	return 0;
}
