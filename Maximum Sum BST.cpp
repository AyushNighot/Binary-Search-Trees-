class Solution {
public:
    // Public function to find the maximum sum of a valid BST
    int maxSumBST(TreeNode* root) {
        // Disable synchronization with C standard streams for faster I/O
        ios_base::sync_with_stdio(false);
        // Untie cin from cout for even faster I/O
        cin.tie(NULL);

        int maxSum = 0;
        // Start the exploration of the BST
        exploreBST(root, maxSum);

        return maxSum;
    }

private:
    // Private recursive function to explore the BST and calculate information
    pair<int, pair<int, int>> exploreBST(TreeNode* node, int& maxSum) {
        // Base case: If the node is a leaf (no left and right children)
        if (!node->left && !node->right) {
            // Update maxSum if the leaf value is greater
            maxSum = max(maxSum, node->val);
            // Return information about the leaf node
            return {node->val, {node->val, node->val}};
        }

        // Information about the left and right subtrees
        pair<int, pair<int, int>> leftInfo = {0, {INT_MAX, INT_MIN}}, rightInfo = {0, {INT_MAX, INT_MIN}};

        // Explore the left subtree if it exists
        if (node->left) {
            leftInfo = exploreBST(node->left, maxSum);
        }
        // Explore the right subtree if it exists
        if (node->right) {
            rightInfo = exploreBST(node->right, maxSum);
        }

        // Check if the current subtree forms a valid BST
        if (node->val > leftInfo.second.second && node->val < rightInfo.second.first) {
            // If valid, calculate the sum of values in the current subtree
            int currentSum = leftInfo.first + rightInfo.first + node->val;
            // Update maxSum if the current sum is greater
            maxSum = max(maxSum, currentSum);
            // Return information about the current subtree
            return {
                currentSum,
                {min(leftInfo.second.first, node->val), max(rightInfo.second.second, node->val)}
            };
        } else {
            // If the current subtree is not a valid BST, return invalid information
            return {0, {INT_MIN, INT_MAX}};
        }
    }
};
