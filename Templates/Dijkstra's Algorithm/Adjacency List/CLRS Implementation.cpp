#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Go through the ReadMe. The code is a bit obfuscated */
/* Be very careful with the Comparators */

/* Structure to hold the nodes */
class Node
{
    public:
    int weight, vertex;
    
    /* Comparator for the class */
    bool operator <(const Node &biggerNode) const 
    {
        if(weight==biggerNode.weight)
            return (vertex < biggerNode.vertex);
        else
            return (weight < biggerNode.weight);
    }
	
	// Constructor
	Node(int weight, int vertex)
	{
	    this->weight = weight;
            this->vertex = vertex;
	}
	
};


/* Template for Dijkstra's Algorithm on a Adjacency List */
/* Returns the vector of delta values for each node */
vector<int> Dijkstra(vector<vector<Node>> &adj, int source)
{
    // Extract the number of vertices
    int n = adj.size();
    
    // Create the set to store the distances
    set<Node> minHeap; 
    
    // Define infinity
    const int inf = 1e9;
    
    // Temporary variables
    int u,v,weight;
    
    // Intialize single source with infinity
    vector<int> delta;
    delta.assign(n,inf);
    
    // Source to source cost is 0!
    delta[source] = 0;
    minHeap.insert(Node(0,source));
    
    // Keep performing edge relaxation
    while(!minHeap.empty())
    {
        // Extract the node with minimum delta
        Node currentNode = *(minHeap.begin());
        minHeap.erase(minHeap.begin());
        
        u = currentNode.vertex;
        
        // Travel the adjacency list
        for(auto edge : adj[u])
        {
            v = edge.vertex;
            weight = edge.weight;
            
            // Perform edge relaxation
            if(delta[v] >= delta[u] + weight)
            {
                // Test passed. Delta needs to be decreased
                int new_delta = delta[u] + weight;
                
                // If not infinity, it has to be in the set. Find and delete
                if(delta[v]!=inf)
                    minHeap.erase(minHeap.find( Node(delta[v], v)) );
                
                // Insert the updated delta    
                minHeap.insert(Node(new_delta,v));
                
                // Remember to update delta in the array too.
                delta[v] = new_delta;
            }
        }
    }
    
    // Return the delta matrix
    return delta;
}

int main() 
{
    int vertices, edges, source;
    cin >> vertices >> edges >> source;
    
    vector<vector<Node>> adj(vertices);
    
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back(Node(w,v));
    }
    
    vector<int> delta = Dijkstra(adj,source);
    
    for(int i=0; i<vertices; i++)
    {
        cout << "The distance from " << source << " to "<< i;
        cout << " is " << delta[i] << endl;
    }
	return 0;
}

/* Test case 
The indexing is assumed to be zero based
5 9 4
4 1 7
4 0 2
1 0 2
0 1 3
1 2 1
0 2 8
0 3 5
2 3 5
3 2 4
*/


/* Test Case CLRS 
5 10 0
0 1 10
0 4 5
1 4 2
4 1 3
3 0 7
4 3 2
4 2 9
1 2 1
2 3 4
3 2 6
*/
