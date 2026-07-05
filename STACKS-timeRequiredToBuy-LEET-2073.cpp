#include <vector>
#include <algorithm> // For min()

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total_time = 0;
        int target_tickets = tickets[k];
        
        for (int i = 0; i < tickets.size(); i++) {
            // People standing before or at index k
            if (i <= k) {
                total_time += min(tickets[i], target_tickets);
            } 
            // People standing after index k
            else {
                total_time += min(tickets[i], target_tickets - 1);
            }
        }
        
        return total_time;
    }
};
