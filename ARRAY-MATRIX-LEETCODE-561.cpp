class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        /* 
         * ALGORITHM: Array Partition
         * 
         * GOAL: Maximize sum of minimums after pairing array elements
         * 
         * APPROACH:
         * 1. Sort array in ascending order
         * 2. Pair adjacent elements (nums[0], nums[1]), (nums[2], nums[3])...
         * 3. Sum the first element of each pair (even indices)
         * 
         * TIME COMPLEXITY: O(n log n) - dominated by sorting
         * SPACE COMPLEXITY: O(1) - sorting is in-place, constant extra space
         * 
         * EXAMPLE: nums = [1,4,3,2]
         * Sort: [1,2,3,4]
         * Pairs: (1,2) → min=1, (3,4) → min=3
         * Sum = 1 + 3 = 4
         */
        
        // Step 1: Sort the array to bring similar values together
        // This ensures adjacent elements have minimal differences
        sort(nums.begin(), nums.end());
        
        // Step 2: Initialize accumulator to store final result
        int maxSum = 0;
        
        // Step 3: Iterate through sorted array with step of 2
        // This visits only even indices: 0, 2, 4, ...
        for (int i = 0; i < nums.size(); i += 2) {
            // Step 4: Add the element at current even index
            // This is always the smaller element of the pair (nums[i], nums[i+1])
            maxSum += nums[i];
        }
        
        // Step 5: Return the maximum possible sum of pair minimums
        return maxSum;
    }
};
