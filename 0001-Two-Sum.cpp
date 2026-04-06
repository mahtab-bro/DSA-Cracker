#include <iostream>      // For input/output (optional for testing)
#include <vector>        // Essential: For using the vector container
#include <unordered_map> // Essential: For using the hash map (Memory Bank)

// We use 'using' declarations for professional clarity and convenience
using std::vector;
using std::unordered_map;

/**
 * UNDERSTANDING THE CLASS:
 * This 'Solution' class acts as a blueprint for our problem solver.
 * It encapsulates the 'twoSum' method to keep the code organized.
 */
class Solution {
public:
    /**
     * THE METHOD: twoSum
     * Why 'vector<int>&'? The '&' (reference) means we look at the original 
     * list in RAM. We don't waste time or space copying it.
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // 1. DATA STRUCTURE: The 'Memory Bank'
        // Key: The number value we saw (e.g., 2)
        // Value: The chair number/index (e.g., 0)
        unordered_map<int, int> num_map;
        
        // 2. OPTIMIZATION: Get the size once
        // This prevents the computer from re-calculating the size every loop cycle.
        int n = nums.size();

        // 3. THE LOGIC: One-Pass Scan
        // We walk through the list once. O(n) time complexity.
        for (int i = 0; i < n; i++) {
            
            // MATH: Calculate the "Missing Puzzle Piece"
            // If Target is 9 and current is 2, we need a 7.
            int current_number = nums[i];
            int complement = target - current_val;

            // SEARCH: Check if the 'Memory Bank' already has that 7
            // .count() checks the Hash Table in O(1) constant time.
            if (num_map.count(complement)) {
                
                // SUCCESS: Found the pair!
                // num_map[complement] = the index of the first number we saw earlier.
                // i = the index of the current number we just found.
                return {num_map[complement], i};
            }

            // STORAGE: If the match wasn't found yet, 'Register' current number.
            // We tell the map: "If anyone needs a '2' later, tell them I'm at index 'i'."
            num_map[current_number] = i;
        }

        // 4. EDGE CASE: Return empty if no solution is found
        // Per LeetCode rules, there is always one solution.
        return {};
    }
};
