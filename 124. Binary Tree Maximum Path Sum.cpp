class Solution {
    int global_max = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        // Fast I/O to hit that 0ms/99% mark
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        calculateGain(root);
        return global_max;
    }

private:
    int calculateGain(TreeNode* node) {
        if (!node) return 0;

        // Recursive call: ignore paths that result in a negative sum
        int leftGain = max(calculateGain(node->left), 0);
        int rightGain = max(calculateGain(node->right), 0);

        // This is the price of a path where the current node is the "highest" point
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum if the current path is better
        if (currentPathSum > global_max) {
            global_max = currentPathSum;
        }

        // Return the best single branch to the parent
        return node->val + max(leftGain, rightGain);
    }
};