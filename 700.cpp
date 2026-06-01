// Search in a Binary Search Tree
// Difficulty: Easy | Topics: Tree, Binary Search Tree, Binary Tree

// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// Example 1:
// Input: root = [4,2,7,1,3], val = 2

// Output: [2,1,3]

// Explanation: The node containing value 2 is found. The program returns the entire sub-tree originating from that node, which contains 2 as its root, 1 as its left child, and 3 as its right child.

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base Cases: root is null (not found) or root matches val (found)
        if (root == nullptr || root->val == val) {
            return root;
        }
        
        // Recursive Cases
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};
