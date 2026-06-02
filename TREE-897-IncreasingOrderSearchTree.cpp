// LeetCode 897. Increasing Order Search Tree
// Question:
// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

class Solution {
private:
    // 1. We create a placeholder node. Its value (0) doesn't matter.
    // This gives us a fixed starting point so we don't lose the head of our new tree.
    TreeNode* dummy = new TreeNode(0);
    
    // 2. 'current' starts at dummy. It will always point to the last node 
    // in our newly flattened chain.
    TreeNode* current = dummy;

public:
    TreeNode* increasingBST(TreeNode* root) {
        // 3. Base Case: If we hit a dead end (null node), turn back.
        if (root == nullptr) {
            // Reached the end of a branch, return back up the call stack
            return nullptr;
        }

        // 4. LEFT: Go as deep left as possible. 
        // This finds the smallest available value in the current subtree.
        increasingBST(root->left);

        // 5. ROOT (Processing the current node):
        // We isolate this node by breaking its left connection.
        root->left = nullptr;
        
        // We attach this node to the right side of our growing chain.
        current->right = root;
        
        // Move our pointer forward so this node becomes the new end of the chain.
        current = root;

        // 6. RIGHT: Now that the left side and this node are handled,
        // move on to process the larger values in the right subtree.
        increasingBST(root->right);

        // 7. RETURN: 'dummy' is still pointing to the start.
        // dummy->right is the actual first node (the smallest node) of our new tree.
        return dummy->right;
    }
};
