
class Solution {
public:
    // Function to check if a given binary
    // tree is a valid binary search tree (BST)
    bool isValid(TreeNode* root) {
        // Calls the helper function isValidBST
        // with initial min and max values
        return isValidBST(root, LONG_MIN, LONG_MAX); 
    }

    // Helper function to recursively validate the BST property
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) {
            // Base case: an empty
            // tree is a valid BST
            return true; 
        }
        
        // Checks if the current node
        // violates the BST property
        if (root->val >= maxVal || root->val <= minVal) {
            return false; 
        }

        // Recursively checks left and right
        // subtrees with updated constraints
        // that every value on its left subtree
        // should be smaller than the current node
        // and every value on its right subtree
        // should be greater than the current node
        return isValidBST(root->left, minVal, root->val)
                && isValidBST(root->right, root->val, maxVal);
    }
};
