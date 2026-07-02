LeetCode 3248: Snake in MatrixProblem StatementThere is an $n \times n$ matrix where each cell $(i, j)$ is labeled with a value calculated by 
$i \times n + j$. A snake starts at position $0$ (which is grid cell $(0, 0)$). Given the grid size $n$ and a list of commands ("UP", "DOWN", "LEFT", "RIGHT"),
calculate the final cell value after all moves.ExampleInput: n = 3, commands = ["DOWN", "RIGHT", "UP"]
Output: 4

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        // Snake starts at (0, 0)
        int row = 0;
        int col = 0;
        
        // Process each command to update coordinates
        for (const string& cmd : commands) {
            if (cmd == "UP") row--;
            else if (cmd == "DOWN") row++;
            else if (cmd == "LEFT") col--;
            else if (cmd == "RIGHT") col++;
        }
        
        // Convert final 2D coordinates back to the matrix label formula
        return (row * n) + col;
    }
};
