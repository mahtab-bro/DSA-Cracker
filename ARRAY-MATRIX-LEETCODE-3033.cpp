class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        vector<vector<int>> answer = matrix; // Create a copy as required

        // Iterate through each column
        for (int j = 0; j < n; ++j) {
            int max_val = -1;
            
            // First pass: Find the maximum element in the current column
            for (int i = 0; i < m; ++i) {
                max_val = max(max_val, answer[i][j]);
            }
            
            // Second pass: Replace -1 with the calculated max_val
            for (int i = 0; i < m; ++i) {
                if (answer[i][j] == -1) {
                    answer[i][j] = max_val;
                }
            }
        }
        
        return answer;
    }
};
