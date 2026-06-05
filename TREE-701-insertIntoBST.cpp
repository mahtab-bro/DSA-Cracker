// LeetCode 701: Insert into a Binary Search Tree
// Problem Description
// You are given the root node of a binary search tree (BST) and a val to insert into the tree. Return the root node of the BST after the insertion. 
//It is guaranteed that the new value does not exist in the original BST.  
// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

class Solution {
public:
    // Main function to insert a value into the BST and return the updated root
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: if we reach an empty spot, create and return the new node, because the given address doesn't exist here or never created
        if (root == nullptr) {
            return new TreeNode(val); // This new node will be attached to its parent
        }

        // If the value to insert is smaller than the current node's value
        if (val < root->val) {
            // Recursively travel down the left subtree and assign the result to root->left
            root->left = insertIntoBST(root->left, val);
        } 
        // If the value to insert is larger than the current node's value
        else {
            // Recursively travel down the right subtree and assign the result to root->right
            root->right = insertIntoBST(root->right, val);
        }

        // Return the unchanged root pointer back up the call stack
        return root;
    }
};
