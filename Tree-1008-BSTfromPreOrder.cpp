// LeetCode 1008: Construct Binary Search Tree from Preorder Traversal
// Problem Description
// Given an array of integers preorder, which represents the preorder traversal of a binary search tree (BST), construct the tree and return its root.

class Solution {
private:
    // Helper function that builds the BST using a tracking index and an upper value restriction
    TreeNode* buildBST(const vector<int>& preorder, int& index, int upperBound) {
        
        // Base Case 1: If index matches array size, we have processed all elements
        // Base Case 2: If the current element is larger than the allowed upper bound, it belongs to a different subtree
        if (index >= preorder.size() || preorder[index] > upperBound) {
            return nullptr; // Return null pointer to stop building this branch
        }

        // Allocate a new root node in memory using the current value in the preorder traversal
        TreeNode* root = new TreeNode(preorder[index]);
        
        // Move the index reference forward so the next recursive frame reads the next number
        index++;

        // Construct the left subtree; elements here must be strictly less than the current node's value
        root->left = buildBST(preorder, index, root->val);

        // Construct the right subtree; elements here can be up to the inherited maximum bound of this frame
        root->right = buildBST(preorder, index, upperBound);

        // Return the fully constructed subtree root back up to the parent caller
        return root;
    }

public:
    // Main function called by the testing framework
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        // Initialize an index tracker at 0; passed by reference to maintain state across recursion frames
        int index = 0; 
        
        // Kick off the recursion with the entire array, starting with a maximum upper limit of infinity
        return buildBST(preorder, index, INT_MAX);
    }
};
