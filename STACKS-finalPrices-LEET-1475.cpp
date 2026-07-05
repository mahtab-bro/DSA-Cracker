class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // This stack will store the INDICES of the items, 
        // not their actual values. This helps us modify the vector directly.
        stack<int> st;
        
        for (int i = 0; i < prices.size(); i++) {
            // While there are items waiting in the stack, and the current item's price 
            // is less than or equal to the item at the top of the stack...
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                // We found a discount for the item at st.top()!
                int idxToDiscount = st.top();
                prices[idxToDiscount] -= prices[i]; // Apply the discount
                st.pop(); // Remove it from the waiting list
            }
            
            // Push the current item's index onto the stack to wait for its discount
            st.push(i);
        }
        
        // Return the modified prices vector
        return prices;
    }
};
