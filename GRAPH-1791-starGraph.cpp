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



#include <vector>
using namespace std;

class Solution {
private:
    // This helper function acts like the teacher tapping friends on the shoulder
    void tapAllFriends(int currentStudent, vector<vector<int>>& isConnected, vector<bool>& visited) {
        // Mark the current student as visited
        visited[currentStudent] = true;
        
        // Look at every student in the room to find currentStudent's friends
        for (int nextStudent = 0; nextStudent < isConnected.size(); nextStudent++) {
            
            // IF they are friends AND we haven't visited nextStudent yet
            if (isConnected[currentStudent][nextStudent] == 1 && !visited[nextStudent]) {
                // Immediately go tap them and find their friends too (Recursion)
                tapAllFriends(nextStudent, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalStudents = isConnected.size();
        
        // Our clipboard to keep track of who we've already counted
        vector<bool> visited(totalStudents, false);
        
        int provinceCount = 0;
        
        // Walk down the classroom row by row checking every student
        for (int i = 0; i < totalStudents; i++) {
            
            // If we find a student we haven't encountered in a circle yet...
            if (!visited[i]) {
                provinceCount++; // It's a brand new circle!
                
                // Go find and mark everyone connected to this student
                tapAllFriends(i, isConnected, visited);
            }
        }
        
        return provinceCount;
    }
};
