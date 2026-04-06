#include <iostream>  // For basic input/output
#include <vector>    // Essential: To use the vector container
#include <string>    // Essential: To handle string objects

// Using specific declarations to keep code clean and professional
using std::vector;
using std::string;

/**
 * UNDERSTANDING THE CLASS:
 * The 'Solution' class contains our logic. In a real-world tech job (or at HITSZ),
 * keeping logic inside classes is part of "Encapsulation" (Object-Oriented Programming).
 */
class Solution {
public:
    /**
     * THE METHOD: longestCommonPrefix
     * Strategy: Horizontal Scanning
     * Time Complexity: O(S) where S is the sum of all characters in all strings.
     * Space Complexity: O(1) as we only store the prefix string.
     */
    string longestCommonPrefix(vector<string>& strs) {
        
        // 1. EDGE CASE: Safety First
        // If the list is empty, there is no common prefix.
        if (strs.empty()) return "";

        // 2. INITIAL GUESS: 
        // We assume the first word is the entire prefix. 
        // We will "chip away" at this guess as we compare it to other words.
        string prefix = strs[0];

        // 3. THE WORD-BY-WORD SCAN:
        // We start from the second word (index 1) and go to the end.
        for (int i = 1; i < (int)strs.size(); i++) {
            
            /**
             * 4. THE "CHIPPING" ENGINE (The while-loop):
             * strs[i].find(prefix) looks for the 'prefix' inside the current word.
             * If it returns 0, the word STARTS with the prefix.
             * If it's NOT 0, we must shorten the prefix and try again.
             */
            while (strs[i].find(prefix) != 0) {
                
                // Remove the last character from our prefix guess
                prefix = prefix.substr(0, prefix.length() - 1);

                // 5. EARLY EXIT:
                // If the prefix shrinks to nothing, there's no commonality at all.
                if (prefix.empty()) return "";
            }
        }

        // 6. FINAL RESULT: 
        // After checking every word, whatever is left of 'prefix' is the answer.
        return prefix;
    }
};
