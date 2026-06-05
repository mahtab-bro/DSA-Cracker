// LeetCode 897: Increasing Order Search Tree
// Problem Description
// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
//and every node has no left child and only one right child.

class Solution {
private:
    TreeNode* dummy = new TreeNode(0); // Create a dummy node to act as the head of the new tree
    TreeNode* curr = dummy;            // A pointer to track the current tail of the new tree

public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);                 // Start the in-order traversal to rearrange nodes
        return dummy->right;           // The real root of the reshaped tree is the right child of dummy
    }

    void inorder(TreeNode* node) {
        if (!node) return;             // Base case: if the node is null, return back up the call stack
        
        inorder(node->left);           // Traverse the left subtree first (smallest values)
        
        node->left = nullptr;          // Cut the left child link to satisfy the problem condition
        curr->right = node;            // Connect the current tail's right pointer to this node
        curr = node;                   // Move the tail pointer forward to the newly added node
        
        inorder(node->right);          // Finally, traverse the right subtree (larger values)
    }
};
