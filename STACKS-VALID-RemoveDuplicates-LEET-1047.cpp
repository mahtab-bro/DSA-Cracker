class Solution {
public:
    string removeDuplicates(string s) {
        // This string doubles up as our stack container
        string result = "";
        
        // Track each particle coming down the belt
        for (char c : s) {
            // If chamber isn't empty and current matches the top particle
            if (!result.empty() && c == result.back()) {
                result.pop_back(); // Annihilation! Pop it off.
            } 
            // If they don't match, it settles safely
            else {
                result.push_back(c); // Push onto our stack
            }
        }
        
        return result;
    }
};
