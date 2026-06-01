// LeetCode 938. Range Sum of BST
// Question:
// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

// Example 1:

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Base case: if the current node is null, its contribution to the sum is 0
        if (root == nullptr) {
            return 0;
        }
        
        // If the current node's value is smaller than the low boundary,
        // all values in its left subtree will also be too small. Search only the right subtree.
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        
        // If the current node's value is larger than the high boundary,
        // all values in its right subtree will also be too large. Search only the left subtree.
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        
        // If the current value is within the range, include it in the sum
        // and recursively find valid nodes in both the left and right subtrees
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
