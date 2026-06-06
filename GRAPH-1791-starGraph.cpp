// LeetCode 1791: Find Center of Star Graph
// Problem Statement
// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect 
// the center node with every other node.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the center node of a star graph
    int findCenter(vector<vector<int>>& edges) {
        
        // Grab the two nodes from the very first edge
        int u1 = edges[0][0]; //taking index from the matrix, checking each element one by one
        int v1 = edges[0][1];
        
        // Grab the two nodes from the second edge
        int u2 = edges[1][0];
        int v2 = edges[1][1];
        
        // If u1 appears in the second edge, it's the center
        if (u1 == u2 || u1 == v2) {
            return u1;
        }
        
        // Otherwise, v1 must be the center
        return v1;
    }
};

