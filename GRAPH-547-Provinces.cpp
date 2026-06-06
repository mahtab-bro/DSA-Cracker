// LeetCode #547: Number of ProvincesThe Problem StatementThere are n cities. Some of them are connected, while some are not. 
//   If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.  
//   A province is a group of directly or indirectly connected cities and no other cities outside of the group.  
//   You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the $i^{th}$ city and the $j^{th}$ city are directly connected, 
// and isConnected[i][j] = 0 otherwise.  Return the total number of provinces.

#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to explore and mark all cities in the same province
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true; // Mark the current city as visited
        
        // Check and read all the connected/ neighboring cities 
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            // If a connection exists and the neighbor hasn't been visited yet
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited); // Recursively visit the neighbor
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Total number of cities
        vector<bool> visited(n, false); // initially all of the cities are not on the list, false means no name
        int provinceCount = 0; // Initialize the total province counter
        
        // Loop through each city to ensure every province is discovered
        for (int i = 0; i < n; i++) {
            // If the city hasn't been part of a discovered province yet
            if (!visited[i]) {
                provinceCount++; // Found a new province, increment the count
                dfs(i, isConnected, visited); // Run DFS to mark all cities in this province
            }
        }
        
        return provinceCount; // Return the total number of connected provinces found
    }
};
