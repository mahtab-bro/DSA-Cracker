LeetCode 1732: Find the Highest AltitudeProblem StatementThere is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes.
  The biker starts his trip on point 0 with an altitude equal to 0.  You are given an integer array gain of length n where gain[i]
is the net gain in altitude between points i and i + 1 for all ($0 \leq i < n$).  Return the highest altitude of a point.
ExampleInput: gain = [-5, 1, 5, 0, -7]
Output: 1
// ------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // maxAlt stores the highest point reached, initialized to 0 (starting point)
        int maxAlt = 0;
        // currentAlt tracks the elevation at the current step
        int currentAlt = 0;
        
        // Loop through each gain value to calculate altitude at each step
        for (int g : gain) {
            // Update current altitude by adding the net change
            currentAlt += g;
            
            // Compare current altitude with the maximum found so far
            if (currentAlt > maxAlt) {
                maxAlt = currentAlt;
            }
        }
        
        return maxAlt;
    }
};
