#include <string>

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 1. Create the double string
        string double_s = s + s;
        
        // 2. Snip off the first character and the last character.
        // string.substr(start_index, length)
        // We start at index 1 and take (total length - 2) characters.
        string trimmed = double_s.substr(1, double_s.length() - 2);
        
        // 3. Search for the original string inside the trimmed version.
        // string::npos means "not found". If it does NOT equal npos, it means we found it!
        if (trimmed.find(s) != string::npos) {
            return true;
        }
        
        return false;
    }
};
