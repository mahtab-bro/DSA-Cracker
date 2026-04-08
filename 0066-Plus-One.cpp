#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                // If we hit this, the function ends here
                return digits;
            }
            // Otherwise, 9 becomes 0 and we carry to the left
            digits[i] = 0;
        }

        // If we are here, it means we ran out of digits to carry to
        // Example: [9,9] became [0,0]. We need to make it [1,0,0]
        
        // Insert '1' at the very start of the vector
        digits.insert(digits.begin(), 1);
        
        // Return the final result
        return digits;
    }
};
