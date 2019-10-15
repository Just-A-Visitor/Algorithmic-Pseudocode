#include <bits/stdc++.h>
using namespace std;

/* Perform dfs on the original Graph
 * Store vertices in a stack according to finish time
 * The last finished element is at the top of the stack
 * Reverse the Graph
 * Perform dfs on this Grpah according to elements on the stack
 * Each external dfs call covers one strongly connected component
 * The second dfs call ensures that everything is initialized
 */

/* The Graph class */
class Graph
{
    public:
    int vertices;
    vector<vector<int>> adj;
    stack<int> dfs_stack;
    vector<bool> visited;
    
    // Constructor
    Graph(int vertices)
    {
        this->vertices = vertices;
        adj.resize(vertices);
        visited.resize(vertices);
    }
    
    void addEdge(int u, int v);
    void dfs_visit(int source, bool printElement);
    void find_scc();
};

/* Function to add an edge (u,v) */
void Graph :: addEdge(int u, int v)
{
    adj[u].push_back(v);
}

/* Performs dfs. Also prints the vertex in order if demanded */
void Graph :: dfs_visit(int source, bool printElement = false)
{
    // Visit this element
    visited[source] = true;
    
    // Print it , if demanded
    if(printElement)
        cout << source << " " ;
    
    // Visit all the neighbours
    for(auto ele : adj[source])
        if(!visited[ele])
            dfs_visit(ele, printElement);
    
    // This has finished, so push  it onto the stack
    dfs_stack.push(source);
}

/* Prints the strongly connected component of the graph */
void Graph :: find_scc()
{
    // Perform the first dfs, filling the stack
    for(int u=0; u<vertices; u++)
        if(!visited[u])
            dfs_visit(u);
    
    // Create the reversed Graph
    Graph reversedGraph(vertices);        
    
    // Populate the reversed Graph
    for(int u=0; u<vertices; u++)
        for(auto v : adj[u])
            reversedGraph.addEdge(v,u);
    
    // Counter to store the scc_number
    int scc_number = 1;
    
    // Peform the second dfs on reversedGraph according to finish time
    while(!dfs_stack.empty())
    {
        // Extract the element with the largest finish time
        int u = dfs_stack.top();
        dfs_stack.pop();
        
        // Visit all the elements in the same SCC
        if(!reversedGraph.visited[u])
        {
            cout << endl << "Printing the contents of scc_number " << scc_number++ << endl;
            reversedGraph.dfs_visit(u, true);
            cout << endl << "Printing Done!" << endl;
        }
    }
}

/* Test Drive for SCC determination */
void Test_SCC()
{
    int vertices, edges;
    cin >> vertices >> edges;
    
    Graph myGraph(vertices);
    
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin >> u >> v;
        
        myGraph.addEdge(u,v);
    }
    
    myGraph.find_scc();
}

int main()
{
	Test_SCC();
	return 0;
}

/* CLRS Test Case (0 Based Indexing) */
/* 
8 12
2 0
0 1
1 2
1 3
1 5
3 4
4 3 
5 6 
6 5
6 7
4 7
7 7 
*/