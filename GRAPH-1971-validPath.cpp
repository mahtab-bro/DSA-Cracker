// LeetCode 1971: Find if Path Exists in GraphProblem StatementThere is a bi-directional graph with n vertices, 
// where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, 
//   where each $edges[i] = [u_i, v_i]$ denotes a bi-directional edge between vertex $u_i$ and vertex $v_i$. 
//   Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.  You want to determine 
// if there is a valid path that exists from vertex source to vertex destination.  

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to check if a valid path exists from source to destination
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // If source and destination are identical, we are already there
        if (source == destination) return true;
        
        // Create an Adjacency List (an array of lists) to map city connections
        vector<vector<int>> adjList(n);
        
        // Loop through every road in the edges list to build our map
        for (const vector<int>& edge : edges) {
            int u = edge[0]; // Extract City A
            int v = edge[1]; // Extract City B
            adjList[u].push_back(v); // Add City B to City A's neighbor list
            adjList[v].push_back(u); // Add City A to City B's neighbor list
        }
        
        // Track visited cities using a boolean array to prevent endless loops
        vector<bool> visited(n, false);
        
        // Initialize a Queue to manage our "To-Do List" for exploration (BFS)
        queue<int> q;
        
        // Place the starting city into the queue and mark it as visited
        q.push(source);
        visited[source] = true;
        
        // Continue exploring as long as there are cities left in our queue
        while (!q.empty()) {
            // Step into the next available city from the queue front
            int curr = q.front();
            q.pop(); // Remove it from the queue since we are currently inspecting it
            
            // Loop through all neighbors connected to our current city
            for (int neighbor : adjList[curr]) {
                
                // If any neighbor matches our target destination, a path exists!
                if (neighbor == destination) return true;
                
                // If we haven't visited this neighbor yet, process it
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark it as visited immediately
                    q.push(neighbor);         // Add it to the queue to explore its neighbors later
                }
            }
        }
        
        // If the queue runs dry and we never hit the destination, no path exists
        return false;
    }
};
