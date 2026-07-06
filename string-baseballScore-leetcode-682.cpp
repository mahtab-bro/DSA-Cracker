#include <vector>
#include <string>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        // We use a vector like a stack because it allows us to easily index 
        // the last two elements, and loop through everything at the end.
        vector<int> scores;
        
        for (string op : operations) {
            if (op == "+") {
                // Access the last element and the second-to-last element
                int topScore = scores[scores.size() - 1];
                int secondTop = scores[scores.size() - 2];
                scores.push_back(topScore + secondTop);
            } 
            else if (op == "D") {
                // scores.back() gives us the element at the very top
                scores.push_back(2 * scores.back());
            } 
            else if (op == "C") {
                // Remove the top element
                scores.pop_back();
            } 
            else {
                // stoi converts a string representation of a number into an actual int
                scores.push_back(stoi(op));
            }
        }
        
        // Final calculation phase: Sum up all valid scores
        int totalScore = 0;
        for (int score : scores) {
            totalScore += score;
        }
        
        return totalScore;
    }
};
