#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 'w' (Writer/Gatekeeper) tracks the position to insert the next valid element
        int w = 0;
        
        // 'r' (Reader/Scout) iterates through every element in the array
        for (int r = 0; r < nums.size(); r++) {
            
            // Logic: If the reader finds a "Good" number (not equal to val)
            if (nums[r] != val) {
                
                // Copy the good number from the current reader position 
                // to the current writer position.
                nums[w] = nums[r];
                
                // Since we just saved a good number, move the writer 
                // forward to the next available slot.
                w++;
            }
            
            // If nums[r] == val, we skip the block above. 
            // The writer 'w' stays on the bad value, waiting to overwrite it later.
        }
        
        // After the loop, 'w' represents the count of elements we kept.
        // This is exactly the value 'k' that LeetCode is looking for.
        return w;
    }
};
