
#include <bits/stdc++.h>
using namespace std;

// Function to visit the nodes of a graph
void DFS(unordered_map<int, vector<int>> &adj, int node, vector<bool> &visited)
{
    // If current node is already visited
    if (visited[node])
        return;
    visited[node] = true;
    for (auto x : adj[node])
    {
        if (visited[x] == false)
            DFS(adj, x, visited);
    }
}
int make_Connect(int n, int c[][2], int m)
{
    // Stores whether a node is visited or not
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> adj;
    int edges = 0;

    // Building adjacency list from the given edges
    for (int i = 0; i < m; ++i)
    {
        // Adding edges to nodes
        adj[c[i][0]].push_back(c[i][1]);
        adj[c[i][1]].push_back(c[i][0]);
        edges += 1;
    }
    int components = 0;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false) // If node is n visited
        {
            components += 1;
            DFS(adj, i, visited);
        }
    }
    if (edges < n - 1)
        return -1;
    // Count of redundant edges
    int r_edge = edges - ((n - 1) - (components - 1));
    // Checking if components can ben rearranged using redundant edges
    if (r_edge >= (components - 1))
        return components - 1;

    return -1;
}

void nodes_connected(int n, int c[][2], int m)
{
    int result = make_Connect(n, c, m);
    cout << "The number of operations required are :" << endl;
    cout << result; // printing the no of operations to required to make connection
}
int main()
{
    int n = 4; // no of nodes
               //  array of connections
    int c[][2] = {{0, 1}, {0, 2}, {1, 2}};
    int m = sizeof(c) / sizeof(c[0]);

    // function to check all nodes are able to connect or not
    nodes_connected(n, c, m);
    return 0;
}
