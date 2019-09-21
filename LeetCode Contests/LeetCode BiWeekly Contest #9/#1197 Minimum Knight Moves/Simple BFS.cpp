class Solution
{
public:
    int minKnightMoves(int tx, int ty);
};

int Solution :: minKnightMoves(int tx, int ty)
{
	tx = abs(tx), ty = abs(ty);
    int n = 400;
    vector<vector<int>> mat(n, vector<int>(n,-1));
    
    int dx[] = {-2, -2, -1, -1,  1, 1,  2, 2};
    int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};
    
    int row = 0, col = 0, x, y;

    queue<pair<int, int>> q;
    
    mat[row][col] = 0;
    q.push(make_pair(row,col));
    
    while(!q.empty())
    {
        if(mat[tx][ty] != -1)
            return mat[tx][ty];
        
        row = q.front().first;
        col = q.front().second;
        q.pop();
        
        for(int i = 0; i < 8; i++)
        {
            int x = row + dx[i];
            int y = col + dy[i];
        
            if(x >= 0 and y >= 0 and x < n and y < n and mat[x][y] == -1)
            {
                mat[x][y] = 1 + mat[row][col];
                q.push(make_pair(x,y));
            }
        }
    }
    
    
    return mat[tx][ty];
}
