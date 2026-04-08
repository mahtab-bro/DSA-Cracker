#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Define starting left boundary
        int low = 0; 
        // Define starting right boundary
        int high = nums.size() - 1; 

        // Run until pointers cross over
        while (low <= high) {
            // Find the middle index
            int mid = low + (high - low) / 2;

            // Check if middle is the target
            if (nums[mid] == target) {
                return mid;
            }
            // If mid is too small, move right
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            // If mid is too big, move left
            else {
                high = mid - 1;
            }
        }
        // Low points to the insertion index
        return low;
    }
};
