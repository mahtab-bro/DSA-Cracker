class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n); // Pre-allocate space for result
        
        int left = 0;           // Pointer at the start
        int right = n - 1;      // Pointer at the end
        
        // Fill the result array from back to front (largest to smallest)
        for (int i = n - 1; i >= 0; --i) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        
        return result;
    }
};
