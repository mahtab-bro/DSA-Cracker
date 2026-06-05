// LeetCode 110: Balanced Binary Tree (Easy)Given a binary tree, determine if it is height-balanced.  
//   A height-balanced binary tree is defined as a binary tree in which the left
//and right subtrees of every node differ in height by no more than 1.
#include <algorithm> 
using namespace std;

class Solution {
public:
    // This helper returns the actual height IF balanced, or -1 IF it breaks the rules.
    int checkHeight(TreeNode* node) {
        // Base Case: If we hit a null node, it has a height of 0.
        if (node == nullptr) {
            return 0;
        }
        
        // 1. Ask the left child for its height
        int leftHeight = checkHeight(node->left);
        // If left child returned -1, it means someone below is broken. Pass the error up!
        if (leftHeight == -1) return -1;
        
        // 2. Ask the right child for its height
        int rightHeight = checkHeight(node->right);
        // If right child returned -1, someone below is broken. Pass the error up!
        if (rightHeight == -1) return -1;
        
        // 3. Now check the current node. Are its children's heights differing by more than 1?
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Found an imbalance! Return our error flag (-1).
        }
        
        // 4. If everything is perfectly balanced, calculate our own height and return it.
        // Our height is 1 (ourselves) + whichever child tree is taller.
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        // If our function completes without returning -1, the tree is balanced!
        return checkHeight(root) != -1;
    }
};
