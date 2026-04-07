#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, there are no unique elements
        if (nums.empty()) return 0;

        // i is the index of the last unique element found so far
        int i = 0;

        // j explores the array starting from the second element (index 1)
        for (int j = 1; j < nums.size(); j++) {
            // Since the array is sorted, if nums[j] is different from nums[i],
            // it must be a new unique element.
            if (nums[j] != nums[i]) {
                // Move i to the next available spot
                i++;
                // Update that spot with the new unique value
                nums[i] = nums[j];
            }
        }

        // The number of unique elements is i + 1 (since i is an index)
        return i + 1;
    }
};
