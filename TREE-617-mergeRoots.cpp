// LeetCode 617: Merge Two Binary Trees
// Problem Description
// You are given two binary trees root1 and root2.
// Example 1:

// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]

// Output: [3,4,5,5,4,null,7]

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If first tree node is null, return the second tree node (handles both null, or just root1 null)
        if (!root1) return root2; 
        // If second tree node is null, return the first tree node
        if (!root2) return root1; 
        
        // If both nodes exist, sum their values and store it in root1 (reusing root1 saves memory)
        root1->val += root2->val; 
        
        // Recursively merge the left children of both nodes
        root1->left = mergeTrees(root1->left, root2->left); 
        // Recursively merge the right children of both nodes
        root1->right = mergeTrees(root1->right, root2->right); 
        
        // Return the locally modified root1 as the root of the merged subtree
        return root1; 
    }
};
