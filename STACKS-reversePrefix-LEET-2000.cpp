class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Find the position of the first occurrence of character 'ch'
        size_t idx = word.find(ch);
        
        // string::npos means "not found". 
        // So if idx != string::npos, it means we successfully found the character!
        if (idx != string::npos) {
            // Reverse the portion from the beginning (index 0) up to index idx
            // We use idx + 1 because the second argument of reverse is exclusive
            reverse(word.begin(), word.begin() + idx + 1);
        }
        
        // Return the modified (or untouched) word
        return word;
    }
};
