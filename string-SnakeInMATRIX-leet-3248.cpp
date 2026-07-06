#include <vector>
#include <string>

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        // Track coordinate positions on our virtual grid
        int row = 0;
        int col = 0;
        
        // Process each command movement sequentially
        for (string cmd : commands) {
            if (cmd == "UP") {
                row--;
            } else if (cmd == "DOWN") {
                row++;
            } else if (cmd == "LEFT") {
                col--;
            } else if (cmd == "RIGHT") {
                col++;
            }
        }
        
        // Calculate the flat mathematical index of the grid cell
        return (row * n) + col;
    }
};
