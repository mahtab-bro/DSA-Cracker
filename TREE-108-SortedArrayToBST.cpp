// LeetCode 108. Convert Sorted Array to Binary Search Tree
// Question:
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

class Solution {
private:
    // Helper function that builds the balanced tree using a range [left, right]
    TreeNode* helper(vector<int>& nums, int left, int right) {
        // Base case: if left index crosses right, the range is empty (sub-tree is null)
        if (left > right) {
            return nullptr;
        }

        // Always choose the middle element as the root of the new TREE; to keep the left and right subtrees perfectly balanced
        int mid = left + (right - left) / 2;

        // Create a root node containing our middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left subtree using elements to the left of the middle
        root->left = helper(nums, left, mid - 1);

        // Recursively build the right subtree using elements to the right of the middle
        root->right = helper(nums, mid + 1, right);

        // Return the fully constructed subtree root
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Run the helper function spanning the entire size of the input array
        return helper(nums, 0, nums.size() - 1);
    }
};
