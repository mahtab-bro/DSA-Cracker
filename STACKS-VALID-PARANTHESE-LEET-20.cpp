class Solution {
public:
    bool isValid(string s) {
        // Our waiting room stack
        stack<char> st;
        
        // Walk through the line of guests
        for (char c : s) {
            // Opening guest arrives -> goes into the waiting room
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // Closing guest arrives -> needs validation
            else {
                // If nobody is in the waiting room, it's an unmatched closer!
                if (st.empty()) return false;
                
                // Peek at the person closest to the exit door
                char topElement = st.top();
                
                // Check for a perfect match
                if ((c == ')' && topElement == '(') ||
                    (c == ']' && topElement == '[') ||
                    (c == '}' && topElement == '{')) {
                    st.pop(); // Match found! They leave together.
                } else {
                    return false; // Mismatch discovered!
                }
            }
        }
        // If the room is empty, everyone was paired successfully
        return st.empty();
    }
};
