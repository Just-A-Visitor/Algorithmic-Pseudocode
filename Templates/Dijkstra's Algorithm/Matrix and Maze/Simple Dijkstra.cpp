#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Go through the ReadMe. The code is a bit obfuscated */
/* Be very careful with the Comparators */

int ROW,COL;

/* Return true if the cell is valid */
bool legal(int i, int j)
{
    return (i>=0 and i<ROW and j>=0 and j<COL);
}

/* Structure to hold the nodes */
class Node
{
    public:
    int dist, x_cord, y_cord;
    
    /* Comparator for the class */
    bool operator <(const Node &biggerNode) const 
	{
	    if(dist==biggerNode.dist)
	    {
            if (x_cord != biggerNode.x_cord) 
                return x_cord < biggerNode.x_cord;
            else
                return y_cord < biggerNode.y_cord;
	    }
		return dist < biggerNode.dist;
	}
	
	// Constructor
	Node(int dist, int x_cord, int y_cord)
	{
	    this->dist = dist;
	    this->x_cord = x_cord;
	    this->y_cord = y_cord;
	}
	
};


/* Template for Dijkstra's Algorithm on a matrix */
int Dijkstra(vector<vector<int>> &weight)
{
    // Extract the total rows and columns
    ROW = weight.size();
    COL = weight[0].size();
    
    // Create the set to store the distances
    set<Node> minHeap; 
    
    // Define infinity
    const int inf = 1e9;
     
    // Define the directions
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Temporary variables
    int x,y, row,col, new_delta;
    
    // Intialize single source with infinity
    int delta[ROW][COL];
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            delta[i][j] = inf;
    
    // Source to source cost is not 0!
    delta[0][0] = weight[0][0];
    minHeap.insert(Node(0,0,0));
    
    // Keep performing edge relaxation
    while(!minHeap.empty())
    {
        // Extract the node with minimum delta
        Node currentNode = *(minHeap.begin());
        minHeap.erase(minHeap.begin());
        
        // Record the cells
        row = currentNode.x_cord;
        col = currentNode.y_cord;
        
        // Travel the cardinal directions
        for(int i=0; i<4; i++)
        {
            x = row + dx[i];
            y = col + dy[i];
            
            if(!legal(x,y)) continue;
            
            // Perform edge relaxation
            if(delta[x][y] >= delta[row][col] + weight[x][y])
            {
                // Test passed. Delta needs to be decreased
                new_delta = delta[row][col] + weight[x][y];
                
                // If not infinity, it has to be in the set. Find and delete
                if(delta[x][y]!=inf)
                    minHeap.erase(minHeap.find( Node(delta[x][y], x,y)) );
                
                // Insert the updated delta    
                minHeap.insert(Node(new_delta,x,y));
                
                // Remember to update delta in the matrix too.
                delta[x][y] = new_delta;
            }
        }
    }
    
    // Return the cost to reach the bottom right cell
    return delta[ROW-1][COL-1];
}

int main() {
	int row, col;
	cin >> row >> col;
	
	vector<vector<int>> weight(row);
	for(auto &row_vec : weight)
	    row_vec.resize(col);
	
	for(int i=0; i<row; i++)
	    for(int j=0; j<col; j++)
	        cin >> weight[i][j];
	
	cout << Dijkstra(weight);
	
	return 0;
}

/* Test case */
/*
3 3
32 88 86
4 79 5
59 62 37
*/
